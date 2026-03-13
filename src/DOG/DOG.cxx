#include "DOGCLP.h"
#include "itkImage.h"
#include "itkImageFileReader.h"
#include "itkImageFileWriter.h"
#include "itkRecursiveGaussianImageFilter.h"
#include "itkSubtractImageFilter.h"
#include "itkRescaleIntensityImageFilter.h"
#include "itkCastImageFilter.h"

int main(int argc, char * argv[])
{
  PARSE_ARGS;

  constexpr unsigned int Dimension = 3;

  using InputPixelType = short;
  using FloatPixelType = float;
  using OutputPixelType = unsigned char;

  using InputImageType = itk::Image<InputPixelType, Dimension>;
  using FloatImageType = itk::Image<FloatPixelType, Dimension>;
  using OutputImageType = itk::Image<OutputPixelType, Dimension>;

  using ReaderType = itk::ImageFileReader<InputImageType>;
  using CastType = itk::CastImageFilter<InputImageType, FloatImageType>;
  using GaussianType = itk::RecursiveGaussianImageFilter<FloatImageType, FloatImageType>;
  using SubtractType = itk::SubtractImageFilter<FloatImageType>;
  using RescaleType = itk::RescaleIntensityImageFilter<FloatImageType, OutputImageType>;
  using WriterType = itk::ImageFileWriter<OutputImageType>;

  ReaderType::Pointer reader = ReaderType::New();
  reader->SetFileName(inputVolume);

  CastType::Pointer cast = CastType::New();
  cast->SetInput(reader->GetOutput());

  GaussianType::Pointer g1x = GaussianType::New();
  GaussianType::Pointer g1y = GaussianType::New();
  GaussianType::Pointer g1z = GaussianType::New();

  g1x->SetDirection(0);
  g1y->SetDirection(1);
  g1z->SetDirection(2);

  g1x->SetSigma(sigma1);
  g1y->SetSigma(sigma1);
  g1z->SetSigma(sigma1);

  g1x->SetInput(cast->GetOutput());
  g1y->SetInput(g1x->GetOutput());
  g1z->SetInput(g1y->GetOutput());

  GaussianType::Pointer g2x = GaussianType::New();
  GaussianType::Pointer g2y = GaussianType::New();
  GaussianType::Pointer g2z = GaussianType::New();

  g2x->SetDirection(0);
  g2y->SetDirection(1);
  g2z->SetDirection(2);

  g2x->SetSigma(sigma2);
  g2y->SetSigma(sigma2);
  g2z->SetSigma(sigma2);

  g2x->SetInput(cast->GetOutput());
  g2y->SetInput(g2x->GetOutput());
  g2z->SetInput(g2y->GetOutput());

  SubtractType::Pointer subtract = SubtractType::New();
  subtract->SetInput1(g1z->GetOutput());
  subtract->SetInput2(g2z->GetOutput());

  RescaleType::Pointer rescale = RescaleType::New();
  rescale->SetInput(subtract->GetOutput());
  rescale->SetOutputMinimum(0);
  rescale->SetOutputMaximum(255);

  WriterType::Pointer writer = WriterType::New();
  writer->SetFileName(outputVolume);
  writer->SetInput(rescale->GetOutput());

  writer->Update();

  return EXIT_SUCCESS;
}
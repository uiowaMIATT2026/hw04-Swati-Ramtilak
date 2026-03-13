#include "GaussianLPFCLP.h"
#include "itkImage.h"
#include "itkImageFileReader.h"
#include "itkImageFileWriter.h"
#include "itkRecursiveGaussianImageFilter.h"

int main(int argc, char * argv[])
{
  PARSE_ARGS;

  constexpr unsigned int Dimension = 3;
  using PixelType = short;
  using ImageType = itk::Image<PixelType, Dimension>;

  using ReaderType = itk::ImageFileReader<ImageType>;
  using WriterType = itk::ImageFileWriter<ImageType>;
  using FilterType = itk::RecursiveGaussianImageFilter<ImageType, ImageType>;

  ReaderType::Pointer reader = ReaderType::New();
  reader->SetFileName(inputVolume);

  FilterType::Pointer gaussianX = FilterType::New();
  FilterType::Pointer gaussianY = FilterType::New();
  FilterType::Pointer gaussianZ = FilterType::New();

  gaussianX->SetDirection(0);
  gaussianY->SetDirection(1);
  gaussianZ->SetDirection(2);

  gaussianX->SetSigma(sigma);
  gaussianY->SetSigma(sigma);
  gaussianZ->SetSigma(sigma);

  gaussianX->SetInput(reader->GetOutput());
  gaussianY->SetInput(gaussianX->GetOutput());
  gaussianZ->SetInput(gaussianY->GetOutput());

  WriterType::Pointer writer = WriterType::New();
  writer->SetFileName(outputVolume);
  writer->SetInput(gaussianZ->GetOutput());

  writer->Update();

  return EXIT_SUCCESS;
}


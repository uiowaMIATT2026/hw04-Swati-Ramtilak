#include "CurvatureADCLP.h"
#include "itkImage.h"
#include "itkImageFileReader.h"
#include "itkImageFileWriter.h"
#include "itkCurvatureAnisotropicDiffusionImageFilter.h"

int main(int argc, char * argv[])
{
  PARSE_ARGS;

  constexpr unsigned int Dimension = 3;

  using PixelType = float;
  using ImageType = itk::Image<PixelType, Dimension>;

  using ReaderType = itk::ImageFileReader<ImageType>;
  using WriterType = itk::ImageFileWriter<ImageType>;
  using FilterType = itk::CurvatureAnisotropicDiffusionImageFilter<ImageType, ImageType>;

  ReaderType::Pointer reader = ReaderType::New();
  reader->SetFileName(inputVolume);

  FilterType::Pointer filter = FilterType::New();
  filter->SetInput(reader->GetOutput());
  filter->SetConductanceParameter(conductance);
  filter->SetTimeStep(timeStep);
  filter->SetNumberOfIterations(iterations);

  WriterType::Pointer writer = WriterType::New();
  writer->SetFileName(outputVolume);
  writer->SetInput(filter->GetOutput());

  writer->Update();

  return EXIT_SUCCESS;
}
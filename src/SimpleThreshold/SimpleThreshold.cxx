#include "SimpleThresholdCLP.h"
#include "itkImage.h"
#include "itkImageFileReader.h"
#include "itkImageFileWriter.h"
#include "itkBinaryThresholdImageFilter.h"

int main(int argc, char * argv[])
{
  PARSE_ARGS;

  constexpr unsigned int Dimension = 3;
  using PixelType = short;
  using ImageType = itk::Image<PixelType, Dimension>;

  using ReaderType = itk::ImageFileReader<ImageType>;
  using WriterType = itk::ImageFileWriter<ImageType>;
  using ThresholdType = itk::BinaryThresholdImageFilter<ImageType, ImageType>;

  ReaderType::Pointer reader = ReaderType::New();
  reader->SetFileName(inputVolume);

  ThresholdType::Pointer threshold = ThresholdType::New();
  threshold->SetInput(reader->GetOutput());

  threshold->SetLowerThreshold(lowThreshold);
  threshold->SetUpperThreshold(highThreshold);

  threshold->SetOutsideValue(outsideValue);
  threshold->SetInsideValue(insideValue);

  WriterType::Pointer writer = WriterType::New();
  writer->SetFileName(outputVolume);
  writer->SetInput(threshold->GetOutput());

  writer->Update();


  return EXIT_SUCCESS;
}
#include "ImageIO.h"
namespace Axum::IO {
OIIO::ImageSpec loadImageFromFile(std::string_view filePath,
                                  std::vector<unsigned char> &pixles) {

  auto input = OIIO::ImageInput::open(filePath.data());
  if (!input)
    throw std::runtime_error(
        fmt::format("Can't load image from {}", filePath.data()));
  auto specs = input->spec();
  int width = specs.width;
  int height = specs.height;
  int channels = specs.nchannels;
  pixles = std::vector<unsigned char>(width * height * channels);
  input->read_image(OIIO::TypeDesc::UINT8, &pixles[0]);
  input->close();
  return specs;
}

OIIO::ImageSpec loadImageFromMemory(std::string_view fileName, void *data,
                                    size_t size,
                                    std::vector<unsigned char> &pixles) {
  assert(data != nullptr);
  assert(size != 0);
  OIIO::Filesystem::IOMemReader mem_reader(data, size);
  auto input = OIIO::ImageInput::open(fileName.data(), nullptr, &mem_reader);
  if (!input)
    throw std::runtime_error(
        fmt::format("Can't load embedded image {}", fileName.data()));
  auto specs = input->spec();
  int width = specs.width;
  int height = specs.height;
  int channels = specs.nchannels;
  pixles = std::vector<unsigned char>(width * height * channels);
  input->read_image(OIIO::TypeDesc::UINT8, &pixles[0]);
  input->close();
  return specs;
}
} // namespace Axum::IO
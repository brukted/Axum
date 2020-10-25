#include "ImageIO.h"
#include <OpenImageIO/filesystem.h>
#include <OpenImageIO/imagebufalgo.h>
#include <OpenImageIO/imageio.h>
#include <array>
#include <assert.h>
#include <fmt/format.h>

// TODO: Not happy with ther performace of the function
namespace Axum::IO {
std::tuple<int, int> loadImageFromFile(std::string_view filePath,
                                       std::vector<unsigned char> &pixles) {

  auto input = OIIO::ImageInput::open(filePath.data());
  if (!input)
    throw std::runtime_error(
        fmt::format("Can't load image from {}", filePath.data()));
  auto specs = input->spec();
  pixles = std::vector<unsigned char>(specs.width * specs.height * 4);
  if (specs.channelnames == std::vector<std::string>{"R", "G", "B", "A"}) {
    if (!input->read_image(0, 0, 0, -1, OIIO::TypeDesc::UINT8, pixles.data())) {
      throw std::runtime_error(
          fmt::format("Failed loading image from {}", filePath.data()));
    }
    input->close();
    return {specs.full_width, specs.full_height};
  } else {
    auto buffer = OIIO::ImageBuf(filePath.data(), 0, 0);
    int rIdx = buffer.spec().channelindex("R");
    int gIdx = buffer.spec().channelindex("G");
    int bIdx = buffer.spec().channelindex("B");
    int aIdx = buffer.spec().channelindex("A");
    std::array<int, 4> channelOrder = {rIdx, gIdx, bIdx, aIdx};
    if (OIIO::ImageBufAlgo::isMonochrome(buffer, buffer.roi_full())) {
      channelOrder = {rIdx, rIdx, rIdx, aIdx};
    }
    OIIO::ImageBufAlgo::channels(buffer, buffer, 4, channelOrder, {1, 1, 1, 1},
                                 {"R", "G", "B", "A"});
    if (!buffer.get_pixels(buffer.roi_full(), OIIO::TypeDesc::UINT8,
                           pixles.data())) {
      throw std::runtime_error(
          fmt::format("Failed loading image from {}", filePath.data()));
    }
    return {buffer.spec().full_width, buffer.spec().full_height};
  }
}

std::tuple<int, int> loadImageFromMemory(std::string_view fileName, void *data,
                                         size_t size,
                                         std::vector<unsigned char> &pixles) {
  assert(data != nullptr);
  assert(size != 0);
  OIIO::Filesystem::IOMemReader mem_reader(data, size);
  auto input = OIIO::ImageInput::open(fileName.data(), nullptr, &mem_reader);
  if (!input)
    throw std::runtime_error(
        fmt::format("Can't load image from {}", fileName.data()));
  auto specs = input->spec();
  pixles = std::vector<unsigned char>(specs.width * specs.height * 4);
  if (specs.channelnames == std::vector<std::string>{"R", "G", "B", "A"}) {
    if (!input->read_image(0, 0, 0, -1, OIIO::TypeDesc::UINT8, pixles.data())) {
      throw std::runtime_error(
          fmt::format("Failed loading image from {}", fileName.data()));
    }
    input->close();
    return {specs.full_width, specs.full_height};
  } else {
    OIIO::ImageBuf buffer =
        OIIO::ImageBuf(fileName.data(), 0, 0, nullptr, nullptr, &mem_reader);
    int rIdx = buffer.spec().channelindex("R");
    int gIdx = buffer.spec().channelindex("G");
    int bIdx = buffer.spec().channelindex("B");
    int aIdx = buffer.spec().channelindex("A");
    std::array<int, 4> channelOrder = {rIdx, gIdx, bIdx, aIdx};
    if (OIIO::ImageBufAlgo::isMonochrome(buffer, buffer.roi_full())) {
      channelOrder = {rIdx, rIdx, rIdx, aIdx};
    }
    OIIO::ImageBufAlgo::channels(buffer, buffer, 4, channelOrder, {1, 1, 1, 1},
                                 {"R", "G", "B", "A"});
    if (!buffer.get_pixels(buffer.roi_full(), OIIO::TypeDesc::UINT8,
                           pixles.data())) {
      throw std::runtime_error(
          fmt::format("Failed loading image from {}", fileName.data()));
    }
    return {buffer.spec().full_width, buffer.spec().full_height};
  }
}
} // namespace Axum::IO
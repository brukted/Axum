/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#include "ImageTexture.h"

/**
 * ImageTexture implementation
 */

namespace Axum {
namespace ResourceType {
void ImageTexture::AppendToModel(Gtk::TreeIter row, Gtk::TreeStore *store) {
  this->Resource::AppendToModel(row, store);
  return;
}

ImageTexture::ImageTexture(std::string &path, PathType _pathType) : Resource() {
  this->type = Type::ImageTexture;
  this->Path = path;
  isLinked = true;
  this->pathType.SetValue((int)_pathType);
  auto input = OIIO::ImageInput::open(path);
  auto specs = input->spec();
  width = (unsigned int)specs.width;
  height = (unsigned int)specs.height;
  channels = specs.nchannels;
  data = std::vector<unsigned char>(width * height * channels);
  input->read_image(OIIO::TypeDesc::UINT8, &data[0]);
  input->close();
}

ImageTexture::ImageTexture(unsigned int _width, unsigned int _height,
                           unsigned char color[4])
    : Resource() {
  this->type = Type::ImageTexture;
  isLinked = false;
  data = std::vector<unsigned char>(_width * _height * 4);
  for (size_t i = 0; i < data.size(); i += 4) {
    data[i] = color[0];
    data[i + 1] = color[1];
    data[i + 2] = color[2];
    data[i + 3] = color[3];
  }
}

ImageTexture::ImageTexture(std::string &path) {
  this->type = Type::ImageTexture;
  auto input = OIIO::ImageInput::open(path);
  auto specs = input->spec();
  width = (unsigned int)specs.width;
  height = (unsigned int)specs.height;
  channels = specs.nchannels;
  data = std::vector<unsigned char>(width * height * channels);
  input->read_image(OIIO::TypeDesc::UINT8, &data[0]);
  input->close();
  isLinked = false;
}
} // namespace ResourceType
} // namespace Axum
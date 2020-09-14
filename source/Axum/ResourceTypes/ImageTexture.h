/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#ifndef _IMAGETEXTURE_H_
#define _IMAGETEXTURE_H_

#include "NodeGraph/Material.h"
#include "Resource.h"
#include "Utils/Log/Log.h"
//#include <OpenImageIO/imageio.h>
#include <algorithm>
#include <boost/serialization/base_object.hpp>
#include <boost/serialization/vector.hpp>
#include <fmt/format.h>
#include <vector>

namespace Axum {
namespace ResourceType {
// TODO: support more than eight bit if possible
class ImageTexture : public Resource {
  friend class boost::serialization::access;

public:
  ImageTexture() = default;
  /**
   * @brief Construct a new linked Image Texture object
   *
   * @param path path to the image
   * @param _pathType path type of the path
   */
  ImageTexture(std::string &path, PathType _pathType = PathType::Absolute);

  /**
   * @brief Construct a new embedded Image Texture from a file at @a path
   *
   * @param path path to the image
   */
  ImageTexture(std::string &path);

  /**
   * @brief Construct a new Image Texture with solid color
   *
   * @param _width width of the generated texture
   * @param _height height of the generated texture
   * @param color color of the texture
   */
  ImageTexture(int _width, int _height, unsigned char color[4]);

  std::vector<unsigned char> data;

  int channels;

  int width, height;

private:
  template <class Archive>
  void save(Archive &ar, const unsigned int version) const {
    ar &boost::serialization::base_object<Resource>(*this);
    if (!isLinked) {
      ar &data;
    }
    ar &channels &width &height;
  }

  template <class Archive> void load(Archive &ar, const unsigned int version) {
    ar &boost::serialization::base_object<Resource>(*this);
    ar &channels &width &height;
    //* If the texture is embedded load data otherwise load from file
    if (!isLinked) {
      ar &data;
    } else { /*
       data = std::vector<unsigned char>(width * height * channels);
       auto input = OIIO::ImageInput::open(Path);
       if (!input) {
         AX_LOG_CORE_WARN("Can't load linked image texture {0}.",
                          name.GetValue())
         std::fill(data.begin(), data.end(), 125);
       } else {
         input->read_image(OIIO::TypeDesc::UINT8, &data[0]);
         input->close();
       }*/
    }
  }
  BOOST_SERIALIZATION_SPLIT_MEMBER()
};
} // namespace ResourceType
} // namespace Axum
BOOST_CLASS_VERSION(Axum::ResourceType::ImageTexture, 1)
#endif //_IMAGETEXTURE_H_

/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#include "MaterialOutSocket.h"

/**
 * MaterialOutSocket implementation
 */

namespace Axum::NodeGraph::Material {

MaterialOutSocket::MaterialOutSocket(std::string &_name, unsigned int _uid,
                                     Channel _channel)
    : channel(_channel), OutputSocket(_name, _uid) {}

MaterialOutSocket::MaterialOutSocket(const char *_name, unsigned int _uid,
                                     Channel _channel)
    : channel(_channel), OutputSocket(_name, _uid) {}

void MaterialOutSocket::SetupCache() {
  auto &parent = static_cast<MaterialNode &>(*ParentNode);
  gl::glGenTextures(1, &GTextureId);
  gl::glBindTexture(gl::GL_TEXTURE_2D, GTextureId);
  gl::glTexImage2D(gl::GL_TEXTURE_2D, 0,
               GetGlFormat((ImageFormat)parent.imageFormat.GetValue()),
               parent.width.GetValue(), parent.height.GetValue(), 0, gl::GL_RGBA,
               gl::GL_UNSIGNED_BYTE, nullptr);
  gl::glTexParameteri(gl::GL_TEXTURE_2D, gl::GL_TEXTURE_MAG_FILTER, gl::GL_NEAREST);
  gl::glTexParameteri(gl::GL_TEXTURE_2D, gl::GL_TEXTURE_MIN_FILTER, gl::GL_NEAREST);
  gl::glGenerateMipmap(gl::GL_TEXTURE_2D);
}

void MaterialOutSocket::DeleteCache() {
  if (GTextureId != 0) {
    gl::glDeleteTextures(1, &GTextureId);
    GTextureId = 0;
  }
}

gl::GLenum MaterialOutSocket::GetGlFormat(ImageFormat format) {
  switch (channel) {
  case Channel::Normal:
  case Channel::Color:
    switch (format) {
    case ImageFormat::EIGHT_BIT:
      return gl::GL_RGB8;
      break;
    case ImageFormat::SIXTEEN_BIT:
      return gl::GL_RGB16;
      break;
    case ImageFormat::SIXTEEN_BIT_FLOAT:
      return gl::GL_RGB16F;
      break;
    case ImageFormat::THIRTY_TWO_BIT_FLOAT:
      return gl::GL_RGB32F;
      break;
    default:
      AX_LOG_CORE_CRITICAL("Unkown color or normal format type: {0:d}",
                           (int)format)
      break;
    }
    break;
  case Channel::Grayscale:
    switch (format) {
    case ImageFormat::EIGHT_BIT:
      return gl::GL_R8;
      break;
    case ImageFormat::SIXTEEN_BIT:
      return gl::GL_R16;
      break;
    case ImageFormat::SIXTEEN_BIT_FLOAT:
      return gl::GL_R16F;
      break;
    case ImageFormat::THIRTY_TWO_BIT_FLOAT:
      return gl::GL_R32F;
      break;
    default:
      AX_LOG_CORE_CRITICAL("Unkown grayscale format type: {0:d}", (int)format)
      break;
    }
    break;
  default:
    AX_LOG_CORE_CRITICAL("Unkown channel type : {0:d}", (int)channel)
    return gl::GL_RGB8;
  }
  return gl::GL_RGB8;
}

gl::GLuint MaterialOutSocket::GetGPUTexture() { return GTextureId; }

MaterialOutSocket::~MaterialOutSocket() {
  if (GTextureId != 0) {
    gl::glDeleteTextures(1, &GTextureId);
  }
}
} // namespace Axum::NodeGraph::Material
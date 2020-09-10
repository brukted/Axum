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
  glGenTextures(1, &GTextureId);
  glBindTexture(GL_TEXTURE_2D, GTextureId);
  glTexImage2D(GL_TEXTURE_2D, 0,
               GetGlFormat((ImageFormat)parent.imageFormat.GetValue()),
               parent.width.GetValue(), parent.height.GetValue(), 0, GL_RGBA,
               GL_UNSIGNED_BYTE, nullptr);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
  glGenerateMipmap(GL_TEXTURE_2D);
}

void MaterialOutSocket::DeleteCache() {
  if (GTextureId != 0) {
    glDeleteTextures(1, &GTextureId);
    GTextureId = 0;
  }
}

GLint MaterialOutSocket::GetGlFormat(ImageFormat format) {
  switch (channel) {
  case Channel::Normal:
  case Channel::Color:
    switch (format) {
    case ImageFormat::EIGHT_BIT:
      return GL_RGB8;
      break;
    case ImageFormat::SIXTEEN_BIT:
      return GL_RGB16;
      break;
    case ImageFormat::SIXTEEN_BIT_FLOAT:
      return GL_RGB16F;
      break;
    case ImageFormat::THIRTY_TWO_BIT_FLOAT:
      return GL_RGB32F;
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
      return GL_R8;
      break;
    case ImageFormat::SIXTEEN_BIT:
      return GL_R16;
      break;
    case ImageFormat::SIXTEEN_BIT_FLOAT:
      return GL_R16F;
      break;
    case ImageFormat::THIRTY_TWO_BIT_FLOAT:
      return GL_R32F;
      break;
    default:
      AX_LOG_CORE_CRITICAL("Unkown grayscale format type: {0:d}", (int)format)
      break;
    }
    break;
  default:
    AX_LOG_CORE_CRITICAL("Unkown channel type : {0:d}", (int)channel)
    return GL_RGB8;
  }
  return GL_RGB8;
}

GLuint MaterialOutSocket::GetGPUTexture() { return GTextureId; }

MaterialOutSocket::~MaterialOutSocket() {
  if (GTextureId != 0) {
    glDeleteTextures(1, &GTextureId);
  }
}
} // namespace Axum::NodeGraph::Material
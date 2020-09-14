/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#ifndef _MATERIALOUTSOCKET_H
#define _MATERIALOUTSOCKET_H

#include "../InputSockets/MaterialInSocket.h"
#include "../Material.h"
#include "../Nodes/MaterialNode.h"
#include "../OutputSocket.h"
#include "Utils/Log/Log.h"
#include <exception>
#include <glbinding/gl/gl.h>
#include <glbinding/glbinding.h>
#include <glbinding/gl/types.h>

namespace Axum::NodeGraph::Material {

class MaterialOutSocket : public OutputSocket {
private:
  /**
   * @brief Id of the texture on gpu used for live preview execution
   * exists only if setup cache is called it is 0 if not initalized
   *
   */
  gl::GLuint GTextureId = 0;
  Channel channel{Channel::Color};

public:
  MaterialOutSocket(std::string &_name, unsigned int _uid,
                    Channel _channel = Channel::Color);

  MaterialOutSocket(const char *_name, unsigned int _uid,
                    Channel _channel = Channel::Color);

  void SetupCache();

  void DeleteCache();

  gl::GLenum GetGlFormat(ImageFormat format);
  /**
   * @brief Return id of the cached texture on the gpu
   *
   * @return GLuint ID of the texture on the GPU
   */
  gl::GLuint GetGPUTexture();
  ~MaterialOutSocket();
};
} // namespace Axum::NodeGraph::Material
#endif //_MATERIALOUTSOCKET_H

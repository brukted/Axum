/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#ifndef _RENDERENGINE_H
#define _RENDERENGINE_H

#include "../Parameter/ParamCollection.h"
#include "../ResourceTypes/Scene.h"
#include <string>

namespace Axum {
namespace Draw {

class RenderEngine {
public:
  /**
   * @brief name displayed in the ui.
   */
  std::string name;
  std::string idName;
  /**
   * @brief Parameters of the render engine.
   */
  Parameter::ParamCollection mEngineParms;
  Parameter::ParamCollection mCameraParms;

  /**
   * @brief Starts rendering. Consider allocating  resources here if you
   * deallocate memory on stop.
   */
  virtual void start();

  /**
   * @brief Draws the render to the OpenGL view port.
   */
  virtual void display();

  /**
   * @brief Stop rendering also consider freeing memory if the renderer is
   * resource heavy.
   */
  virtual void stop();

  /**
   * @brief Called when the scene is changed so update the renderer's scene too.
   * @param *Scene
   */
  virtual void updateScene(ResourceType::Scene *Scene);

  virtual void updateMaterial();

  /**
   * @brief Called when camera parameters are changed as fov.
   *
   * @param CameraParms
   */
  virtual void updateCamera(Parameter::ParamCollection *CameraParms);

  /**
   * @brief Called when the view port is resized.
   * @param Width The new width of the view port.
   * @param Height The new height of the view port.
   */
  virtual void resize(int Width, int Height);
};

} // namespace Draw
} // namespace Axum
#endif //_RENDERENGINE_H

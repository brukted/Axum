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
   * @brief Name diplayed in the ui.
   */
  std::string Name;
  std::string idName;
  /**
   * @brief Parameters of the render engine.
   */
  Parameter::ParamCollection mEngineParms;
  Parameter::ParamCollection mCameraParms;

  /**
   * @brief Starts rendering. Consider allocating  resources here if you deallocate
   * memory on stop.
   */
  virtual void Start();

  /**
   * @brief Draws the render to the OpenGL viewport.
   */
  virtual void Display();

  /**
   * @brief Stop rendering also consider freeing memory if the renderer is resource
   * heavy.
   */
  virtual void Stop();

  /**
   * @brief Called when the scene is changed so update the renderer's scene too.
   * @param *Scene
   */
  virtual void UpdateScene(ResourceType::Scene *Scene);

  virtual void UpdateMaterial();

  /**
   * @brief Called when camera parameters are changed as fov.
   *
   * @param CameraParms
   */
  virtual void UpdateCamera(Parameter::ParamCollection *CameraParms);

  /**
   * @brief Called when the viewport is resized.
   * @param Width The new width of the viewport.
   * @param Height The new height of the viewport.
   */
  virtual void Resize(int Width, int Height);
};

} // namespace Draw
} // namespace Axum
#endif //_RENDERENGINE_H

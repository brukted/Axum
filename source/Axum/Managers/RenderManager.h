/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#ifndef _RENDERMANAGER_H
#define _RENDERMANAGER_H

#include "../Draw/RenderEngine.h"
#include <vector>

namespace Axum::Manager {

/**
 * @brief RenderManager Manages available render engines.
 *
 */
class RenderManager {
public:
  static RenderManager &getInstance() {
    static RenderManager instance;
    return instance;
  }

private:
  RenderManager(){};

public:
  RenderManager(RenderManager const &) = delete;
  void operator=(RenderManager const &) = delete;

  Draw::RenderEngine *CurrentEngine;
  std::vector<Draw::RenderEngine> mRenderEngines;

  void Startup();

  void Shutdown();

  /**
   * @param engine
   */
  void SetRenderEngine(Draw::RenderEngine *engine);

  /**
   * @param engine
   */
  void RegisterEngine(Draw::RenderEngine engine);
};
} // namespace Axum::Manager

/**
 * @brief Shortcut to the instance of RenderManager
 * 
 */
#define Render_Manager Axum::Manager::RenderManager::getInstance() 
#endif //_RENDERMANAGER_H

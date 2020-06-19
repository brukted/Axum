/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#include "RenderManager.h"

/**
 * RenderManager implementation
 *
 * Manages available render engines and holds a pointer to the current render
 * engine.
 */

namespace Axum::Manager{

/**
 * @param *engine
 */
void RenderManager::SetRenderEngine(Draw::RenderEngine *engine) {}

/**
 * @param engine
 */
void RenderManager::RegisterEngine(Draw::RenderEngine engine) {}

void RenderManager::Startup() {}

void RenderManager::Shutdown() {}

}
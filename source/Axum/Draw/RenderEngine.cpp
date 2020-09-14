/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#include "RenderEngine.h"

/**
 * RenderEngine implementation
 *
 * Base class for all types of renderers(whether ray tracing or real time)
 */

namespace Axum::Draw {

void RenderEngine::start() {}

void RenderEngine::display() {}

void RenderEngine::stop() {}

void RenderEngine::updateScene(ResourceType::Scene *Scene) {}

void RenderEngine::updateMaterial() {}

void RenderEngine::updateCamera(Parameter::ParamCollection *CameraParms) {}

void RenderEngine::resize(int Width, int Height) {}

} // namespace Axum::Draw
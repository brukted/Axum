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

void RenderEngine::Start() {}

void RenderEngine::Display() {}

void RenderEngine::Stop() {}

void RenderEngine::UpdateScene(ResourceType::Scene *Scene) {}

void RenderEngine::UpdateMaterial() {}

void RenderEngine::UpdateCamera(Parameter::ParamCollection *CameraParms) {}

void RenderEngine::Resize(int Width, int Height) {}

} // namespace Axum::Draw
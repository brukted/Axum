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

/**
 * Starts rendering.Consider allocating  resources here if you deallocate memory on stop.
 */
void RenderEngine::Start()
{
}

/**
 * Draws the render to the 3d view.
 */
void RenderEngine::Display()
{
}

/**
 * Stop rendering also consider freeing memory if the renderer is resource heavy.
 */
void RenderEngine::Stop()
{
}

/**
 * Called when the scene is changed so update the renderer's scene too.
 * @param *Scene
 */
void RenderEngine::UpdateScene(Scene *Scene)
{
}

void RenderEngine::UpdateMaterial()
{
}

/**
 * @param *CameraParms
 */
void RenderEngine::UpdateCamera(CameraParams *CameraParms)
{
}

/**
 * The 3d view has been resized so update your framebuffer.
 * @param Width
 * @param Height
 */
void RenderEngine::Resize(int Width, int Height)
{
}
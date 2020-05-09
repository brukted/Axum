/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#ifndef _RENDERENGINE_H
#define _RENDERENGINE_H

#include "RenderEngineParams.h"
#include "CameraParams.h"
#include "../Resources/Scene.h"

class RenderEngine
{
public:
	/**
 	* Name diplayed in the ui.
 	*/
	char Name;
	char IdName;
	/**
 	* Parameters of the render engine.
 	*/
	RenderEngineParams mEngineParms;
	CameraParams mCameraParms;

	/**
 * Starts rendering.Consider allocating  resources here if you deallocate memory on stop.
 */
	virtual void Start();

	/**
 * Draws the render to the 3d view.
 */
	virtual void Display();

	/**
 * Stop rendering also consider freeing memory if the renderer is resource heavy.
 */
	virtual void Stop();

	/**
 * Called when the scene is changed so update the renderer's scene too.
 * @param *Scene
 */
	virtual void UpdateScene(Scene *Scene);

	virtual void UpdateMaterial();

	/**
 * @param *CameraParms
 */
	virtual void UpdateCamera(CameraParams *CameraParms);

	/**
 * The 3d view has been resized so update your framebuffer.
 * @param Width The new width of the 3d view
 * @param Height The new height of the 3d view
 */
	virtual void Resize(int Width, int Height);
};

#endif //_RENDERENGINE_H

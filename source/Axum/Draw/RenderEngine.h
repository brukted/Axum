/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#ifndef _RENDERENGINE_H
#define _RENDERENGINE_H

#include "../Parameter/ParamCollection.h"
#include "../Resources/Scene.h"
#include <string>

class RenderEngine
{
public:
	/**
 	* Name diplayed in the ui.
 	*/
	std::string Name;
	std::string idName;
	/**
 	* Parameters of the render engine.
 	*/
	ParamCollection mEngineParms;
	ParamCollection mCameraParms;

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
	virtual void UpdateCamera(ParamCollection *CameraParms);

	/**
 * The 3d view has been resized so update your framebuffer.
 * @param Width The new width of the 3d view
 * @param Height The new height of the 3d view
 */
	virtual void Resize(int Width, int Height);
};

#endif //_RENDERENGINE_H

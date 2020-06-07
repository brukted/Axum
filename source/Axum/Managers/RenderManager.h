/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#ifndef _RENDERMANAGER_H
#define _RENDERMANAGER_H

#include <vector>
#include "../Draw/RenderEngine.h"

/**
 * @class RenderManager Manages available render engines.
 * 
 */
class RenderManager
{
public:
	static RenderManager &getInstance()
	{
		static RenderManager instance;
		return instance;
	}

private:
	RenderManager(){};

public:
	RenderManager(RenderManager const &) = delete;
	void operator=(RenderManager const &) = delete;

	RenderEngine *CurrentEngine;
	std::vector<RenderEngine> mRenderEngines;

	void Startup();

	void Shutdown();

	/**
 * @param engine
 */
	void SetRenderEngine(RenderEngine *engine);

	/**
 * @param engine
 */
	void RegisterEngine(RenderEngine engine);
};

#endif //_RENDERMANAGER_H

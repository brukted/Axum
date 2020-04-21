/**
 * Project Material Lab
 * @author Bruk Tedla
 */


#ifndef _RENDERMANAGER_H
#define _RENDERMANAGER_H

#include<vector>
#include"../Draw/RenderEngine.h"

class RenderManager {
public: 
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

/**
 * Project Material Lab
 * @author Bruk Tedla
 */


#ifndef _CONTEXT_H
#define _CONTEXT_H

#include "Managers\AddonManager.h"
#include "Managers\BakeryManager.h"
#include "Managers\EditorManager.h"
#include "Managers\PackageManager.h"
#include "Managers\PreferenceManager.h"
#include "Managers\RenderManager.h"
#include "Managers\UndoManager.h"
#include "Managers\WindowManager.h"

class MContext {
public: 
	PreferenceManager PrefMan;
	WindowManager WinMan;
	EditorManager EditorMan;
	BakeryManager BakeryMan;
	RenderManager RenderMan;
	PackageManager PackageMan;
	UndoManager UndoMan;
	AddonManager AddonMan;
	MContext();
};

#endif //_CONTEXT_H

/**
 * Project Material Lab
 * @author Bruk Tedla
 */


#ifndef _PARAMETEREDITORUI_H
#define _PARAMETEREDITORUI_H

#include "../EditorUI.h"
#include "../Widgets/ParamUI.h"
#include "../../Parameter/Param.h"

class ParameterEditorUI: public EditorUI {
public: 
	ParamUI mParamUI;
	
/**
 * Builds the appropirate ui for the parameter collection.
 * @param *param
 */
void BindParm(Param *param);
};

#endif //_PARAMETEREDITORUI_H

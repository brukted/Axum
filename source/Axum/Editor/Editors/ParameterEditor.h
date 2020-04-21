/**
 * Project Material Lab
 * @author Bruk Tedla
 */


#ifndef _PARAMETEREDITOR_H
#define _PARAMETEREDITOR_H

#include "../Editor.h"
#include "../../Parameter/Param.h"

class ParameterEditor: public Editor {
public: 
	Param *currentParamter = nullptr;
	
/**
 * @param *param
 */
void EditParameter(Param *param);
};

#endif //_PARAMETEREDITOR_H

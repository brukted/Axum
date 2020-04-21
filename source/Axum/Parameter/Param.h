/**
 * Project Material Lab
 * @author Bruk Tedla
 */


#ifndef _PARAM_H
#define _PARAM_H

#include <string>
#include <vector>
#include "../UI/Widgets/ParamUI.h"

enum UIType { Slider, Angle, Color };
class Param {
public: 
	std::string Name;
	unsigned int uid;
	UIType mUIType;
	std::vector<UIType> SupportedTypes;
	
/**
 * Displays the data to the ui.
 */
virtual ParamUI GetEditUI();
	
virtual ParamUI GetDisplayUI();
};

#endif //_PARAM_H

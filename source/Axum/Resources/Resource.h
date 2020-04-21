/**
 * Project Material Lab
 * @author Bruk Tedla
 */


#ifndef _RESOURCE_H
#define _RESOURCE_H

#include<string>
#include"../UI/Widgets/ExplorerItemUI.h"

class Resource {
	enum ResourceType { Linked, Embedded };
	enum PathType { Relative, Absolute };
public: 
	std::string Name;
	ResourceType mType;
	/**
 * Path to the resource if it is linked type.
 */
	std::string mPath;
	int UUID;
	PathType mPathType;
	
/**
 * Opens the resource in the appropirate editor.
 */
virtual void Open();
	
/**
 * Returns a UI to display the resource the UI is an instance odf ExplorerItemUI or child of it.
 */
ExplorerItemUI GetUI();
};

#endif //_RESOURCE_H

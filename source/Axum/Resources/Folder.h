/**
 * Project Material Lab
 * @author Bruk Tedla
 */


#ifndef _FOLDER_H
#define _FOLDER_H

#include<vector>
#include "Resource.h"


class Folder: public Resource {
public: 
	std::vector<Resource> mResources;
};

#endif //_FOLDER_H

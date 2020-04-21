/**
 * Project Material Lab
 * @author Bruk Tedla
 */


#ifndef _EDITORMANAGER_H
#define _EDITORMANAGER_H

#include<vector>
#include"../Editor/Editor.h"

class EditorManager {
public: 
	std::vector<Editor> Editors;
	
	void Startup();

    void Shutdown();
};

#endif //_EDITORMANAGER_H

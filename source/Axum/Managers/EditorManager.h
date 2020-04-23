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
	static EditorManager& getInstance(){
		static EditorManager instance;
		return instance;
	}
private:
	EditorManager(){};
public:
	EditorManager(EditorManager const&) = delete;
	void operator=(EditorManager const&) = delete;
	std::vector<Editor> Editors;
	
	void Startup();

    void Shutdown();
};

#endif //_EDITORMANAGER_H

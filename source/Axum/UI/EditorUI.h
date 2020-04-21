/**
 * Project Material Lab
 * @author Bruk Tedla
 */


#ifndef _EDITORUI_H
#define _EDITORUI_H

#include<string>
#include "../Editor/Editor.h"
#include "DockablePanel.h"


class EditorUI: public DockablePanel {
public: 
	Editor *editor = nullptr;
	
/**
 * Returns a pointer to Gtk container where more UI can be added.
 */
void GetSpace();
	
/**
 * @param title
 */
void SetTitle(std::string title);
	
void SetIcon();
};

#endif //_EDITORUI_H

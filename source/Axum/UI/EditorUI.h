/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#ifndef _EDITORUI_H
#define _EDITORUI_H

#include <string>
#include "../Editors/Editor.h"

class EditorUI
{
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

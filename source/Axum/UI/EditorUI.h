/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#ifndef _EDITORUI_H
#define _EDITORUI_H

#include <string>
#include "../Editors/Editor.h"
#include <gdlmm.h>
#include <gtkmm.h>

/**
 * @class EditorUI Editor ui provides common functionalities for editors
 * such as docking and title bar.
 * 
 */
class EditorUI : public Gdl::DockItem
{
protected:
	Gtk::Fixed space;

public:
	Editor *editor = nullptr;

	EditorUI();

	EditorUI(std::string name, std::string longname);

	/**
	 * @brief Returns a reference to Gtk container where more UI can be added.
 	*/
	Gtk::Fixed &GetSpace();

	void SetIcon();
};

#endif //_EDITORUI_H

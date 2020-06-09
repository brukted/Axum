/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#include "EditorUI.h"

/**
 * EditorUI implementation
 * 
 * A basic space on the ui with common functionalities such as stacking,resizing e.t.c.
 */

Gtk::Fixed &EditorUI::GetSpace()
{
    return space;
}

void EditorUI::SetIcon()
{
}

EditorUI::EditorUI() : Gdl::DockItem("name", "long name")
{
    this->add(space);
}

EditorUI::EditorUI(std::string name, std::string longname) : Gdl::DockItem(name, longname)
{
    this->add(space);
}
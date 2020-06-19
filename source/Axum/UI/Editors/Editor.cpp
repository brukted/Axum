/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#include "Editor.h"

/**
 * Editor implementation
 *
 * A basic space on the ui with common functionalities such as stacking,resizing
 * e.t.c.
 */

namespace Axum::UI::Editor {

Gtk::Fixed &Editor::GetSpace() { return space; }

void Editor::SetIcon() {}

Editor::Editor() : Gdl::DockItem("name", "long name") { this->add(space); }

Editor::Editor(std::string name, std::string longname)
    : Gdl::DockItem(name, longname) {
  this->add(space);
}

} // namespace Axum::UI::Editor
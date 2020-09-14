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

Editor::Editor() {}

Editor::Editor(std::string name, std::string longname)
    : name(name), longName(longname) {}

void Editor::draw() { return; }

} // namespace Axum::UI::Editor
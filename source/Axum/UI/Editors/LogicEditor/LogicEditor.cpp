/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#include "LogicEditor.h"

/**
 * Logic graph editor implementation
 */

namespace Axum::UI::Editor {

LogicEditor::LogicEditor() {}

void LogicEditor::draw() {
  if (!ImGui::Begin(_("Logic editor"))) {
    ImGui::End();
    return;
  }
  ImGui::End();
}

} // namespace Axum::UI::Editor
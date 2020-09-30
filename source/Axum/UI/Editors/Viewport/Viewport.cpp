/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#include "Viewport.h"

/**
 * Viewport implementation
 */

namespace Axum::UI::Editor {

Viewport::Viewport() {}

void Viewport::draw() {
  if (!ImGui::Begin(_("Viewport"))) {
    ImGui::End();
    return;
  }
  ImGui::End();
}

} // namespace Axum::UI::Editor
/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#include "TextureViewer.h"

/**
 * TextureViewer implementation
 */

namespace Axum::UI::Editor {

TextureViewer::TextureViewer() : Editor("Texture Viewer", "Texture Viewer") {}

void TextureViewer::draw() {
  if (!ImGui::Begin(_("Texture viewer"))) {
    ImGui::End();
    return;
  }
  ImGui::End();
}

} // namespace Axum::UI::Editor
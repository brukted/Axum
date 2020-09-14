#include "Dialogs.h"

namespace Axum::UI::Widget {
bool newImageTextureDialog(std::string &name, int &width, int &height,
                           float *color) {
  bool response = false;
  if (ImGui::BeginPopupModal(_("Create image texture"), 0,
                             ImGuiWindowFlags_NoMove |
                                 ImGuiWindowFlags_NoCollapse)) {
    ImGui::ColorEdit4(_("Color"), color);
    ImGui::InputText(_("Texture name"), &name);
    ImGui::Separator();
    ImGui::SliderInt(_("Width"), &width, 1, 2048);
    ImGui::SliderInt(_("Height"), &height, 1, 2048);
    ImGui::Separator();
    if (ImGui::Button(_("Create"))) {
      ImGui::CloseCurrentPopup();
      response = true;
    }
    ImGui::SameLine();
    if (ImGui::Button(_("Cancel"))) {
      ImGui::CloseCurrentPopup();
      response = false;
    }
    ImGui::EndPopup();
  }
  return response;
}

} // namespace Axum::UI::Widget
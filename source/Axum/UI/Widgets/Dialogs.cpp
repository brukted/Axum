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
bool nativeFileDialog(std::string &path, FileDialogMode mode,
                      std::string_view defaultPath, std::string_view filters) {
  nfdchar_t *nfdPath = nullptr;
  nfdresult_t result;
  if (mode == FileDialogMode::SAVE) {
    result = NFD_SaveDialog(filters.data(), defaultPath.data(), &nfdPath);
  } else if (mode == FileDialogMode::OPEN) {
    result = NFD_OpenDialog(filters.data(), defaultPath.data(), &nfdPath);
  } else {
    result = NFD_PickFolder(defaultPath.data(), &nfdPath);
  }
  if (nfdPath != nullptr) {
    path.assign(nfdPath);
    delete[] nfdPath;
  }
  switch (result) {
  case NFD_OKAY:
    return true;
    break;
  case NFD_CANCEL:
    return false;
    break;
  case NFD_ERROR: {
    auto error = NFD_GetError();
    AX_LOG_EDITOR_ERROR("File dialog error {}", error);
    delete[] error;
    return false;
    break;
  }
  default:
    AX_LOG_EDITOR_CRITICAL("Unkown result from file dialog")
    return false;
    break;
  }
}

} // namespace Axum::UI::Widget
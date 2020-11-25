#include "Dialogs.h"
#include "Utils/Log/Log.h"
#include "Utils/Translation/Translation.h"
#include <imgui.h>
#include <imgui_stdlib.h>
#include <nfd.h>
#include <filesystem>
#include "Managers/PackageManager.h"

namespace Axum::UI::Widget {
bool newImageTextureDialog(std::string *name, int *width, int *height,
                           float *color) {
  assert(name != nullptr);
  assert(width != nullptr);
  assert(height != nullptr);
  assert(color != nullptr);
  bool response = false;
  if (ImGui::BeginPopupModal(_("Create image texture"), 0,
                             ImGuiWindowFlags_NoMove |
                                 ImGuiWindowFlags_NoCollapse)) {
    ImGui::ColorEdit4(_("Color"), color);
    ImGui::InputText(_("Texture name"), name);
    ImGui::Separator();
    ImGui::SliderInt(_("Width"), width, 1, 2048);
    ImGui::SliderInt(_("Height"), height, 1, 2048);
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

bool importResourceDialog(std::string_view title, std::string &path,
                          bool *isLinked) {
  assert(isLinked != nullptr);
  bool response = false;
  if (ImGui::BeginPopupModal(title.data(), 0,
                             ImGuiWindowFlags_NoMove |
                                 ImGuiWindowFlags_NoCollapse)) {
    ImGui::TextUnformatted(_("Path: "));
    ImGui::SameLine();
    ImGui::TextUnformatted(path.c_str());
    ImGui::SameLine();
    ImGui::TextUnformatted("...");
    if (ImGui::IsItemClicked(ImGuiMouseButton_Left)) {
      nativeFileDialog(path, FileDialogMode::OPEN, path, "");
    }
    ImGui::NewLine();
    ImGui::Checkbox(_("Linked"), isLinked);
    if (ImGui::Button(_("Import"))) {
      if (path != "") {
        ImGui::CloseCurrentPopup();
        response = true;
      }
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

void createPackageDialog() 
{
  std::string  path;
  if(nativeFileDialog(path,FileDialogMode::SAVE,"","axpkg")){
    std::filesystem::path p(path);
    p.replace_extension(".axpkg");
    Package_Manager.CreatePackage(p.string());
  }
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
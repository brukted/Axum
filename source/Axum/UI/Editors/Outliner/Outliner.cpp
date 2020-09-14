/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#include "Outliner.h"

/**
 * Outliner implementation
 */

namespace Axum::UI::Editor {

Outliner::Outliner() : Editor("Outliner", "Outliner") {}

void Outliner::draw() {
  if (!ImGui::Begin(_("Outliner"), 0)) {
    ImGui::End();
    return;
  }
  mainContextMenu();

  ///@TODO make the lambdas static
  auto appendResource = [this](ResourceType::Resource *res) {
    bool open = ImGui::TreeNode((void *)res, res->name.GetValue().c_str());
    showRowContextMenu(res);
    if (open) {
      if (ImGui::IsItemActivated()) {
        ParameterEditor::BindParams(res->Params());
      }
      ImGui::TreePop();
    }
  };

  std::function<void(ResourceType::Folder *)> appendFolder =
      [&appendResource, &appendFolder, this](ResourceType::Folder *folder) {
        bool open =
            ImGui::TreeNode((void *)folder, folder->name.GetValue().c_str());
        showRowContextMenu(folder);
        if (open) {
          if (ImGui::IsItemActivated()) {
            ParameterEditor::BindParams(folder->Params());
          }
          for (auto &subFolder : folder->GetSubFolders()) {
            appendFolder(&subFolder);
          }
          for (auto resource : folder->GetResources()) {
            appendResource(resource);
          }
          ImGui::TreePop();
        }
      };

  for (auto &pkg : Package_Manager.packages) {
    bool open = ImGui::TreeNode((void *)&pkg, pkg.name.GetValue().c_str());
    bool isDeleted = showRowContextMenu(&pkg);
    if (open) {
      if (ImGui::IsItemActivated()) {
        ParameterEditor::BindParams(pkg.Params());
      }
      for (auto &folder : pkg.GetRootFolder().GetSubFolders()) {
        appendFolder(&folder);
      }
      for (auto *resource : pkg.GetRootFolder().GetResources()) {
        appendResource(resource);
      }
      ImGui::TreePop();
    }
  }
  ImGui::End();

} // namespace Axum::UI::Editor

void Outliner::openPackage() {}

bool Outliner::showRowContextMenu(ResourceType::Resource *resource) {
  bool isDeleted = false;
  if (ImGui::BeginPopupContextItem()) {
    if (resource->type == ResourceType::Resource::Type::Package) {
      auto package = static_cast<ResourceType::Package *>(resource);
      if (ImGui::BeginMenu(_("New"))) {
        if (ImGui::Selectable(_("Material graph"))) {
          package->AddMaterialGraph(NodeGraph::Material::MaterialGraph());
        }
        if (ImGui::Selectable(_("Logic graph"))) {
          package->AddLogicGraph(NodeGraph::Logic::LogicGraph());
        }
        if (ImGui::Selectable(_("Image texture"))) {
          /// @TODO Show Image texture dialog
          unsigned char color[] = {0, 0, 0, 255};
          package->AddImageTexture(ResourceType::ImageTexture{512, 512, color});
        }
        if (ImGui::Selectable(_("Folder"))) {
          package->GetRootFolder().AddFolder(ResourceType::Folder());
        }
        ImGui::EndMenu();
      }
      if (ImGui::BeginMenu(_("Import"))) {
        /// @TODO add items to import menu  in  folder and package
        ImGui::EndMenu();
      }
      ImGui::Separator();
      ///   @TODO Disable widgets instade of not adding
      if (resource->Path != "") {
        if (ImGui::Selectable(_("Reload")))
          isDeleted = false; /// @TODO Implement reload for package
        if (ImGui::Selectable(_("Save")))
          Package_Manager.SavePackage(*package);
      }
      if (ImGui::Selectable(_("Save as"))) {
        /// @TODO Implement save as for package
      }
      ImGui::Separator();
      /// @TODO Implement paste resource for package
      // ImGui::Selectable(_("Paste"));
      if (ImGui::Selectable(_("Close"))) {
        Package_Manager.ClosePackage(package->uid);
        isDeleted = true;
      }
    } else if (resource->type == ResourceType::Resource::Type::Folder) {
      auto package = resource->package;
      auto folder = static_cast<ResourceType::Folder *>(resource);
      if (ImGui::BeginMenu(_("New"))) {
        if (ImGui::Selectable(_("Material graph"))) {
          package->AddMaterialGraph(NodeGraph::Material::MaterialGraph(),
                                    folder);
        }
        if (ImGui::Selectable(_("Logic graph"))) {
          package->AddLogicGraph(NodeGraph::Logic::LogicGraph(), folder);
        }
        if (ImGui::Selectable(_("Image texture"))) {
          /// @TODO Show Image texture dialog
          unsigned char color[] = {0, 0, 0, 255};
          package->AddImageTexture(ResourceType::ImageTexture{512, 512, color},
                                   folder);
        }
        if (ImGui::Selectable(_("Folder"))) {
          folder->AddFolder(ResourceType::Folder());
        }
        ImGui::EndMenu();
      }
      if (ImGui::BeginMenu(_("Import"))) {
        /// @TODO add items to import menu  in  folder and package
        ImGui::EndMenu();
      }
      ImGui::Separator();
      /// @TODO Implement copy and paste for folder
      if (ImGui::Selectable(_("Paste"))) {
      }
      if (ImGui::Selectable(_("Copy"))) {
      }
      if (ImGui::Selectable(_("Delete"))) {
        folder->parent->RemoveFolder(folder->uid);
        isDeleted = true;
      }
    } else {
      if (!(resource->type == ResourceType::Resource::Type::Font)) {
        ImGui::Selectable(_("Open"));
      }
      if (ImGui::Selectable(_("Copy"))) {
      }
      if (ImGui::Selectable(_("Delete"))) {
        resource->package->RemoveResource(resource->uid);
        isDeleted = true;
      }
      if (resource->isLinked) {
        ImGui::Selectable(_("Reload"));
      }
    }
    ImGui::EndPopup();
  }
  return isDeleted;
}

void Outliner::mainContextMenu() {
  if (ImGui::BeginPopupContextWindow()) {
    if (ImGui::Selectable(_("Create Package")))
      Package_Manager.CreatePackage();
    if (ImGui::Selectable(_("Open Package")))
      openPackage();
    ImGui::EndPopup();
  }
}

} // namespace Axum::UI::Editor
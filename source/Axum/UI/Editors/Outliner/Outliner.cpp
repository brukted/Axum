/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#include "Outliner.h"

/**
 * Outliner implementation
 */

namespace Axum::UI::Editor {

Outliner::Outliner() {}

void Outliner::draw() {
  if (!ImGui::Begin(_("Outliner"), 0)) {
    ImGui::End();
    return;
  }
  mainContextMenu();

  /// TODO make the lambdas static
  auto appendResource = [this](ResourceType::Resource *resource) {
    bool open =
        ImGui::TreeNode((void *)resource, resource->name.getValue().data());
    showRowContextMenu(resource);
    if (open) {
      if (ImGui::IsItemActivated()) {
        ParameterEditor::BindParams(resource->Params());
      }
      if (ImGui::IsMouseDoubleClicked(ImGuiMouseButton_Left)) {
        openResource(resource);
      }
      ImGui::TreePop();
    }
  };

  std::function<void(ResourceType::Folder *)> appendFolder =
      [&appendResource, &appendFolder, this](ResourceType::Folder *folder) {
        bool open =
            ImGui::TreeNode((void *)folder, folder->name.getValue().data());
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
    bool open = ImGui::TreeNode((void *)&pkg, pkg.name.getValue().data());
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
}

void Outliner::openPackage() {
  std::string path;
  if (Widget::nativeFileDialog(path, Widget::FileDialogMode::OPEN, "",
                               "axpkg")) {
    Package_Manager.LoadPackage(path);
  }
}

bool Outliner::showRowContextMenu(ResourceType::Resource *resource) {
  bool isDeleted = false;
  if (ImGui::BeginPopupContextItem()) {
    if (resource->type == ResourceType::Resource::Type::Package) {
      auto package = static_cast<ResourceType::Package *>(resource);
      if (ImGui::BeginMenu(_("New"))) {
        if (ImGui::Button(_("Material graph"))) {
          NodeGraph::Material::MaterialGraph graph;
          package->AddMaterialGraph(std::move(graph));
        }
        if (ImGui::Button(_("Logic graph"))) {
          NodeGraph::Logic::LogicGraph graph;
          package->AddLogicGraph(std::move(graph));
        }
        if (ImGui::Button(_("Image texture"))) {
          ImGui::OpenPopup("Create image texture");
        }
        {
          static int width, height = 512;
          static float colorVec4[4] = {0.4f, 0.7f, 0.0f, 0.5f};
          static std::string name{"texture"};
          if (Widget::newImageTextureDialog(name, width, height, colorVec4)) {
            unsigned char color[] = {(unsigned char)colorVec4[0] * 255,
                                     (unsigned char)colorVec4[1] * 255,
                                     (unsigned char)colorVec4[2] * 255,
                                     (unsigned char)colorVec4[3] * 255};
            auto texture = ResourceType::ImageTexture{width, height, color};
            texture.name.setValue(name);
            package->AddImageTexture(std::move(texture));
          }
        }
        if (ImGui::Button(_("Folder"))) {
          package->GetRootFolder().AddFolder(ResourceType::Folder());
        }
        ImGui::EndMenu();
      }
      if (ImGui::BeginMenu(_("Import"))) {
        /// TODO add items to import menu  in  folder and package
        ImGui::EndMenu();
      }
      ImGui::Separator();
      ///   TODO Disable widgets instade of not adding
      if (resource->Path.size() != 0) {
        if (ImGui::Button(_("Reload")))
          isDeleted = false; /// TODO Implement reload for package
        if (ImGui::Button(_("Save")))
          Package_Manager.SavePackage(*package);
      }
      if (ImGui::Button(_("Save as"))) {
        std::string path;
        if (Widget::nativeFileDialog(path, Widget::FileDialogMode::SAVE,
                                     package->Path, "axpkg")) {
          boost::filesystem::path bp(path);
          bp.replace_extension(".axpkg");
          Package_Manager.SavePackage(*package, bp.string());
        }
      }
      ImGui::Separator();
      /// TODO Implement paste resource for package
      // ImGui::Button(_("Paste"));
      if (ImGui::Button(_("Close"))) {
        Package_Manager.ClosePackage(package->uid);
        isDeleted = true;
      }
    } else if (resource->type == ResourceType::Resource::Type::Folder) {
      auto package = resource->package;
      auto folder = static_cast<ResourceType::Folder *>(resource);
      if (ImGui::BeginMenu(_("New"))) {
        if (ImGui::Button(_("Material graph"))) {
          NodeGraph::Material::MaterialGraph graph;
          package->AddMaterialGraph(std::move(graph), folder);
        }
        if (ImGui::Button(_("Logic graph"))) {
          NodeGraph::Logic::LogicGraph graph;
          package->AddLogicGraph(std::move(graph), folder);
        }
        if (ImGui::Button(_("Image texture"))) {
          ImGui::OpenPopup("Create image texture");
        }
        {
          static int width, height = 512;
          static float colorVec4[4] = {0.4f, 0.7f, 0.0f, 0.5f};
          static std::string name{"texture"};
          if (Widget::newImageTextureDialog(name, width, height, colorVec4)) {
            unsigned char color[] = {colorVec4[0] * 255, colorVec4[1] * 255,
                                     colorVec4[2] * 255, colorVec4[3] * 255};
            auto texture = ResourceType::ImageTexture{width, height, color};
            texture.name.setValue(name);
            package->AddImageTexture(std::move(texture), folder);
          }
        }
        if (ImGui::Button(_("Folder"))) {
          folder->AddFolder(ResourceType::Folder());
        }
        ImGui::EndMenu();
      }
      if (ImGui::BeginMenu(_("Import"))) {
        /// TODO add items to import menu  in  folder and package
        ImGui::EndMenu();
      }
      ImGui::Separator();
      /// TODO Implement copy and paste for folder
      if (ImGui::Button(_("Paste"))) {
      }
      if (ImGui::Button(_("Copy"))) {
      }
      if (ImGui::Button(_("Delete"))) {
        folder->parent->RemoveFolder(folder->uid);
        isDeleted = true;
      }
    } else {
      if (!(resource->type == ResourceType::Resource::Type::Font)) {
        if (ImGui::Button(_("Open"))) {
          openResource(resource);
        }
      }
      if (ImGui::Button(_("Copy"))) {
      }
      if (ImGui::Button(_("Delete"))) {
        resource->package->RemoveResource(resource->uid);
        isDeleted = true;
      }
      if (resource->isLinked) {
        ImGui::Button(_("Reload"));
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

void Outliner::openResource(ResourceType::Resource *resource) {
  if (resource->type == ResourceType::Resource::Type::MaterialGraph) {
    auto *graph = static_cast<NodeGraph::Material::MaterialGraph *>(resource);
    MaterialEditor::openGraph(graph);
  }
}

} // namespace Axum::UI::Editor
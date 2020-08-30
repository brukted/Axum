#include "OutlinerContextMenu.h"
#include "UI/Editors/Outliner/Outliner.h"

namespace Axum::UI::Widget {

OutlinerContextMenu::OutlinerContextMenu(ResourceType::Folder *folder) {
  auto New = new Gtk::MenuItem(_("New"));
  auto Import = new Gtk::MenuItem(_("Import"));
  auto Separator1 = new Gtk::SeparatorMenuItem();
  auto Copy = new Gtk::MenuItem(_("Copy"));
  auto Paste = new Gtk::MenuItem(_("Paste"));
  auto Delete = new Gtk::MenuItem(_("Delete"));
  add(*New);
  add(*Import);
  add(*Separator1);
  add(*Copy);
  add(*Paste);
  add(*Delete);
  Delete->signal_button_press_event().connect([folder](GdkEventButton *evt) {
    auto *package = static_cast<ResourceType::Package *>(folder->package);
    for (auto *res : folder->GetResources()) {
      package->RemoveResource(*res);
    }
    folder->parent->RemoveFolder(folder->uid);
    UI::Editor::Outliner::UpdateItems();
    return true;
  });
  auto NewSubMenu = new Gtk::Menu();
  auto NewMatrialGraph = new Gtk::MenuItem(_("Material Graph"));
  auto NewLogicGraph = new Gtk::MenuItem(_("Logic Graph"));
  auto NewTexture = new Gtk::MenuItem(_("Image Texture"));
  auto NewFolder = new Gtk::MenuItem(_("Folder"));
  NewSubMenu->add(*NewMatrialGraph);
  NewSubMenu->add(*NewLogicGraph);
  NewSubMenu->add(*NewTexture);
  NewSubMenu->add(*NewFolder);
  New->set_submenu(*NewSubMenu);

  NewTexture->signal_button_press_event().connect([folder](
                                                      GdkEventButton *evt) {
    auto *package = static_cast<ResourceType::Package *>(folder->package);
    int width = 1;
    int height = 1;
    std::array<unsigned char, 4> color;
    std::string name{"Image Texture"};
    UI::Widget::NewImageTextureDialog dialog{&width, &height, &color, &name};
    dialog.set_transient_for(*Manager::WindowManager::getInstance().MainWin);
    dialog.show();
    auto result = dialog.run();
    if (result == Gtk::RESPONSE_ACCEPT) {
      unsigned char col[4] = {color[0], color[1], color[2], color[3]};
      auto texture = ResourceType::ImageTexture(
          width, height, col);
      texture.name.SetValue(name);
      package->AddImageTexture(std::move(texture), folder);
      UI::Editor::Outliner::UpdateItems();
    }
    return true;
  });
  NewFolder->signal_button_press_event().connect([folder](GdkEventButton *evt) {
    folder->AddFolder(ResourceType::Folder());
    UI::Editor::Outliner::UpdateItems();
    return true;
  });
  NewMatrialGraph->signal_button_press_event().connect(
      [folder](GdkEventButton *evt) {
        auto *package = static_cast<ResourceType::Package *>(folder->package);
        // @TODO Show graph creation dialog
        package->AddMaterialGraph(NodeGraph::Material::MaterialGraph(), folder);
        UI::Editor::Outliner::UpdateItems();
        return true;
      });
  NewLogicGraph->signal_button_press_event().connect(
      [folder](GdkEventButton *evt) {
        auto *package = static_cast<ResourceType::Package *>(folder->package);
        // @TODO Show graph creation dialog
        package->AddLogicGraph(NodeGraph::Logic::LogicGraph(), folder);
        UI::Editor::Outliner::UpdateItems();
        return true;
      });

  auto ImportSubMenu = new Gtk::Menu();
  auto ImportTexture = new Gtk::MenuItem(_("Image Texture"));
  auto ImportSVG = new Gtk::MenuItem(_("Vector Texture"));
  auto ImportMesh = new Gtk::MenuItem(_("Mesh"));
  ImportSubMenu->add(*ImportTexture);
  ImportSubMenu->add(*ImportSVG);
  ImportSubMenu->add(*ImportMesh);
  Import->set_submenu(*ImportSubMenu);
  // @TODO Implement Import , copy and paste menu actions.
}

OutlinerContextMenu::OutlinerContextMenu(ResourceType::Package *package) {
  auto New = new Gtk::MenuItem(_("New"));
  auto Import = new Gtk::MenuItem(_("Import"));
  auto Separator1 = new Gtk::SeparatorMenuItem();
  auto Reload = new Gtk::MenuItem(_("Reload"));
  auto Save = new Gtk::MenuItem(_("Save"));
  if (package->Path == "") {
    Reload->set_sensitive(false);
    Save->set_sensitive(false);
  }
  auto SaveAs = new Gtk::MenuItem(_("Save As"));
  auto Separator2 = new Gtk::SeparatorMenuItem();
  auto Paste = new Gtk::MenuItem(_("Paste"));
  auto Close = new Gtk::MenuItem(_("Close"));
  add(*New);
  add(*Import);
  add(*Separator1);
  add(*Reload);
  add(*Save);
  add(*SaveAs);
  add(*Separator2);
  add(*Paste);
  add(*Close);
  Close->signal_button_press_event().connect([package](GdkEventButton *evt) {
    //@TODO Check if resources in the package are opened in other editors.
    Package_Manager.ClosePackage(*package);
    //@TODO Check if the bound parameters are the package's before
    // unbinding.
    UI::Editor::ParameterEditor::Unbind();
    UI::Editor::Outliner::UpdateItems();
    return true;
  });
  Save->signal_button_press_event().connect([package](GdkEventButton *evt) {
    Package_Manager.SavePackage(*package);
    return true;
  });
  SaveAs->signal_button_press_event().connect([package](GdkEventButton *evt) {
    Glib::RefPtr<Gtk::FileChooserNative> dialog =
        Gtk::FileChooserNative::create(
            _("Save As"), Gtk::FileChooserAction::FILE_CHOOSER_ACTION_SAVE,
            _("Save"), _("Cancel"));
    auto filter = Gtk::FileFilter::create();
    filter->add_pattern("*.axpkg");
    dialog->add_filter(filter);
    dialog->set_filename(package->name.GetValue() + ".axpkg");
    dialog->set_transient_for(*Manager::WindowManager::getInstance().MainWin);
    int result = dialog->run();
    if (result == Gtk::RESPONSE_ACCEPT || result == Gtk::RESPONSE_OK) {
      Package_Manager.SavePackage(*package, dialog->get_file()->get_path());
    }
    return true;
  });
  auto NewSubMenu = new Gtk::Menu();
  auto NewMatrialGraph = new Gtk::MenuItem(_("Material Graph"));
  auto NewLogicGraph = new Gtk::MenuItem(_("Logic Graph"));
  auto NewTexture = new Gtk::MenuItem(_("Image Texture"));
  auto NewFolder = new Gtk::MenuItem(_("Folder"));
  NewSubMenu->add(*NewMatrialGraph);
  NewSubMenu->add(*NewLogicGraph);
  NewSubMenu->add(*NewTexture);
  NewSubMenu->add(*NewFolder);
  New->set_submenu(*NewSubMenu);

  NewTexture->signal_button_press_event().connect([package](
                                                      GdkEventButton *evt) {
    int width = 1;
    int height = 1;
    std::array<unsigned char, 4> color;
    std::string name{"Image Texture"};
    UI::Widget::NewImageTextureDialog dialog{&width, &height, &color, &name};
    dialog.set_transient_for(*Manager::WindowManager::getInstance().MainWin);
    dialog.show();
    auto result = dialog.run();
    if (result == Gtk::RESPONSE_ACCEPT) {
      unsigned char col[4] = {color[0], color[1], color[2], color[3]};
      auto texture = ResourceType::ImageTexture(width, height, col);
      texture.name.SetValue(name);
      package->AddImageTexture(std::move(texture));
      UI::Editor::Outliner::UpdateItems();
    }
    return true;
  });
  NewFolder->signal_button_press_event().connect(
      [package](GdkEventButton *evt) {
        auto &root = package->GetRootFolder();
        root.AddFolder(ResourceType::Folder());
        UI::Editor::Outliner::UpdateItems();
        return true;
      });
  NewMatrialGraph->signal_button_press_event().connect(
      [package](GdkEventButton *evt) {
        auto graph = NodeGraph::Material::MaterialGraph();
        // @TODO Show graph creation dialog
        package->AddMaterialGraph(graph,nullptr);
        UI::Editor::Outliner::UpdateItems();
        return true;
      });
  NewLogicGraph->signal_button_press_event().connect(
      [package](GdkEventButton *evt) {
        auto graph = NodeGraph::Logic::LogicGraph();
        // @TODO Show graph creation dialog
        package->AddLogicGraph(std::move(graph));
        UI::Editor::Outliner::UpdateItems();
        return true;
      });

  auto ImportSubMenu = new Gtk::Menu();
  auto ImportTexture = new Gtk::MenuItem(_("Image Texture"));
  auto ImportSVG = new Gtk::MenuItem(_("Vector Texture"));
  auto ImportMesh = new Gtk::MenuItem(_("Mesh"));
  ImportSubMenu->add(*ImportTexture);
  ImportSubMenu->add(*ImportSVG);
  ImportSubMenu->add(*ImportMesh);
  Import->set_submenu(*ImportSubMenu);
  // @TODO Implement Import , reload and paste menu actions.
}

OutlinerContextMenu::OutlinerContextMenu(ResourceType::Font *font) {
  auto Copy = new Gtk::MenuItem(_("Copy"));
  auto Delete = new Gtk::MenuItem(_("Delete"));
  auto Reload = new Gtk::MenuItem(_("Reload"));
  add(*Copy);
  add(*Delete);
  if (font->isLinked)
    add(*Reload);
  Delete->signal_button_press_event().connect([=](GdkEventButton *) {
    auto *package = static_cast<ResourceType::Package *>(font->package);
    package->RemoveResource(*font);
    UI::Editor::Outliner::UpdateItems();
    return true;
  });
  // @TODO Implement Open , Copy , Delete and reload menu actions.
}

OutlinerContextMenu::OutlinerContextMenu(ResourceType::Scene *scene) {
  auto Open = new Gtk::MenuItem(_("Open"));
  auto Copy = new Gtk::MenuItem(_("Copy"));
  auto Delete = new Gtk::MenuItem(_("Delete"));
  auto Reload = new Gtk::MenuItem(_("Reload"));
  add(*Open);
  add(*Copy);
  add(*Delete);
  if (scene->isLinked)
    add(*Reload);
  Delete->signal_button_press_event().connect([=](GdkEventButton *) {
    auto *package = static_cast<ResourceType::Package *>(scene->package);
    package->RemoveResource(*scene);
    UI::Editor::Outliner::UpdateItems();
    return true;
  });
  // @TODO Implement Open , Copy , Delete and reload menu actions.
}

OutlinerContextMenu::OutlinerContextMenu(ResourceType::ImageTexture *texture) {
  auto Open = new Gtk::MenuItem(_("Open"));
  auto Copy = new Gtk::MenuItem(_("Copy"));
  auto Delete = new Gtk::MenuItem(_("Delete"));
  auto Reload = new Gtk::MenuItem(_("Reload"));
  add(*Open);
  add(*Copy);
  add(*Delete);
  if (texture->isLinked)
    add(*Reload);
  Delete->signal_button_press_event().connect([=](GdkEventButton *) {
    auto *package = static_cast<ResourceType::Package *>(texture->package);
    package->RemoveResource(*texture);
    UI::Editor::Outliner::UpdateItems();
    return true;
  });
  // @TODO Implement Open , Copy , Delete and reload menu actions.
}

OutlinerContextMenu::OutlinerContextMenu(ResourceType::VectorTexture *texture) {
  auto Open = new Gtk::MenuItem(_("Open"));
  auto Copy = new Gtk::MenuItem(_("Copy"));
  auto Delete = new Gtk::MenuItem(_("Delete"));
  auto Reload = new Gtk::MenuItem(_("Reload"));
  add(*Open);
  add(*Copy);
  add(*Delete);
  if (texture->isLinked)
    add(*Reload);
  Delete->signal_button_press_event().connect([=](GdkEventButton *) {
    auto *package = static_cast<ResourceType::Package *>(texture->package);
    package->RemoveResource(*texture);
    UI::Editor::Outliner::UpdateItems();
    return true;
  });
  // @TODO Implement Open , Copy , Delete and reload menu actions.
}

OutlinerContextMenu::OutlinerContextMenu(
    NodeGraph::Material::MaterialGraph *graph) {
  auto Open = new Gtk::MenuItem(_("Open"));
  auto Copy = new Gtk::MenuItem(_("Copy"));
  auto Delete = new Gtk::MenuItem(_("Delete"));
  auto Reload = new Gtk::MenuItem(_("Reload"));
  add(*Open);
  add(*Copy);
  add(*Delete);
  if (graph->isLinked)
    add(*Reload);
  Delete->signal_button_press_event().connect([=](GdkEventButton *) {
    auto *package = static_cast<ResourceType::Package *>(graph->package);
    package->RemoveResource(*graph);
    UI::Editor::Outliner::UpdateItems();
    return true;
  });
  // @TODO Implement Open , Copy , Delete and reload menu actions.
}

OutlinerContextMenu::OutlinerContextMenu(NodeGraph::Logic::LogicGraph *graph) {
  auto Open = new Gtk::MenuItem(_("Open"));
  auto Copy = new Gtk::MenuItem(_("Copy"));
  auto Delete = new Gtk::MenuItem(_("Delete"));
  auto Reload = new Gtk::MenuItem(_("Reload"));
  add(*Open);
  add(*Copy);
  add(*Delete);
  if (graph->isLinked)
    add(*Reload);
  Delete->signal_button_press_event().connect([=](GdkEventButton *) {
    auto *package = static_cast<ResourceType::Package *>(graph->package);
    package->RemoveResource(*graph);
    UI::Editor::Outliner::UpdateItems();
    return true;
  });
  // @TODO Implement Open , Copy , Delete and reload menu actions.
}

} // namespace Axum::UI::Widget
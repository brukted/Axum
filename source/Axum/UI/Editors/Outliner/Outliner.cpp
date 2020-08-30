/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#include "Outliner.h"

/**
 * Outliner implementation
 */

namespace Axum::UI::Editor {
Outliner::Columns Outliner::columns;
Glib::RefPtr<Gtk::TreeStore> Outliner::store =
    Gtk::TreeStore::create(Outliner::columns);

Outliner::Outliner() : Editor("Outliner", "Outliner") {
  mActionGroup = Gtk::ActionGroup::create();
  mActionGroup->add(Gtk::Action::create("CreatePackage", "Create Package",
                                        "Creates new package."),
                    sigc::mem_fun(*this, &CreatePackage));
  mActionGroup->add(Gtk::Action::create("OpenPackage", "Open Package"),
                    sigc::mem_fun(*this, &OpenPackage));
  mUIManager = Gtk::UIManager::create();
  mUIManager->insert_action_group(mActionGroup);
  std::string ContextMenuUI{"<ui>"
                            "<popup name='OutlinerMainPopupMenu'>"
                            "<menuitem action='CreatePackage'/>"
                            "<menuitem action='OpenPackage'/>"
                            "</popup>"
                            "</ui>"};
  mUIManager->add_ui_from_string(ContextMenuUI);
  MainContextMenu = dynamic_cast<Gtk::Menu *>(
      mUIManager->get_widget("/OutlinerMainPopupMenu"));
  UpdateItems();
  iconCol.set_renderer(iconCellRenderer, columns.icon);
  resourcesCol.set_renderer(textCellRenderer, columns.name);
  tree.append_column(iconCol);
  tree.append_column(resourcesCol);
  tree.set_headers_visible(false);
  rootBox.pack_end(tree, true, true);
  space.add(rootBox);
  // @note The signal handlers don't necessary need to be a member function
  // consider making them static, if that will result better performance or
  // simpler code.
  signal_button_press_event().connect(sigc::mem_fun(*this, &OnButtonPress));
  signal_key_press_event().connect(sigc::mem_fun(*this, &OnKeyPress));
  signal_key_release_event().connect(sigc::mem_fun(*this, &OnKeyRelease));
  rootBox.signal_button_press_event().connect(
      sigc::mem_fun(*this, &OnButtonPressTree));
  tree.get_selection()->signal_changed().connect_notify(
      sigc::mem_fun(*this, &OnSelectionChangedTree));
  show_all();
}

void Outliner::UpdateItems() {
  store->clear();
  for (auto &pkg : Package_Manager.Packages) {
    pkg.AppendToModel(store->append(), store.get());
  }
}

bool Outliner::OnButtonPress(GdkEventButton *evt) {
  if (evt->button == GDK_BUTTON_SECONDARY) {
    MainContextMenu->popup_at_pointer((GdkEvent *)evt);
    return true;
  }
  return false;
}

bool Outliner::OnKeyPress(GdkEventKey *evt) {
  if (evt->keyval == GDK_KEY_Control_L || evt->keyval == GDK_KEY_Control_R) {
    tree.get_selection()->set_mode(Gtk::SelectionMode::SELECTION_MULTIPLE);
    return true;
  }
  return false;
}

bool Outliner::OnKeyRelease(GdkEventKey *evt) {
  if (evt->keyval == GDK_KEY_Control_L || evt->keyval == GDK_KEY_Control_R) {
    tree.get_selection()->set_mode(Gtk::SelectionMode::SELECTION_SINGLE);
    return true;
  }
  return false;
}

bool Outliner::OnButtonPressTree(GdkEventButton *evt) {
  if (evt->button == GDK_BUTTON_SECONDARY) {
    if (tree.get_selection()->get_mode() ==
        Gtk::SelectionMode::SELECTION_SINGLE) {
      ShowRowContextMenu((GdkEvent *)evt);
      return true;
    }
    return false;
  }
  return false;
}

void Outliner::CreatePackage() {
  Package_Manager.CreatePackage();
  UpdateItems();
}

void Outliner::OpenPackage() {
  Glib::RefPtr<Gtk::FileChooserNative> dialog = Gtk::FileChooserNative::create(
      "Please choose a package",
      Gtk::FileChooserAction::FILE_CHOOSER_ACTION_OPEN, "Open", "Cancel");
  auto filter = Gtk::FileFilter::create();
  filter->add_pattern("*.axpkg");
  dialog->add_filter(filter);
  dialog->set_transient_for(*Manager::WindowManager::getInstance().MainWin);
  int result = dialog->run();
  switch (result) {
  case Gtk::RESPONSE_ACCEPT:
  case Gtk::RESPONSE_OK:
    for (auto file : dialog->get_files()) {
      Package_Manager.LoadPackage(file->get_path());
      UpdateItems();
    }
    break;
  case Gtk::RESPONSE_CANCEL:
    break;
  default:
    AX_LOG_EDITOR_WARN("Unhandled result code from file chooser dialog in "
                       "outliner. code = {0:d}",
                       result)
    break;
  }
}

void Outliner::ShowRowContextMenu(GdkEvent *evt) {
  AX_LOG_EDITOR_DEBUG("Showing row context menu.")
  auto Res = tree.get_selection()->get_selected();
  if (Res == nullptr)
    return;
  auto ResPtr = Res->get_value<ResourceType::Resource *>(columns.pointer);
  switch (ResPtr->type) {
  case ResourceType::Resource::Type::Package:
    RowContextMenu = UI::Widget::OutlinerContextMenu(
        static_cast<ResourceType::Package *>(ResPtr));
    break;
  case ResourceType::Resource::Type::Folder:
    RowContextMenu = UI::Widget::OutlinerContextMenu(
        static_cast<ResourceType::Folder *>(ResPtr));
    break;
  case ResourceType::Resource::Type::Font:
    RowContextMenu = UI::Widget::OutlinerContextMenu(
        static_cast<ResourceType::Font *>(ResPtr));
    break;
  case ResourceType::Resource::Type::ImageTexture:
    RowContextMenu = UI::Widget::OutlinerContextMenu(
        static_cast<ResourceType::ImageTexture *>(ResPtr));
    break;
  case ResourceType::Resource::Type::Scene:
    RowContextMenu = UI::Widget::OutlinerContextMenu(
        static_cast<ResourceType::Scene *>(ResPtr));
    break;
  case ResourceType::Resource::Type::VectorTexture:
    RowContextMenu = UI::Widget::OutlinerContextMenu(
        static_cast<ResourceType::VectorTexture *>(ResPtr));
    break;
  case ResourceType::Resource::Type::MaterialGraph:
    RowContextMenu = UI::Widget::OutlinerContextMenu(
        static_cast<NodeGraph::Material::MaterialGraph *>(ResPtr));
    break;
  case ResourceType::Resource::Type::LogicGraph:
    RowContextMenu = UI::Widget::OutlinerContextMenu(
        static_cast<NodeGraph::Logic::LogicGraph *>(ResPtr));
    break;
  case ResourceType::Resource::Type::Generic:
    AX_LOG_EDITOR_WARN("Generic resource type in outliner.")
    return;
  default:
    AX_LOG_EDITOR_WARN("Unkown resource type in outliner.")
    return;
  }
  RowContextMenu.show_all();
  RowContextMenu.popup_at_pointer(evt);
}

void Outliner::OnSelectionChangedTree() {
  if (tree.get_selection()->get_mode() != Gtk::SELECTION_SINGLE)
    return;
  auto row = tree.get_selection()->get_selected();
  if (row == nullptr)
    return;
  ResourceType::Resource *ResPtr;
  row->get_value(2, ResPtr);
  ParameterEditor::BindParams(ResPtr->Params());
}

} // namespace Axum::UI::Editor
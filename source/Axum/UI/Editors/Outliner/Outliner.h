/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#ifndef _OUTLINER_H
#define _OUTLINER_H

#include "../Editor.h"
#include "../ParameterEditor/ParameterEditor.h"
#include "Log.h"
#include "Managers/PackageManager.h"
#include "Managers/WindowManager.h"
#include "ResourceTypes/Resource.h"
#include "UI/Widgets/OutlinerContextMenu.h"
#include <gtkmm.h>
#include <string>
#include <vector>

namespace Axum::UI {
namespace Editor {

/// @TODO : Replace the uid column with pointer to the resource that way we
/// don't have to search the item in the package heirarchy everytime we want to
/// reference it.

class Outliner : public Editor {
private:
  class Columns : public Gtk::TreeModel::ColumnRecord {
  public:
    Gtk::TreeModelColumn<Glib::RefPtr<Gdk::Pixbuf>> icon;
    Gtk::TreeModelColumn<std::string> name;
    Gtk::TreeModelColumn<ResourceType::Resource *> pointer;
    Columns() {
      add(icon);
      add(name);
      add(pointer);
    }
  };
  Gtk::Box rootBox{Gtk::ORIENTATION_VERTICAL};
  static Outliner::Columns columns;
  static Glib::RefPtr<Gtk::TreeStore> store;
  Gtk::TreeView tree = Gtk::TreeView{Glib::RefPtr<Gtk::TreeStore>(store)};
  Gtk::CellRendererPixbuf iconCellRenderer{};
  Gtk::TreeViewColumn iconCol{"", iconCellRenderer};
  Gtk::CellRendererText textCellRenderer;
  Gtk::TreeViewColumn resourcesCol{"", textCellRenderer};
  Gtk::Menu *MainContextMenu = nullptr;
  Gtk::Menu RowContextMenu;
  Glib::RefPtr<Gtk::UIManager> mUIManager;
  Glib::RefPtr<Gtk::ActionGroup> mActionGroup;

public:
  Outliner();

  /**
   * @brief Rebuilds the tree.
   *
   */
  static void UpdateItems();

  bool OnButtonPress(GdkEventButton *evt);

  bool OnKeyPress(GdkEventKey *evt);

  bool OnKeyRelease(GdkEventKey *evt);

  bool OnButtonPressTree(GdkEventButton *evt);

  void CreatePackage();

  void OpenPackage();

  void ShowRowContextMenu(GdkEvent *evt);

  void OnSelectionChangedTree();
};

} // namespace Editor
} // namespace Axum::UI

#endif //_OUTLINER_UI_H
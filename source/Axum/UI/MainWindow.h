/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#ifndef _MAINWINDOW_H
#define _MAINWINDOW_H

#include "Editors/Outliner/Outliner.h"
#include "gdlmm.h"
#include "gtkmm.h"

namespace Axum::UI::Window {
/**
 * @brief MainWindow provides a functionality to open a full fledged
 * window which supports docking. Main window is also the only window type that
 * can contain @a Editor.
 *
 */
class MainWindow : public Gtk::ApplicationWindow {
protected:
  Gdl::Dock dock;
  Glib::RefPtr<Gdl::DockMaster> master = dock.get_master();
  Glib::RefPtr<Gdl::DockLayout> layout = Gdl::DockLayout::create(dock);

public:
  MainWindow();
};

} // namespace Axum::UI::Window
#endif //_MAINWINDOW_H

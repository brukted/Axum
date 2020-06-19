/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#ifndef _MAINWINDOW_H
#define _MAINWINDOW_H

#include "Editors/Outliner/Outliner.h"
#include "gtkmm.h"

namespace Axum::UI::Window {
/**
 * @brief MainWindow main window provides a functionality to open a full fledged
 * window which supports docking. Main window is also the only window type that
 * can contain @a Editor.
 *
 */
class MainWindow : public Gtk::ApplicationWindow {
protected:
public:
  MainWindow();
};

} // namespace Axum::UI::Window
#endif //_MAINWINDOW_H

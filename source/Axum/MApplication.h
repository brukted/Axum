/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#ifndef _MAPPLICATION_H
#define _MAPPLICATION_H

#include "Managers/AddonManager.h"
#include "Managers/PackageManager.h"
#include "Managers/PreferenceManager.h"
#include "Managers/RenderManager.h"
#include "Managers/UndoManager.h"
#include "Managers/WindowManager.h"
#include "UI/SplashWindow.h"
#include <gtkmm.h>

namespace Axum {

class MApplication : public Gtk::Application {
protected:
  MApplication();

public:
  static Glib::RefPtr<MApplication> create();
  ~MApplication();

protected:
  void on_activate() override;
  void on_open(const Gio::Application::type_vec_files &files,
               const Glib::ustring &hint) override;
};
} // namespace Axum

#endif //_MAPPLICATION_H

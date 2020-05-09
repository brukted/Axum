/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#ifndef _MAPPLICATION_H
#define _MAPPLICATION_H

#include "gtkmm-3.0/gtkmm.h"
#include "UI/SplashWindow.h"
#include "Managers/PreferenceManager.h"
#include "Managers/UndoManager.h"
#include "Managers/PackageManager.h"
#include "Managers/RenderManager.h"
#include "Managers/BakeryManager.h"
#include "Managers/EditorManager.h"
#include "Managers/WindowManager.h"
#include "Managers/AddonManager.h"

class MApplication : public Gtk::Application
{
protected:
	MApplication();

public:
	constexpr static const unsigned int ApplicationVersion[3] = {1, 0, 0};
	static Glib::RefPtr<MApplication> create();

protected:
	void on_activate() override;
	void on_open(const Gio::Application::type_vec_files &files, const Glib::ustring &hint) override;
};

#endif //_MAPPLICATION_H

/**
 * Project Material Lab
 * @author Bruk Tedla
 */


#ifndef _MAPPLICATION_H
#define _MAPPLICATION_H

#include "MContext.h"
#include "gtkmm-3.0/gtkmm.h"
#include "UI/SplashWindow.h"
#include "boost/foreach.hpp"

class MApplication:public Gtk::Application {
protected:
	MApplication();
public:
	static MContext *context;
	constexpr static const unsigned int ApplicationVersion[3] = {1,0,0};
	static Glib::RefPtr<MApplication> create();

private:
	MContext mContext;

protected:
	void on_activate() override;
	void on_open(const Gio::Application::type_vec_files& files,const Glib::ustring& hint) override;
};

#endif //_MAPPLICATION_H

/**
 * Project Material Lab
 * @author Bruk Tedla
 */


#include "MApplication.h"
#include <iostream>

/**
 * MApplication implementation
 */

MApplication::MApplication():Gtk::Application("com.bruk.tedla.Axum", Gio::APPLICATION_HANDLES_OPEN){
    
}

Glib::RefPtr<MApplication> MApplication::create(){
    return Glib::RefPtr<MApplication> (new MApplication());
}

void MApplication::on_activate(){
    auto splashScreen = SplashWindow(500,500);
    this->add_window(splashScreen);
    splashScreen.present();
    while(gtk_events_pending()){
        gtk_main_iteration();
    }
    while(1){}
    /*
    this->mContext = new MContext();
    this->context = &(this->mContext);
    */

}

void MApplication::on_open(const Gio::Application::type_vec_files& files,const Glib::ustring& hint){

}

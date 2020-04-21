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
    this->mContext = MContext();
    this->context = &(this->mContext);
    //Start the Prefernce Manager first as it does not depend on anything
    this->mContext.PrefMan.Startup();
    //Starts Undo Manager
    this->mContext.UndoMan.Startup();
    //Starts the manager and intilizes package related stufffs
    this->mContext.PackageMan.Startup();
    //Starts the manager and intilize render engines 
    this->mContext.RenderMan.Startup();
    //Starts the manager and initilizes bakery and it's bakers
    this->mContext.BakeryMan.Startup();
    //Starts the manager and intilizes editors 
    this->mContext.EditorMan.Startup();
    //Starts the manager and initilizes the main window but won't show it
    this->mContext.WinMan.Startup();
    //Addon Manager is started at last because it has reference to all aspects of the software
    this->mContext.AddonMan.Startup();
    this->mContext.WinMan.ShowMainWindow();
}

void MApplication::on_open(const Gio::Application::type_vec_files& files,const Glib::ustring& hint){

}

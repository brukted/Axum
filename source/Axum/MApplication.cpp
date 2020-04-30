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
    //Start the Prefernce Manager first as it does not depend on anything
    PreferenceManager::getInstance().Startup();
    //Starts Undo Manager
    UndoManager::getInstance().Startup();
    //Starts the manager and intilizes package related stufffs
    PackageManager::getInstance().Startup();
    //Starts the manager and intilize render engines 
    RenderManager::getInstance().Startup();
    //Starts the manager and initilizes bakery and it's bakers
    BakeryManager::getInstance().Startup();
    //Starts the manager and intilizes editors 
    EditorManager::getInstance().Startup();
    //Starts the manager and initilizes the main window but won't show it
    WindowManager::getInstance(this).Startup();
    //Addon Manager is started at last because it has reference to all aspects of the software
    AddonManager::getInstance().Startup();
    WindowManager::getInstance().ShowMainWindow();
}

void MApplication::on_open(const Gio::Application::type_vec_files& files,const Glib::ustring& hint){
    for(auto f : files)
    {
        PackageManager::getInstance().LoadProject(f);
    }
}

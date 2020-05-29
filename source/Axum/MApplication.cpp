/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#include "MApplication.h"

/**
 * MApplication implementation
 */

MApplication::MApplication() : Gtk::Application("com.bruk.tedla.Axum", Gio::APPLICATION_HANDLES_OPEN)
{
}

Glib::RefPtr<MApplication> MApplication::create()
{
    return Glib::RefPtr<MApplication>(new MApplication());
}

MApplication::~MApplication()
{
    //TODO: Currently shutdown sequence is  a reverse of startup sequence consider adjusting the order.
    AX_LOG_EDITOR_TRACE("Shutting down Window manager")
    WindowManager::getInstance(this).Shutdown();

    AX_LOG_EDITOR_TRACE("Shutting down Editor manager")
    EditorManager::getInstance().Shutdown();

    AX_LOG_EDITOR_TRACE("Shutting down Bakery manager")
    BakeryManager::getInstance().Shutdown();

    AX_LOG_EDITOR_TRACE("Shutting down PackageManager")
    RenderManager::getInstance().Shutdown();

    AX_LOG_EDITOR_TRACE("Shutting down PackageManager")
    PackageManager::getInstance().Shutdown();

    AX_LOG_EDITOR_TRACE("Shutting down UndoManager")
    UndoManager::getInstance().Shutdown();

    AX_LOG_EDITOR_TRACE("Shutting down preference manager")
    PreferenceManager::getInstance().Shutdown();
}

void MApplication::on_activate()
{
    auto splashScreen = SplashWindow(500, 500);
    this->add_window(splashScreen);
    splashScreen.present();
    while (gtk_events_pending())
    {
        gtk_main_iteration();
    }
    //Start the Preference Manager first as it does not depend on anything
    AX_LOG_EDITOR_TRACE("Starting up preference manager")
    PreferenceManager::getInstance().Startup();
    //Starts Undo Manager
    AX_LOG_EDITOR_TRACE("Starting up undo manager")
    UndoManager::getInstance().Startup();
    //Starts the manager and initializes package related stuffs
    AX_LOG_EDITOR_TRACE("Starting up package manager")
    PackageManager::getInstance().Startup();
    //Starts the manager and initialize render engines
    AX_LOG_EDITOR_TRACE("Starting up render manager")
    RenderManager::getInstance().Startup();
    //Starts the manager and initializes bakery and it's bakers
    AX_LOG_EDITOR_TRACE("Starting up bakery manager")
    BakeryManager::getInstance().Startup();
    //Starts the manager and initializes editors
    AX_LOG_EDITOR_TRACE("Starting up editor manager")
    EditorManager::getInstance().Startup();
    //Starts the manager and initializes the main window but won't show it
    AX_LOG_EDITOR_TRACE("Starting up window manager")
    WindowManager::getInstance(this).Startup();
    //Addon Manager is started at last because it has reference to all aspects of the software
    AX_LOG_EDITOR_TRACE("Starting up addon manager")
    AddonManager::getInstance().Startup();
    WindowManager::getInstance().ShowMainWindow();
}

void MApplication::on_open(const Gio::Application::type_vec_files &files, const Glib::ustring &hint)
{
    for (auto f : files)
    {
        PackageManager::getInstance().LoadPackage(f);
    }
}

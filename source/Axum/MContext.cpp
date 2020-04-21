/**
 * Project Material Lab
 * @author Bruk Tedla
 */


#include "MContext.h"

/**
 * Context implementation
 * 
 * Current context of the application.
 */
MContext::MContext(){
    //Order of intilization does not matter as the constructors does not do any thing.
    this->AddonMan = AddonManager();
    this->BakeryMan = BakeryManager();
    this->EditorMan = EditorManager();
    this->PackageMan = PackageManager();
    this->PrefMan = PreferenceManager();
    this->RenderMan = RenderManager();
    this->UndoMan = UndoManager();
    this->WinMan = WindowManager();
}
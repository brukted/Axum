/**
 * Project Material Lab
 * @author Bruk Tedla
 */


#ifndef _WINDOWMANAGER_H
#define _WINDOWMANAGER_H

#include<vector>
#include"../UI/Window.h"
#include"../UI/MainWindow.h"

class WindowManager {
public: 
	static WindowManager& getInstance(){
		static WindowManager instance;
		return instance;
	}
private:
	WindowManager(){};
public:
	WindowManager(WindowManager const&) = delete;
	void operator=(WindowManager const&) = delete;
/**
 * @param window
 */
void AddWindow(Window window);

void Startup();

void Shutdown();

void ShowMainWindow();

private: 
	std::vector<Window> windows;
	MainWindow* MainWin;
};

#endif //_WINDOWMANAGER_H

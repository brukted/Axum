/**
 * Project Material Lab
 * @author Bruk Tedla
 */


#ifndef _BAKERYMANAGER_H
#define _BAKERYMANAGER_H

#include"../Bakery/Bakery.h"

class BakeryManager {
public: 
	Bakery mBakery;
	void Startup();
	void Shutdown();

};

#endif //_BAKERYMANAGER_H

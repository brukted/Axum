/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#ifndef _BAKERYMANAGER_H
#define _BAKERYMANAGER_H

#include "../Bakery/Bakery.h"

class BakeryManager
{
public:
	static BakeryManager &getInstance()
	{
		static BakeryManager instance;
		return instance;
	}

private:
	BakeryManager(){};

public:
	BakeryManager(BakeryManager const &) = delete;
	void operator=(BakeryManager const &) = delete;
	Bakery mBakery;
	void Startup();
	void Shutdown();
};

#endif //_BAKERYMANAGER_H

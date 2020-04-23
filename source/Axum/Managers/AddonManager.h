/**
 * Project Material Lab
 * @author Bruk Tedla
 */


#ifndef _ADDONMANAGER_H
#define _ADDONMANAGER_H

#include<vector>
#include"../Addon/Addon.h"

class AddonManager {
public:
	static AddonManager& getInstance(){
		static AddonManager instance;
		return instance;
	}
private:
	AddonManager(){};
public:
	AddonManager(AddonManager const&) = delete;
	void operator=(AddonManager const&) = delete;
	
	std::vector<Addon> Addons;
	
	void Startup();

    void Shutdown();

	void Refresh();
};

#endif //_ADDONMANAGER_H

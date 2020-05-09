/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#ifndef _PACKAGEMANAGER_H
#define _PACKAGEMANAGER_H

#include <string>
#include "../Package/Package.h"
#include "gtkmm-3.0/gtkmm.h"

class PackageManager
{
public:
	static PackageManager &getInstance()
	{
		static PackageManager instance;
		return instance;
	}

private:
	PackageManager(){};

public:
	PackageManager(PackageManager const &) = delete;
	void operator=(PackageManager const &) = delete;

	std::vector<Package> mPackages;

	void Startup();

	void Shutdown();
	/**
 * @param Path
 */
	void LoadProject(std::string &Path);
	/**
 * @param file
 */
	void LoadProject(const Glib::RefPtr<Gio::File> &file);

	void SavePackage();
};

#endif //_PACKAGEMANAGER_H

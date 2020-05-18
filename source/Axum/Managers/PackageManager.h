/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#ifndef _PACKAGEMANAGER_H
#define _PACKAGEMANAGER_H

#include <string>
#include <fstream>
#include "boost/archive/text_iarchive.hpp"
#include "boost/archive/text_oarchive.hpp"
#include "../Package/Package.h"
#include "gtkmm-3.0/gtkmm.h"
#include <list>
#include <boost/filesystem.hpp>
#include "../Utils/Log/Log.h"

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

	std::list<Package> mPackages;

	void Startup() noexcept;

	void Shutdown() noexcept;
	/**
	 * @brief Loads the package at the specified path.This is blocking call.
	 * 
	 * @param Path 
	 */
	void LoadPackage(std::string &Path);
	/**
 * @param file
 */
	void LoadPackage(const Glib::RefPtr<Gio::File> &file);

	void SavePackage(Package &pkg);
};

#endif //_PACKAGEMANAGER_H

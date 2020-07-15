/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#ifndef _PACKAGEMANAGER_H
#define _PACKAGEMANAGER_H

#include "../ResourceTypes/Package.h"
#include "Log.h"
#include "boost/archive/text_iarchive.hpp"
#include "boost/archive/text_oarchive.hpp"
#include "gtkmm-3.0/gtkmm.h"
#include <boost/filesystem.hpp>
#include <fstream>
#include <list>
#include <string>

namespace Axum::Manager {

class PackageManager {
public:
  static PackageManager &getInstance() {
    static PackageManager instance;
    return instance;
  }

private:
  PackageManager(){};

public:
  PackageManager(PackageManager const &) = delete;
  void operator=(PackageManager const &) = delete;

  std::list<ResourceType::Package> mPackages;

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

  void SavePackage(ResourceType::Package &pkg);
};
} // namespace Axum::Manager

/**
 * @brief Shortcut to the instance of PackageManager.
 * 
 */
#define Package_Manager Axum::Manager::PackageManager::getInstance() 
#endif //_PACKAGEMANAGER_H

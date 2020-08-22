/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#ifndef _PACKAGEMANAGER_H
#define _PACKAGEMANAGER_H

#include "Log.h"
#include "ResourceTypes/Package.h"
#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/filesystem.hpp>
#include <fstream>
#include <gtkmm-3.0/gtkmm.h>
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
  unsigned int LastUID = 0;

public:
  PackageManager(PackageManager const &) = delete;
  void operator=(PackageManager const &) = delete;

  std::list<ResourceType::Package> Packages;

  void Startup() noexcept;

  void Shutdown() noexcept;

  /**
   * @brief Loads the package at the specified path.This is blocking call.
   *
   * @param Path Path to the project file including the file name.
   */
  void LoadPackage(std::string Path);

  /**
   * @brief Loads the package at the specified path.This is blocking call.
   *
   */
  void LoadPackage(const Glib::RefPtr<Gio::File> file);

  void SavePackage(ResourceType::Package &Pkg, std::string Path = "");

  /**
   * @brief Remove the package from opened packages list.
   * 
   * @param uid UID of the package to remove.
   *
   * @warning This doesn't check if the package is opened in editors.
   */
  void ClosePackage(unsigned int uid);
  
  /**
   * @brief Remove the package from opened packages list.
   * 
   * @param Pkg Package to remove.
   * 
   * @warning This doesn't check if the package is opened in editors.
   */
  void ClosePackage(ResourceType::Package &Pkg);

  /**
   * @brief Create new package.
   *
   * @param Name Name of the package.
   */
  void CreatePackage(std::string Name = "Untitled");

  ResourceType::Package &FindPackage(unsigned int uid);
};
} // namespace Axum::Manager

/// Shortcut to the instance of PackageManager.
#define Package_Manager Axum::Manager::PackageManager::getInstance()

#endif //_PACKAGEMANAGER_H
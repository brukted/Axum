/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#ifndef _PREFERENCEMANAGER_H
#define _PREFERENCEMANAGER_H

#define PREF_FILE_NAME "preferences.json"

#include "Log.h"
#include "PathUtils.h"
#include "boost/property_tree/json_parser.hpp"
#include "boost/property_tree/ptree.hpp"
#include <exception>
#include <fmt/format.h>
#include <fstream>
#include <string>
#include <vector>

namespace pt = boost::property_tree;

namespace Axum::Manager {

class PreferenceManager {
public:
  static PreferenceManager &getInstance() {
    static PreferenceManager instance;
    return instance;
  }

private:
  pt::ptree tree;
  PreferenceManager(){};
  ~PreferenceManager(){};

public:
  std::string preferencesPath = fmt::format(
      "{}{}{}", Axum::Utils::PathUtils::userPathS, "/", PREF_FILE_NAME);

  PreferenceManager(PreferenceManager const &) = delete;

  void operator=(PreferenceManager const &) = delete;

  void Startup();

  void Shutdown();

  void save();

  void load();

  /**
   *@param path relative path to put the preference e.g: bakery.useGPU
   *@param value value of the prefence to put
   **/
  template <typename T> void putPreference(std::string path, T value) {
    this->tree.put(path, value);
  }
  /**
   *@param path relative path to put the preference e.g: 3dview.HDRIpaths
   *@param values values of the prefence to put
   **/
  template <typename T>
  void putPreferenceArray(std::string path, std::vector<T> values) {
    for (const std::string &name : values) {
      this->tree.add(path + ".item", name);
    }
  }
  /**
   *@param path relative path to put the preference e.g: bakery.useGPU
   *@param defaultValue value to return if the preference doesn't exist
   *@return value of the preference
   **/
  template <typename T> T getPreference(std::string path, T defaultValue) {
    return this->tree.get<T>(path, defaultValue);
  }
  /**
   * @brief Returns a preference at @a path. Returns zero sized vector if the
   *parameter doesn't exist.
   *
   *@param path relative path to put the preference e.g: 3dview.HDRIpaths
   *@return array of values of the preference.
   **/
  template <typename T> std::vector<T> getPreferenceArray(std::string path) {
    std::vector<T> values;
    for (pt::ptree::value_type &v : this->tree.get_child(path)) {
      values.insert(static_cast<T>(&v.second.data()));
    }
    return values;
  }
};

} // namespace Axum::Manager

/**
 * @brief Shortcut to the instance of PreferenceManager.
 * 
 */
#define Preference_Manager Axum::Manager::PreferenceManager::getInstance() 
#endif //_PREFERENCEMANAGER_H

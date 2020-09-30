/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#include "PreferenceManager.h"
#include "boost/lexical_cast.hpp"

/**
 * PreferenceManager implementation
 */

namespace Axum::Manager {

void PreferenceManager::Startup() {
  AX_LOG_EDITOR_INFO("Loading preferences from {}", preferencesPath)
  load();
}

void PreferenceManager::Shutdown() {
  save();
}

void PreferenceManager::save() {
  AX_LOG_EDITOR_INFO("Saving preferences to {}", preferencesPath)
  std::ofstream ofs{preferencesPath};
  pt::write_json(ofs, this->tree);
}

void PreferenceManager::load() {
  try {
    std::ifstream ifs{preferencesPath};
    pt::read_json(ifs, this->tree);
  }
  catch (boost::property_tree::json_parser_error e) {
    // TODO: Initialize ptree to default preferences as this will happen on the
    // very first run.
    AX_LOG_EDITOR_ERROR("Can't load preferences.\n {}",e.what())
    this->tree = pt::ptree();
  }
}

} // namespace Axum::Manager
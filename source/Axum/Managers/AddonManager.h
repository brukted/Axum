/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#ifndef _ADDON_MANAGER_H
#define _ADDON_MANAGER_H

#include "../Addon/Addon.h"
#include <vector>

namespace Addon = Axum::Addon;

namespace Axum::Manager {

class AddonManager {
public:
  static AddonManager &getInstance() {
    static AddonManager instance;
    return instance;
  }

private:
  AddonManager(){};

public:
  AddonManager(AddonManager const &) = delete;
  void operator=(AddonManager const &) = delete;

  std::vector<Addon::Addon> addons;

  void Startup();

  void Shutdown();

  void Refresh();
};
} // namespace Axum::Manager

/**
 * @brief Shortcut to the instance of AddonManager.
 *
 */
#define Addon_Manager Axum::Manager::AddonManager::getInstance()
#endif //_ADDON_MANAGER_H

/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#include "Package.h"

/**
 * Package implementation
 *
 * Easily Serializable Data Type containing all infos about the current session
 */

using namespace Axum::ResourceType;

/**
 * @param UUID
 * @return *Resource
 */
Resource &Package::GetResource(unsigned int _uid) {
  for (auto &var : this->Resources) {
    if (var.uid == _uid)
      return var;
  }
  AX_LOG_CORE_ERROR(
      "Package {0} is requested non-existenet resourece uid : {0:d}",
      name.GetValue(), _uid)
  throw "Resource doesn't exist";
}
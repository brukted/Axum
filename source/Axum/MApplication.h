/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#ifndef _MAPPLICATION_H
#define _MAPPLICATION_H

#include "Managers/AddonManager.h"
#include "Managers/PackageManager.h"
#include "Managers/PreferenceManager.h"
#include "Managers/RenderManager.h"
#include "Managers/UndoManager.h"
#include "Managers/WindowManager.h"

namespace Axum {

class MApplication{

public:
  MApplication();
  ~MApplication();
  void activate();
  int run();
};
} // namespace Axum

#endif //_MAPPLICATION_H

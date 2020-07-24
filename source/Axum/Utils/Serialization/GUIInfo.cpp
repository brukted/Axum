#include "GUIInfo.h"

namespace Axum::Utils {

GUIInfo::GUIInfo(float x, float y, bool _isHidden) {
  X = x;
  Y = y;
  isHidden = _isHidden;
}

} // namespace Axum::Utils
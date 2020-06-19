#include "GUIInfo.h"

using namespace Axum::Utils;

GUIInfo::GUIInfo() {}

GUIInfo::GUIInfo(float x, float y, bool _isHidden)
{
    X = x;
    Y = y;
    isHidden = _isHidden;
}
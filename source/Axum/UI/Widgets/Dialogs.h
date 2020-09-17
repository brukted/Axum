/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#ifndef __DIALOGS_H_
#define __DIALOGS_H_

#include <array>
#include <imgui.h>
#include <imgui_stdlib.h>
#include <string>
#include "Utils/Translation/Translation.h"

namespace Axum::UI::Widget {

bool newImageTextureDialog(std::string &name, int &width, int &height,
                           float *color);

} // namespace Axum::UI::Widget
#endif // __DIALOGS_H_
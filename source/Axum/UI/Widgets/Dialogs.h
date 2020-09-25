/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#ifndef __DIALOGS_H_
#define __DIALOGS_H_

#include "Utils/Log/Log.h"
#include "Utils/Translation/Translation.h"
#include <array>
#include <imgui.h>
#include <imgui_stdlib.h>
#include <nfd.h>
#include <string>


namespace Axum::UI::Widget {

bool newImageTextureDialog(std::string &name, int &width, int &height,
                           float *color);

enum class FileDialogMode { OPEN, SAVE, FOLDER };
bool nativeFileDialog(std::string &path, FileDialogMode mode,
                      std::string_view defaultPath = "",
                      std::string_view filters = "");

} // namespace Axum::UI::Widget
#endif // __DIALOGS_H_
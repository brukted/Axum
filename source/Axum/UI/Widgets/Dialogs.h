/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#ifndef __DIALOGS_H_
#define __DIALOGS_H_

#include <string>
#include <string_view>

namespace Axum{

    namespace  UI::Widget {

bool newImageTextureDialog(std::string *name, int *width, int *height,
                           float *color);

enum class FileDialogMode { OPEN, SAVE, FOLDER };
bool nativeFileDialog(std::string &path, FileDialogMode mode,
                      std::string_view defaultPath = "",
                      std::string_view filters = "");

bool importResourceDialog(std::string_view title, std::string &path,
                          bool *isLinked);

void createPackageDialog();
    }
} // namespace Axum::UI::Widget
#endif // __DIALOGS_H_
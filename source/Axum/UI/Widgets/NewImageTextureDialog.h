/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#ifndef __NEWIMAGETEXTUREDIALOG_H__
#define __NEWIMAGETEXTUREDIALOG_H__

#include <array>
#include <imgui.h>
#include <string>
#define _(text) text

namespace Axum::UI::Widget {

class NewImageTextureDialog {
private:
  int width;
  int height;
  std::array<unsigned char, 4> color;
  std::string name;

public:
  NewImageTextureDialog();
};

} // namespace Axum::UI::Widget
#endif // __NEWIMAGETEXTUREDIALOG_H__
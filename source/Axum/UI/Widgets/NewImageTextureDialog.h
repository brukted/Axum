/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#ifndef __NEWIMAGETEXTUREDIALOG_H__
#define __NEWIMAGETEXTUREDIALOG_H__

#include <gtkmm.h>
#include <string>
#include <array>
#define _(text) text

namespace Axum::UI::Widget {

class NewImageTextureDialog : public Gtk::Dialog {
private:
  int *width;
  int *height;
  std::array<unsigned char,4> *color;
  std::string *name;
public:
  NewImageTextureDialog(int *width,int *height,std::array<unsigned char,4> *color,std::string *name);
};

} // namespace Axum::UI::Widget
#endif // __NEWIMAGETEXTUREDIALOG_H__
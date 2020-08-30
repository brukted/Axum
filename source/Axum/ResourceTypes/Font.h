/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#ifndef _FONT_H
#define _FONT_H

#include "Resource.h"
namespace Axum {
namespace ResourceType {
class Font : public Resource {
public:
  Font();
  virtual void AppendToModel(Gtk::TreeIter row, Gtk::TreeStore *store) override;
};
} // namespace ResourceType
} // namespace Axum
#endif //_FONT_H

/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#ifndef _VECTORGRAPHICS_H
#define _VECTORGRAPHICS_H

#include "Resource.h"

namespace Axum {
namespace ResourceType {
class VectorGraphics : public Resource {
public:
  virtual void AppendToModel(Gtk::TreeIter row, Gtk::TreeStore *store) override;
};
} // namespace ResourceType
} // namespace Axum
#endif //_VECTORGRAPHICS_H

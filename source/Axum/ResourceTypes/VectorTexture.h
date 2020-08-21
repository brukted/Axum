/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#ifndef _VECTOR_TEXTURE_H
#define _VECTOR_TEXTURE_H

#include "Resource.h"

namespace Axum {
namespace ResourceType {
class VectorTexture : public Resource {
public:
  virtual void AppendToModel(Gtk::TreeIter row, Gtk::TreeStore *store) override;
};
} // namespace ResourceType
} // namespace Axum
#endif //_VECTOR_TEXTURE_H

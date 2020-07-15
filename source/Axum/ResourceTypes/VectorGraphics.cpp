/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#include "VectorGraphics.h"

/**
 * VectorGraphics implementation
 */

namespace Axum {
namespace ResourceType {
void VectorGraphics::AppendToModel(Gtk::TreeIter row, Gtk::TreeStore *store) {
    this->Resource::AppendToModel(row,store);
}
} // namespace ResourceType
} // namespace Axum
/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#include "VectorTexture.h"

/**
 * VectorTexture implementation
 */

namespace Axum {
namespace ResourceType {
void VectorTexture::AppendToModel(Gtk::TreeIter row, Gtk::TreeStore *store) {
    this->Resource::AppendToModel(row,store);
}
} // namespace ResourceType
} // namespace Axum
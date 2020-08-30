/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#include "Font.h"

/**
 * Font implementation
 */

namespace Axum {
namespace ResourceType {
Font::Font() { this->type = Type::Font; }

void Font::AppendToModel(Gtk::TreeIter row, Gtk::TreeStore *store) {
  this->Resource::AppendToModel(row, store);
}
} // namespace ResourceType
} // namespace Axum
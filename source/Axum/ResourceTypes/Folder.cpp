/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#include "Folder.h"

/**
 * Folder implementation
 */

namespace Axum {
namespace ResourceType {

void Folder::AddResource(Resource *resource) { Resources.push_back(resource); }

void Folder::RemoveResource(Resource *resource) {
  RemoveResource(resource->uid);
}

void Folder::RemoveResource(unsigned int _uid) {
  Resources.remove_if(
      [_uid](Resource *resource) { return _uid == resource->uid; });
}
void Folder::AppendToModel(Gtk::TreeIter row, Gtk::TreeStore *store) {
  this->Resource::AppendToModel(row, store);
  for (auto res : Resources) {
    // Creates and passes sub-row to each resources
    res->AppendToModel(store->append(row->children()), store);
  }
}
} // namespace ResourceType
} // namespace Axum
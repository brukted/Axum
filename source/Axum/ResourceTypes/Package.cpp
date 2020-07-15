/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#include "Package.h"

/**
 * Package implementation
 *
 * Easily Serializable Data Type containing all infos about the current session
 */

namespace Axum {
namespace ResourceType {
Package::Package() { root.name.SetValue("root"); }

void Package::AppendToModel(Gtk::TreeIter row, Gtk::TreeStore *store) {
  this->Resource::AppendToModel(row, store);
  for (auto &folder : root.GetSubFolders()) {
    folder.AppendToModel(store->append(row->children()), store);
  }
  for (auto res : root.GetResources()) {
    res->AppendToModel(store->append(row->children()), store);
  }
}

Resource &Package::FindResource(unsigned int _uid) {
  for (auto &var : Resources) {
    if (var.uid == _uid)
      return var;
  }
  AX_LOG_CORE_ERROR(
      "Package {0} is requested non-existenet resourece uid : {0:d}",
      name.GetValue(), _uid)
}

} // namespace ResourceType
} // namespace Axum
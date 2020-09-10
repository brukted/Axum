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
Folder &Folder::FindFolder(unsigned int _uid) {
  auto fol =
      std::find_if(SubFolders.begin(), SubFolders.end(),
                   [_uid](Folder &folder) { return _uid == folder.uid; });
  return *fol;
}

Folder::Folder() {
  name.SetValue(_("Untitled Folder"));
  type = Type::Folder;
}

void Folder::AddResource(Resource *resource) { Resources.push_back(resource); }

Folder &Folder::AddFolder(Folder folder) {
  SubFolders.push_back(std::move(folder));
  SubFolders.back().uid = ++LastUID;
  SubFolders.back().package = this->package;
  SubFolders.back().parent = this;
  return SubFolders.back();
}

Folder *Folder::RemoveResource(Resource &resource) {
  return RemoveResource(resource.uid);
}

Folder *Folder::RemoveResource(unsigned int _uid) {
  ///@brief The folder that was containing the resource.
  Folder *result = nullptr;
  auto InitalSize = Resources.size();
  Resources.remove_if(
      [_uid](Resource *resource) { return _uid == resource->uid; });
  /** TODO_cpp20 If the code base changed cpp standard to cpp20 use ElementCount
   returned by remove_if to check. */
  // Check if the resource was found and removed
  if ((InitalSize - Resources.size()) != 0)
    return this;
  // Move down the heirarchy and try to remove the resource
  for (auto &folder : SubFolders) {
    auto fol = folder.RemoveResource(_uid);
    // Check if the resource was already removed
    if (fol != nullptr && result != nullptr) {
      AX_LOG_CORE_WARN("A resource was found in multiple folders({},{}). This "
                       "should not happen.",
                       result->name.GetValue(), fol->name.GetValue())
      continue;
    }
    result = fol;
  }
  return result;
}

void Folder::AppendToModel(Gtk::TreeIter row, Gtk::TreeStore *store) {
  this->Resource::AppendToModel(row, store);
  for (auto res : Resources) {
    // Creates and passes sub-row to each resources
    res->AppendToModel(store->append(row->children()), store);
  }
  for (auto &folder : SubFolders) {
    // Creates and passes sub-row to each sub folders
    folder.AppendToModel(store->append(row->children()), store);
  }
}

void Folder::RemoveFolder(unsigned int _uid) {
  SubFolders.remove_if([_uid](Folder &folder) { return _uid == folder.uid; });
}

void Folder::RemoveFolder(Folder &folder) { RemoveFolder(folder.uid); }

} // namespace ResourceType
} // namespace Axum
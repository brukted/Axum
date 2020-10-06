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
  name.setValue(_("Untitled Folder"));
  type = Type::Folder;
}

void Folder::AddResource(Resource *resource) { Resources.push_back(resource); }

Folder &Folder::AddFolder(Folder folder) {
  SubFolders.emplace_back(std::move(folder));
  SubFolders.back().uid = ++LastUID;
  SubFolders.back().package = this->package;
  SubFolders.back().parent = this;
  return SubFolders.back();
}

Folder *Folder::RemoveResource(Resource &resource) {
  return RemoveResource(resource.uid);
}

Folder *Folder::RemoveResource(unsigned int _uid) {
  /// The folder that was containing the resource.
  Folder *Result = nullptr;
  auto it = std::find_if(
      Resources.begin(), Resources.end(),
      [_uid](Resource *resource) { return _uid == resource->uid; });
  if (it != Resources.end()) {
    Resources.erase(it);
    return this;
  }
  // Move down the heirarchy and try to remove the resource
  for (auto &folder : SubFolders) {
    auto fol = folder.RemoveResource(_uid);
    // Check if the resource was already removed
    if (fol != nullptr && Result != nullptr) {
      AX_LOG_CORE_WARN("A resource was found in multiple folders({},{}). This "
                       "should not happen.",
                       Result->name.getValue(), fol->name.getValue())
      continue;
    }
    Result = fol;
  }
  return Result;
}

void Folder::RemoveFolder(unsigned int _uid) {
  SubFolders.remove_if([_uid](Folder &folder) { return _uid == folder.uid; });
}

void Folder::RemoveFolder(Folder &folder) { RemoveFolder(folder.uid); }

} // namespace ResourceType
} // namespace Axum
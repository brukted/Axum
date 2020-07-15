/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#include "Resource.h"

/**
 * Resource implementation
 */

namespace Axum::ResourceType {

Resource::Resource(ResourceType _resourceType, const char *_path,
                   PathType _pathType) {
  resourceType = _resourceType;
  Path.assign(_path);
  pathType.SetValue(_pathType);
  attributes.AddParameter(&name);
  attributes.AddParameter(&description);
  attributes.AddParameter(&category);
  attributes.AddParameter(&label);
  attributes.AddParameter(&author);
  attributes.AddParameter(&authorUrl);
  attributes.AddParameter(&tags);
  attributes.AddParameter(&showInManager);
  attributes.AddParameter(&pathType);
  mParams.AddParameter(&attributes);
}

void Resource::Open() {}

void Resource::DrawExplorer(void *ui) {}

void Resource::makeAbsolute(std::string &pkgPath) {
  if (resourceType == ResourceType::Linked) {
    // get absolute path and set it to path
    boost::filesystem::path pkg(pkgPath);
    boost::filesystem::path currentPath(Path);
    auto absolute = boost::filesystem::absolute(currentPath, pkg.parent_path());
    Path.assign(absolute.string());
    // Set the path type in parameters to absolute
    pathType.SetValue(PathType::Absolute);
  }
}

void Resource::Reload() {}

void Resource::makeRelative(std::string &pkgPath) {
  if (resourceType == ResourceType::Linked) {
    // get relative path and set it to path
    boost::filesystem::path pkg(pkgPath);
    boost::filesystem::path currentPath(Path);
    auto relative = boost::filesystem::relative(currentPath, pkg.parent_path());
    Path.assign(relative.string());
    // Set the path type in parameters to relative
    pathType.SetValue(PathType::Relative);
  }
}
} // namespace Axum::ResourceType
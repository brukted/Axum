/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#include "Resource.h"
#include "UI/Editors/Outliner/Outliner.h"

/**
 * Resource implementation
 */

namespace Axum::ResourceType {
Resource::Resource() {}

void Resource::makeAbsolute(std::string &pkgPath) {
  if (isLinked) {
    // get absolute path and set it to path
    boost::filesystem::path pkg(pkgPath);
    boost::filesystem::path currentPath(Path);
    auto absolute = boost::filesystem::absolute(currentPath, pkg.parent_path());
    Path.assign(absolute.string());
    // Set the path type in parameters to absolute
    pathType.SetValue(PathType::Absolute);
  }
}

void Resource::makeRelative(std::string &pkgPath) {
  if (isLinked) {
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
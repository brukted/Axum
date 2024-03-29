/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#include "PackageManager.h"

/**
 * PackageManager implementation
 *
 */

namespace Axum::Manager {

void PackageManager::LoadPackage(std::string Path) {
  auto start = std::chrono::steady_clock::now();
  AX_LOG_EDITOR_INFO("Loading a package from {0}", Path)
  std::ifstream ifs(Path);
  if (ifs.good()) {
    try {
      boost::archive::text_iarchive ia(ifs);
      packages.emplace_back(0);
      ia >> packages.back();
      packages.back().Path = Path;
      packages.back().uid = ++LastUID;
    } catch (const boost::archive::archive_exception &e) {
      AX_LOG_EDITOR_ERROR(e.what())
      return;
    }
  } else {
    AX_LOG_EDITOR_WARN("Input file stream is bad maybe the file doesn't exist.")
    AX_LOG_EDITOR_WARN("Package loading failed.")
    return;
  }
  auto end = std::chrono::steady_clock::now();
  AX_LOG_EDITOR_INFO(
      "Loaded package \"{0}\" in {1:d} milliseconds",
      packages.back().name.getValue(),
      std::chrono::duration_cast<std::chrono::milliseconds>(end - start)
          .count())
}

void PackageManager::SavePackage(ResourceType::Package &pkg, std::string path) {
  auto start = std::chrono::steady_clock::now();
  AX_LOG_EDITOR_INFO("Saving package \"{}\" uid {} to {}", pkg.name.getValue(),
                     pkg.uid, path.c_str())
  if (path.size() == 0) {
    if (pkg.Path.size() != 0) {
      path = pkg.Path;
    } else {
      AX_LOG_EDITOR_WARN("Package has empty path and path is not provided. "
                         "Can't save the package.")
      return;
    }
  }
  std::ofstream ofs(path);
  if (ofs.bad()) {
    AX_LOG_EDITOR_WARN("Bad ofstream while trying to save package.")
    AX_LOG_EDITOR_WARN("Package saving failed")
    return;
  }
  boost::archive::text_oarchive oa(ofs);
  try {
    oa << pkg;
  } catch (const boost::archive::archive_exception &e) {
    AX_LOG_EDITOR_ERROR("Can't save the package {}", e.what())
    return;
  }
  pkg.Path = path;
  auto end = std::chrono::steady_clock::now();
  AX_LOG_EDITOR_INFO(
      "Saved package \"{0}\" uid {1} in : {2:d} milliseconds",
      pkg.name.getValue(), pkg.uid,
      std::chrono::duration_cast<std::chrono::milliseconds>(end - start)
          .count())
}

void PackageManager::ClosePackage(ResourceType::Package &Pkg) {
  ClosePackage(Pkg.uid);
}

void PackageManager::ClosePackage(unsigned int uid) {
  packages.remove_if(
      [uid](ResourceType::Package &Pkg) { return uid == Pkg.uid; });
}

void PackageManager::CreatePackage(std::string name) {
  packages.emplace_back(++LastUID, name);
}

ResourceType::Package &PackageManager::FindPackage(unsigned int uid) {
  for (auto &pkg : packages) {
    if (pkg.uid == uid) {
      return pkg;
    }
  }
  AX_LOG_CORE_CRITICAL("PackageManager: Can't find package with uid {0:d}", uid)
  throw std::runtime_error("Can't find the package");
}

void PackageManager::Startup() noexcept {}

void PackageManager::Shutdown() noexcept {}

} // namespace Axum::Manager
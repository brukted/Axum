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
  AX_LOG_EDITOR_INFO("Opening a package at {0}", Path)
  std::ifstream ifs(Path);
  if (ifs.good()) {
    try {
      boost::archive::text_iarchive ia(ifs);
      Packages.push_back(ResourceType::Package());
      ia >> Packages.back();
      Packages.back().Path.assign(Path);
      Packages.back().uid = ++LastUID;
    } catch (const std::exception &e) {
      AX_LOG_EDITOR_ERROR(e.what())
      return;
    }
  } else {
    AX_LOG_EDITOR_ERROR(
        "Input file stream is bad maybe the file doesn't exist.")
    throw "Bad input file stream";
    return;
  }
  auto end = std::chrono::steady_clock::now();
  AX_LOG_EDITOR_INFO(
      "Loaded package {0} in : {1:d} milliseconds",
      Packages.back().name.GetValue(),
      std::chrono::duration_cast<std::chrono::milliseconds>(end - start)
          .count())
}

void PackageManager::LoadPackage(const Glib::RefPtr<Gio::File> file) {
  LoadPackage(file->get_path());
}

void PackageManager::SavePackage(ResourceType::Package &pkg) {
  auto start = std::chrono::steady_clock::now();
  std::ofstream ofs(pkg.Path);
  boost::archive::text_oarchive oa(ofs);
  oa << pkg;
  auto end = std::chrono::steady_clock::now();
  AX_LOG_EDITOR_INFO(
      "Saved package {0} in : {1:d} milliseconds", pkg.name.GetValue(),
      std::chrono::duration_cast<std::chrono::milliseconds>(end - start)
          .count())
}

void PackageManager::CreatePackage(std::string _name) {
  Packages.push_back(ResourceType::Package());
  Packages.back().name.SetValue(_name);
  Packages.back().uid = ++LastUID;
}

ResourceType::Package &PackageManager::FindPackage(unsigned int uid) {
  for (auto &pkg : Packages) {
    if (pkg.uid == uid) {
      return pkg;
    }
  }
  AX_LOG_CORE_CRITICAL("PackageManager: Can't find package with uid {0:d}",uid)
}

void PackageManager::Startup() noexcept {}

void PackageManager::Shutdown() noexcept {}

} // namespace Axum::Manager
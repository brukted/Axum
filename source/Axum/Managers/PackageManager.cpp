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
      Packages.back().Path = Path;
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
      "Loaded package {0} in {1:d} milliseconds",
      Packages.back().name.GetValue(),
      std::chrono::duration_cast<std::chrono::milliseconds>(end - start)
          .count())
}

void PackageManager::LoadPackage(const Glib::RefPtr<Gio::File> file) {
  LoadPackage(file->get_path());
}

void PackageManager::SavePackage(ResourceType::Package &pkg, std::string Path) {
  auto start = std::chrono::steady_clock::now();
  std::string SaveLocation = "";
  if (Path == "") {
    if (pkg.Path != "") {
      SaveLocation = pkg.Path;
    } else {
      AX_LOG_EDITOR_WARN(
          "Package has no path and path is not provided. Can't save a package,")
      return;
    }
  } else {
    SaveLocation = Path;
  }
  std::ofstream ofs(SaveLocation);
  if (ofs.bad()) {
    AX_LOG_EDITOR_WARN("Bad ofstream whiletrying to save package.")
    return;
  }
  boost::archive::text_oarchive oa(ofs);
  oa << pkg;
  pkg.Path = SaveLocation;
  auto end = std::chrono::steady_clock::now();
  AX_LOG_EDITOR_INFO(
      "Saved package {0} in : {1:d} milliseconds", pkg.name.GetValue(),
      std::chrono::duration_cast<std::chrono::milliseconds>(end - start)
          .count())
}

void PackageManager::ClosePackage(ResourceType::Package &Pkg) {
  ClosePackage(Pkg.uid);
}

void PackageManager::ClosePackage(unsigned int uid) {
  Packages.remove_if(
      [uid](ResourceType::Package &Pkg) { return uid == Pkg.uid; });
}

void PackageManager::CreatePackage(std::string Name) {
  Packages.emplace_back(ResourceType::Package(++LastUID, Name));
}

ResourceType::Package &PackageManager::FindPackage(unsigned int uid) {
  for (auto &pkg : Packages) {
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
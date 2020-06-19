/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#include "PackageManager.h"

/**
 * PackageManager implementation
 *
 * ProjectManager holds the project that is currently opened and provides access
 * to it
 */

namespace Axum::Manager {

/**
 * @brief Loads the package and adds it to packages list.
 *
 * @param Path Path to the project file including the file name.
 */
void PackageManager::LoadPackage(std::string &Path) {
  auto start = std::chrono::steady_clock::now();
  AX_LOG_EDITOR_INFO("Opening a package at {0}", Path)
  std::ifstream ifs(Path);
  if (ifs.good()) {
    boost::archive::text_iarchive ia(ifs);
    mPackages.push_back(ResourceType::Package());
    ia >> mPackages.back();
    mPackages.back().setPath(Path.c_str());
  } else {
    AX_LOG_EDITOR_WARN("Input file stream is bad maybe the file doesn't exist.")
    throw "Bad input file stream";
    return;
  }
  auto end = std::chrono::steady_clock::now();
  AX_LOG_EDITOR_INFO(
      "Loaded package {0} in : {1:d} milliseconds",
      mPackages.back().name.GetValue(),
      std::chrono::duration_cast<std::chrono::milliseconds>(end - start)
          .count())
}

void PackageManager::LoadPackage(const Glib::RefPtr<Gio::File> &file) {
  auto start = std::chrono::steady_clock::now();
  AX_LOG_EDITOR_INFO("Opening a package at {0}", file->get_path())
  std::ifstream ifs(file->get_path().c_str());
  if (ifs.good()) {
    boost::archive::text_iarchive ia(ifs);
    mPackages.push_back(ResourceType::Package());
    ia >> mPackages.back();
    mPackages.back().setPath((file->get_path().c_str()));
  } else {
    AX_LOG_EDITOR_WARN("Input file stream is bad maybe the file doesn't exist.")
    throw "Bad input file stream";
    return;
  }
  auto end = std::chrono::steady_clock::now();
  AX_LOG_EDITOR_INFO(
      "Loaded package {0} in : {1:d} milliseconds",
      mPackages.back().name.GetValue(),
      std::chrono::duration_cast<std::chrono::milliseconds>(end - start)
          .count())
}

void PackageManager::SavePackage(ResourceType::Package &pkg) {
  auto start = std::chrono::steady_clock::now();
  std::ofstream ofs(pkg.mPath);
  boost::archive::text_oarchive oa(ofs);
  oa << pkg;
  auto end = std::chrono::steady_clock::now();
  AX_LOG_EDITOR_INFO(
      "Saved package {0} in : {1:d} milliseconds",
      mPackages.back().name.GetValue(),
      std::chrono::duration_cast<std::chrono::milliseconds>(end - start)
          .count())
}

void PackageManager::Startup() noexcept {}

void PackageManager::Shutdown() noexcept {}

} // namespace Axum::Manager
#include "PathUtils.h"

namespace Axum::Utils {

std::string PathUtils::excutablePath = std::string{};

std::string PathUtils::resourcesPath = std::string{};

std::string PathUtils::userPath = std::string{};

std::string PathUtils::userPathS = std::string{};

std::string PathUtils::LogDirectory = std::string{};

void PathUtils::getPaths(char *argv0) {
  excutablePath = boost::filesystem::canonical(argv0).string();
#ifdef _WIN32
  boost::filesystem::path excutable{excutablePath};
  resourcesPath = excutable.parent_path().string() + "\\data";
  TCHAR pf[MAX_PATH];
  SHGetSpecialFolderPath(0, pf, CSIDL_LOCAL_APPDATA, FALSE);
  userPath.append(pf);
  userPath.append("\\Axum\\" AXUM_VERSION_MAJOR
                  "." AXUM_VERSION_MINOR AXUM_VERSION_PATCH);
  TCHAR xf[MAX_PATH];
  SHGetSpecialFolderPath(0, xf, CSIDL_APPDATA, FALSE);
  userPathS.append(xf);
  userPathS.append("\\Axum\\" AXUM_VERSION_MAJOR
                   "." AXUM_VERSION_MINOR AXUM_VERSION_PATCH);
  LogDirectory = userPath + "\\logs";
#endif // _WIN32

// TODO: implement for macos and linux
#ifdef APPLE

#else
// Linux variants
#ifdef UNIX

#endif // UNIX
#endif // APPLE
  boost::filesystem::path p(userPathS);
  if (!(boost::filesystem::exists(p.parent_path())))
    boost::filesystem::create_directory(p.parent_path());
  if (!(boost::filesystem::exists(p)))
    boost::filesystem::create_directory(p);
}

} // namespace Axum::Utils
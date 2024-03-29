#ifndef __PATHUTILS_H__
#define __PATHUTILS_H__

#include "Axum/Axum-version.h"
#include <boost/filesystem.hpp>
#include <string>

#ifdef _WIN32
#include <shlobj.h>
#include <windows.h>
#endif // _WIN32

namespace Axum {
namespace Utils {

/**
 * @brief PathUtils Contains various utilities used to get different paths at
 * runtime like user specific path resources path.
 *
 */

class PathUtils {
public:
  /// @brief Path to the executable.
  static std::string excutablePath;

  /// @brief Path to the executable directory.
  static std::string excutableDir;

  /**
   * @brief Path to the default global resources. On windows it's
   * @excutablePath/../resources
   */
  static std::string systemResourcesPath;

  /**
   * @brief Path to the user resources. On windows it's
   * @excutablePath/../resources
   */
  static std::string resourcesPath;

  /**
   * @brief Local user specific path of the application. On windows it's
   * %APPDATA%/local/Axum/version .
   */
  static std::string userPath;

  /**
   * @brief Synced user specific path of the application. On windows it's
   * %APPDATA%/roaming/Axum/version .
   */
  static std::string userPathS;

  /**
   * @brief Path to the logs directory to store log files in release builds. On
   * windows it's @a userPath/Logs .
   *
   */
  static std::string LogDirectory;

  /**
   * @brief Constructs all paths on platform dependent manner
   *
   * @param argv0 path of the excutable including filename and extansion
   */
  static void getPaths(char *argv0);
};
} // namespace Utils
} // namespace Axum
#endif // __PATHUTILS_H__
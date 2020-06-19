#ifndef __PATHUTILS_H__
#define __PATHUTILS_H__

#include <string>
#include <boost/filesystem.hpp>
#include "Axum/Axum-version.h"

#ifdef _WIN32
#include <windows.h>
#include <shlobj.h>
#endif // _WIN32

namespace Axum
{
  namespace Utils
  {

    /**
    *@class Path utils contains various utilities used to get different paths at runtime like user specific path 
    *resources path.    
    **/

    class PathUtils
    {
    public:
      /**
      * @brief Path to the executable.
      * 
      */
      static std::string excutablePath;
      /**
      * @brief Path to the default resources. On windows it's @excutablePath/../resources
      * 
      */
      static std::string resourcesPath;
      /**
      * @brief Local user specific path of the application. On windows it's %APPDATA%/local/Axum/version .
      * 
      */
      static std::string userPath;

      /**
      * @brief Synced user specific path of the application. On windows it's %APPDATA%/roaming/Axum/version .
      * 
      */
      static std::string userPathS;

      /**
      * @brief Path to the logs directory to store log files in release builds. On windows it's @a userPath/Logs .
      * 
      */
      static std::string LogDirectory;

      /**
      * @brief Constructs all paths on platform dependent manner
      * 
      * @param argv0 path of the excutable includeing filename and extansion
      */
      static void getPaths(char *argv0);
    };
  } // namespace Utils
} // namespace Axum
#endif // __PATHUTILS_H__
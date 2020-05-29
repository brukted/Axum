#ifndef __PATHUTILS_H__
#define __PATHUTILS_H__

#include <string>
#include <boost/filesystem.hpp>
#include "Axum/Axum-version.h"

#ifdef WIN32
#include <windows.h>
#include <shlobj.h>
#endif // WIN32

/**
 *@file Path utils contains various utilities used to get different paths at runtime like user specific path 
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
 * @brief Path to the default resources
 * 
 */
  static std::string resourcesPath;
  /**
 * @brief Local user specific path of the application 
 * 
 */
  static std::string userPath;

  /**
 * @brief Synced user specific path of the application 
 * 
 */
  static std::string userPathS;

  /**
 * @brief Constructs all paths on platform dependent manner
 * 
 * @param argv0 path of the excutable includeing filename and extansion
 */
  static void getPaths(char *argv0);
};
#endif // __PATHUTILS_H__
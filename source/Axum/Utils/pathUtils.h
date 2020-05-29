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
static void getPaths(char *argv0)
{
    excutablePath = boost::filesystem::canonical(argv0).string();
#ifdef WIN32
    boost::filesystem::path excutable{excutablePath};
    resourcesPath = excutable.parent_path().string() + "\\data";
    TCHAR pf[MAX_PATH];
    SHGetSpecialFolderPath(0, pf, CSIDL_LOCAL_APPDATA, FALSE);
    userPath.append(pf);
    userPath.append("\\Axum\\" AXUM_VERSION_MAJOR "." AXUM_VERSION_MINOR AXUM_VERSION_PATCH);
    TCHAR xf[MAX_PATH];
    SHGetSpecialFolderPath(0, xf, CSIDL_APPDATA, FALSE);
    userPathS.append(xf);
    userPathS.append("\\Axum\\" AXUM_VERSION_MAJOR "." AXUM_VERSION_MINOR AXUM_VERSION_PATCH);
#endif // WIN32

//TODO: implement for macos and linux
#ifdef APPLE

#else
//Linux variants
#ifdef UNIX

#endif // UNIX
#endif // APPLE
}

#endif // __PATHUTILS_H__
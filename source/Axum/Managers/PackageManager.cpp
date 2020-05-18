/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#include "PackageManager.h"

/**
 * PackageManager implementation
 * 
 * ProjectManager holds the project that is currently opened and provides access to it
 */

/**
 * @brief Loads the package and adds it to packages list.
 * 
 * @param Path Path to the project file including the file name.
 */
void PackageManager::LoadPackage(std::string &Path)
{
    auto p = boost::filesystem::path(Path);
    if (boost::filesystem::exists(p))
    {
        std::ofstream ofs(Path);
        boost::archive::text_oarchive oa(ofs);
        mPackages.push_back(Package());
        oa << mPackages.back();
        mPackages.back().setPath(Path.c_str());
    }
    else
    {
        AX_LOG_EDITOR_WARN("Tried to open a file that doesn't exist.")
        std::__throw_runtime_error("File doesn't exist.");
    }
}

void PackageManager::LoadPackage(const Glib::RefPtr<Gio::File> &file)
{
    if (file->query_exists())
    {
        // open the archive
        std::ifstream ifs(file->get_path().c_str());
        assert(ifs.good());
        boost::archive::text_iarchive ia(ifs);
        mPackages.push_back(Package());
        ia >> mPackages.back();
        mPackages.back().setPath((file->get_path().c_str()));
    }
    else
    {
        AX_LOG_EDITOR_WARN("Tried to open file that doesn't exist.")
        std::__throw_runtime_error("File doesn't exist.");
    }
}

void PackageManager::SavePackage(Package &pkg)
{
    std::ofstream ofs(pkg.mPath);
    boost::archive::text_oarchive oa(ofs);
    oa << pkg;
}

void PackageManager::Startup() noexcept
{
}

void PackageManager::Shutdown() noexcept
{
}
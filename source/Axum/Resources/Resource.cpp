/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#include "Resource.h"

/**
 * Resource implementation
 */

Resource::Resource()
{
    attributes.AddParameter(&name);
    attributes.AddParameter(&description);
    attributes.AddParameter(&category);
    attributes.AddParameter(&label);
    attributes.AddParameter(&author);
    attributes.AddParameter(&authorUrl);
    attributes.AddParameter(&tags);
    attributes.AddParameter(&showInManager);
    attributes.AddParameter(&pathType);
    mParams.AddParameter(&attributes);
}

/**
 * Opens the resource in the appropriate editor.
 */
void Resource::Open()
{
}

/**
 * Returns a UI to display the resource the UI is an instance odf ExplorerItemUI or child of it.
 * 
 * @return ExplorerItemUI
 */
ExplorerItemUI Resource::GetUI()
{
    return ExplorerItemUI();
}
void Resource::makeAbsolute(std::string &pkgPath)
{
    if (mType == ResourceType::Linked)
    {

        //get absolute path and set it to path
        boost::filesystem::path pkg(pkgPath);
        boost::filesystem::path currentPath(mPath);
        auto absolute = boost::filesystem::absolute(currentPath, pkg.parent_path());
        mPath.assign(absolute.string());
        //Set the path type in parameters to absolute
        pathType.SetValue(PathType::Absolute);
    }
}

void Resource::makeRelative(std::string &pkgPath)
{
    if (mType == ResourceType::Linked)
    {
        //get relative path and set it to path
        boost::filesystem::path pkg(pkgPath);
        boost::filesystem::path currentPath(mPath);
        auto relative = boost::filesystem::relative(currentPath, pkg.parent_path());
        mPath.assign(relative.string());
        //Set the path type in parameters to relative
        pathType.SetValue(PathType::Relative);
    }
}

void Resource::setPath(char const *path)
{
    mPath.assign(path);
}
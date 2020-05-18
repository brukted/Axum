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
    ParamCollection resourceParams(mParams.GenerateUid());
    resourceParams.setName("Resource");

    TextParam name(mParams.GenerateUid());
    name.setName("Name");
    name.setValue("unknown");

    auto pathTypes = std::map<int, std::string>();
    pathTypes.insert(std::make_pair(PathType::Relative, "Relative"));
    pathTypes.insert(std::make_pair(PathType::Absolute, "Absolute"));
    EnumParam pathType(std::move(pathTypes), mParams.GenerateUid());
    pathType.setName("Path type");

    resourceParams.AddParameter(std::move(name));
    resourceParams.AddParameter(std::move(pathType));

    mParams.AddParameter(std::move(resourceParams));
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
    //TODO:
    return ExplorerItemUI();
}
void Resource::makeAbsolute(std::string &pkgPath)
{
    if (mType == ResourceType::Linked)
    {
        //Set the path type in parameters to absolute
        auto resource_param = static_cast<ParamCollection &>(mParams.GetParameter("Resource"));
        auto pathType = static_cast<EnumParam &>(resource_param.GetParameter(""));
        pathType.SetValue(PathType::Absolute);
        //get absolute path and set it to path
        boost::filesystem::path pkg(pkgPath);
        boost::filesystem::path currentPath(mPath);
        auto absolute = boost::filesystem::absolute(currentPath, pkg.parent_path());
        mPath.assign(absolute.string());
    }
}

void Resource::makeRelative(std::string &pkgPath)
{
    if (mType == ResourceType::Linked)
    {
        //Set the path type in parameters to relative
        auto resource_param = static_cast<ParamCollection &>(mParams.GetParameter("Resource"));
        auto pathType = static_cast<EnumParam &>(resource_param.GetParameter(""));
        pathType.SetValue(PathType::Relative);
        //get relative path and set it to path
        boost::filesystem::path pkg(pkgPath);
        boost::filesystem::path currentPath(mPath);
        auto relative = boost::filesystem::relative(currentPath, pkg.parent_path());
        mPath.assign(relative.string());
    }
}

void Resource::setPath(char const *path)
{
    auto resource_param = static_cast<ParamCollection &>(mParams.GetParameter("Resource"));
    auto pathType = static_cast<EnumParam &>(resource_param.GetParameter(""));
    mPath.assign(path);
}
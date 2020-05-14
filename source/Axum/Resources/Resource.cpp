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
    ParamCollection resourceParams;
    resourceParams.setName("Resource");
    TextParam name;
    name.setName("Name");
    name.setValue("unknown");
    resourceParams.AddParameter(std::move(name));
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
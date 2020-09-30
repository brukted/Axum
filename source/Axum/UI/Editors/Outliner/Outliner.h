/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#ifndef _OUTLINER_H
#define _OUTLINER_H

#include "../Editor.h"
#include "../MaterialEditor/MaterialEditor.h"
#include "../ParameterEditor/ParameterEditor.h"
#include "Managers/PackageManager.h"
#include "ResourceTypes/Resource.h"
#include "UI/Widgets/Dialogs.h"
#include "Utils/Log/Log.h"
#include "Utils/Translation/Translation.h"
#include <boost/filesystem.hpp>
#include <string>
#include <vector>


namespace Axum::UI {
namespace Editor {

class Outliner : public Editor {
  void openPackage();

  /**
   * @brief Draws conntext menu for  @a resource
   *
   * @param resource
   * @return true resource has been deleted
   * @return false resource exists.
   */
  bool showRowContextMenu(ResourceType::Resource *resource);

  void mainContextMenu();

  void openResource(ResourceType::Resource *resource);

public:
  Outliner();

  void draw() override;
};

} // namespace Editor
} // namespace Axum::UI

#endif //_OUTLINER_UI_H
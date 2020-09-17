/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#ifndef _OUTLINER_H
#define _OUTLINER_H

#include "../Editor.h"
#include "../ParameterEditor/ParameterEditor.h"
#include "Managers/PackageManager.h"
#include "ResourceTypes/Resource.h"
#include "UI/Widgets/Dialogs.h"
#include "Utils/Log/Log.h"
#include <string>
#include <vector>
#include "Utils/Translation/Translation.h"

namespace Axum::UI {
namespace Editor {

class Outliner : public Editor {
public:
  Outliner();

  void draw() override;

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
};

} // namespace Editor
} // namespace Axum::UI

#endif //_OUTLINER_UI_H
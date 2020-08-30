/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#ifndef __OUTLINER_CONTEXT_MENU_H__
#define __OUTLINER_CONTEXT_MENU_H__

#include "Managers/PackageManager.h"
#include "Managers/UndoManager.h"
#include "Managers/WindowManager.h"
#include "NodeGraph/LogicGraph.h"
#include "NodeGraph/MaterialGraph.h"
#include "ResourceTypes/Folder.h"
#include "ResourceTypes/Font.h"
#include "ResourceTypes/ImageTexture.h"
#include "ResourceTypes/Package.h"
#include "ResourceTypes/Resource.h"
#include "ResourceTypes/Scene.h"
#include "ResourceTypes/VectorTexture.h"
#include "UI/Widgets/NewImageTextureDialog.h"
#include <gtkmm.h>
#define _(text) text
#include "Log.h"
#include <boost/filesystem.hpp>
#include <memory>
#include <string>
#include <typeinfo>

namespace Axum::UI::Widget {
class OutlinerContextMenu : public Gtk::Menu {
public:
  OutlinerContextMenu(){};
  OutlinerContextMenu(ResourceType::Folder *folder);
  OutlinerContextMenu(ResourceType::Package *package);
  OutlinerContextMenu(ResourceType::Font *font);
  OutlinerContextMenu(ResourceType::Scene *scene);
  OutlinerContextMenu(ResourceType::ImageTexture *texture);
  OutlinerContextMenu(ResourceType::VectorTexture *texture);
  OutlinerContextMenu(NodeGraph::Material::MaterialGraph *graph);
  OutlinerContextMenu(NodeGraph::Logic::LogicGraph *graph);
};
} // namespace Axum::UI::Widget
#endif // __OUTLINER_CONTEXT_MENU_H__
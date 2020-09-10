/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#ifndef _ASSET_MANAGER_H_
#define _ASSET_MANAGER_H_

#include "../Editor.h"
#include "Log.h"
#include "PathUtils.h"
#include <boost/algorithm/string.hpp>
#include <filesystem>
#include <string>

namespace Axum::UI {
namespace Editor {

class AssetItem {
public:
  enum class Type {
    FONT,
    DIRECTORY,
    IMAGE_TEXTURE,
    VECTOR_GRAPHICS,
    SCENE,
    PACKAGE
  };

  AssetItem::Type type;
  /**
   * @brief Name of the asset to display on the UI
   *
   */
  std::string name{"name"};
  /**
   * @brief Path to the asset including filename and extension.
   *
   */
  std::string path;
  std::array<unsigned char, 32 * 32> *thumbnail = nullptr;
  std::vector<AssetItem> children;

  AssetItem(AssetItem::Type _type, std::string _name, std::string _path)
      : type(_type), name(_name), path(_path) {}

  ~AssetItem() {
    if (thumbnail != nullptr)
      delete thumbnail;
  }
};

class ThumbnailBuilder {
public:
  /**
   * @brief Rebuilds thumbnail for all asset items.
   *
   * @param _root root of the asset items. Should be directory type.
   *
   */
  static void RebuildCache(AssetItem &_root);

  /**
   * @brief Builds the thumbnail for the item. This is a blocking
   * call. Fork a thread if you want to make it non-blocking.
   *
   * @param item Item to build thumbnail for. Should be non-directory type.
   */
  static void GetThumbnail(AssetItem &item);
};

class AssetManager : public Editor {
public:
  std::string assetsPath = Utils::PathUtils::resourcesPath + std::string{"/assets"};

  AssetItem root{AssetItem::Type::DIRECTORY, std::string{"Catagories"},
                 assetsPath};

  /**
   * @brief Refresh the asset library. This is a blocking call.
   *
   */
  void reload();

  /**
   * @brief Recursively searchs all assets in the @a parent and adds them to it.
   *
   * @param parent Directory to search assets in.
   */
  void discoverAssets(AssetItem &parent);
};

} // namespace Editor
} // namespace Axum::UI
#endif //_ASSET_MANAGER_H_

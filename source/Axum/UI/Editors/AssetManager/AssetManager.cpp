/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#include "AssetManager.h"

/**
 * AssetManager implementation
 */

namespace Axum::UI::Editor {

void ThumbnailBuilder::RebuildCache(AssetItem &_root) {
  auto start = std::chrono::steady_clock::now();
  AX_LOG_EDITOR_INFO("Started rebuilding thumbnail cache.")
  // TODO:Implement thumbnail rebuild cache
  auto end = std::chrono::steady_clock::now();
  AX_LOG_EDITOR_INFO(
      "Finished rebuilding thumbnail cache in : {1:d} seconds.",
      std::chrono::duration_cast<std::chrono::seconds>(end - start).count())
}

void ThumbnailBuilder::GetThumbnail(AssetItem &item) {
  // TODO:Implement thumbnail builder
}

void AssetManager::reload() {
  auto start = std::chrono::steady_clock::now();
  AX_LOG_EDITOR_INFO("Reloading assets.")
  root = AssetItem(AssetItem::Type::DIRECTORY, std::string{"Catagories"},
                   assetsPath);
  discoverAssets(root);
  auto end = std::chrono::steady_clock::now();
  AX_LOG_EDITOR_INFO(
      "Finished reloading assets in : {1:d} seconds.",
      std::chrono::duration_cast<std::chrono::seconds>(end - start).count())
}

// TODO: remove extension from name
void AssetManager::discoverAssets(AssetItem &parent) {
  AX_LOG_EDITOR_INFO("Discovering assets in {}", parent.path)
  for (auto &p : std::filesystem::directory_iterator(parent.path)) {
    if (p.is_directory()) {
      parent.children.push_back(AssetItem(AssetItem::Type::DIRECTORY,
                                          p.path().filename().string(),
                                          p.path().string()));
      discoverAssets(*(parent.children.end()));
    } else if (p.is_regular_file()) {
      std::string extension = p.path().extension().string();
      boost::to_lower(extension);
      if (extension.compare(".axpkg")) {
        parent.children.push_back(AssetItem(AssetItem::Type::PACKAGE,
                                            p.path().filename().string(),
                                            p.path().string()));
      } else if (extension.compare(".svg")) {
        parent.children.push_back(AssetItem(AssetItem::Type::VECTOR_GRAPHICS,
                                            p.path().filename().string(),
                                            p.path().string()));
      } else if (extension.compare(".obj") | extension.compare(".fbx")) {
        parent.children.push_back(AssetItem(AssetItem::Type::SCENE,
                                            p.path().filename().string(),
                                            p.path().string()));
      } else if (extension.compare(".jpeg") | extension.compare(".png") |
                 extension.compare(".jpg") | extension.compare(".tif") |
                 extension.compare(".tiff")) {
        parent.children.push_back(AssetItem(AssetItem::Type::IMAGE_TEXTURE,
                                            p.path().filename().string(),
                                            p.path().string()));
      } else {
        AX_LOG_EDITOR_WARN("Unknown asset file type with extension {}.",
                           extension)
      }
    }
  }
}

} // namespace Axum::UI::Editor
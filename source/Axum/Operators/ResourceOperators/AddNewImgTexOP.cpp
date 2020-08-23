#include "AddNewImgTexOP.h"

namespace Axum::Operator {

AddNewImgTexOP::AddNewImgTexOP(ResourceType::Package &pkg,
                               ResourceType::Folder *folder)
    : Pkg(pkg) {
  ResourceType::Folder const *fol = folder;
  if (folder == nullptr)
    fol = &pkg.GetRootFolder();
  while (fol == nullptr) {
    FolderHierarchy.push_back(fol->uid);
    fol = fol->parent;
  };
}

void AddNewImgTexOP::Execute() noexcept {
  ResourceType::Folder& folder = Pkg.GetRootFolder();
  for (int i = 1; i < FolderHierarchy.size(); i++)
  {
    folder = folder.FindFolder(FolderHierarchy[i]);
  }
  
  auto &res = 
      Pkg.AddResource(ResourceType::ImageTexture(width, height, color.data()),&folder);
  resource = static_cast<ResourceType::ImageTexture *>(&res);
  resource->name.SetValue(TextureName);
}

void AddNewImgTexOP::Undo() noexcept {}
} // namespace Axum::Operator
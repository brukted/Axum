/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#ifndef __ADD_NEW_TEX_OP_H__
#define __ADD_NEW_TEX_OP_H__

#include "../Operator.h"
#include "Managers/PackageManager.h"
#include "ResourceTypes/Folder.h"
#include "ResourceTypes/ImageTexture.h"
#include "ResourceTypes/Package.h"
#include <array>
#define _(text) text

namespace Axum::Operator {

class AddNewImgTexOP : public Operator::Operator {
private:
  ResourceType::Package &Pkg;
  std::vector<unsigned int> FolderHierarchy;
  ResourceType::ImageTexture *resource;

public:
  int width = 1;
  int height = 1;
  std::array<unsigned char, 4> color;
  std::string TextureName;
  std::string UIName = _("Add texture");
  std::string Name = _("NEW_TEXTURE_OP");

  /**
   * @brief Construct a new Add New Resource Operator.
   *
   * @param resource resource to add to the pkg.
   * @param pkg
   * @param folder
   */
  AddNewImgTexOP(ResourceType::Package &pkg, ResourceType::Folder *folder = nullptr);
  virtual void Execute() noexcept override;
  virtual void Undo() noexcept override;
};

} // namespace Axum::Operator

#endif // __ADD_NEW_TEX_OP_H__

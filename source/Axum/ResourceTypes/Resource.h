/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#ifndef _RESOURCE_H
#define _RESOURCE_H

#include "../Parameter/BooleanParam.h"
#include "../Parameter/EnumParam.h"
#include "../Parameter/ParamCollection.h"
#include "../Parameter/TextParam.h"
#include "boost/serialization/access.hpp"
#include "boost/serialization/split_member.hpp"
#include "boost/serialization/string.hpp"
#include "boost/serialization/vector.hpp"
#include "boost/serialization/version.hpp"
#include <boost/filesystem.hpp>
#include <string>

using namespace Axum::Parameter;

namespace Axum {
namespace ResourceType {
class Resource {
  friend class boost::serialization::access;

public:
  enum ResourceType { Linked, Embedded };
  enum PathType { Relative, Absolute };

  /**
   * @brief Construct a new Resource object
   *
   * @param _resourceType type of the resource embedded or linked deafult is
   * embedded
   * @param _path path to the resource if linked
   * @param _pathType path type of the resource if linked
   */
  Resource(ResourceType _resourceType = ResourceType::Embedded,
           const char *_path = "", PathType _pathType = PathType::Absolute);

  ResourceType resourceType;
  unsigned int uid;

  /**
   * @brief Location of the resource including the filename and extension,if it
   * is linked type.
   *
   */
  std::string Path;
  ParamCollection mParams;
  ParamCollection attributes{mParams.GenerateUid(), "Attributes"};
  TextParam name{attributes.GenerateUid(), "Name", "Untitled"};
  TextParam description{attributes.GenerateUid(), "Description", ""};
  TextParam category{attributes.GenerateUid(), "Category", ""};
  TextParam label{attributes.GenerateUid(), "Label", ""};
  TextParam author{attributes.GenerateUid(), "Author", ""};
  TextParam authorUrl{attributes.GenerateUid(), "Author URL", ""};
  TextParam tags{attributes.GenerateUid(), "Tags", ""};
  BooleanParam showInManager{attributes.GenerateUid(), "Show in asset manager",
                             true};
  EnumParam pathType{
      attributes.GenerateUid(), "Path type",
      std::map<int, std::string>{{PathType::Relative, "Relative"},
                                 {PathType::Absolute, "Absolute"}},
      PathType::Absolute};

  /**
   * @brief Opens the resource in the appropriate editor.
   */
  virtual void Open();

  /**
   * @brief Draws in the explorer window.
   *
   * @param ui Pointer to the ui to draw to.
   */
  void DrawExplorer(void *ui);

  void setPath(char const *);

  /**
   * @brief Makes the path type to relative and the path relative to @a pkgPath.
   * This method has no effect if the resource is embedded.
   *
   * @param pkgPath Absolute path of the package this resource is located
   */
  void makeRelative(std::string &pkgPath);

  /** @brief Makes the path type to absolute and the path absolute to @a
   * pkgPath. This method has no effect if the resource is embedded.
   *
   * @param pkgPath Absolute path of the package this resource is located
   */
  void makeAbsolute(std::string &pkgPath);

  /**
   * @brief Reloads the resource if linked type
   *
   */
  void virtual Reload();

private:
  template <class Archive>
  void save(Archive &ar, const unsigned int version) const {
    ar &resourceType, &uid, &Path, &name, &description, &category, &label,
        &author, &authorUrl, &tags, &showInManager, &pathType;
    ar &mParams, &attributes;
  }

  template <class Archive> void load(Archive &ar, const unsigned int version) {
    ar &resourceType, &uid, &Path, &name, &description, &category, &label,
        &author, &authorUrl, &tags, &showInManager, &pathType;
    ar &mParams, &attributes;
  }
  BOOST_SERIALIZATION_SPLIT_MEMBER()
};
} // namespace ResourceType
} // namespace Axum
BOOST_CLASS_VERSION(Axum::ResourceType::Resource, 1)
#endif //_RESOURCE_H

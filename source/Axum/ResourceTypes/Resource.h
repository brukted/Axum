/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#ifndef _RESOURCE_H
#define _RESOURCE_H

#include "Parameter/Parameter.h"
#include <boost/filesystem.hpp>
#include <boost/serialization/access.hpp>
#include <boost/serialization/split_member.hpp>
#include <boost/serialization/string.hpp>
#include <boost/serialization/vector.hpp>
#include <boost/serialization/version.hpp>
#include <string>
#define _(text) text

namespace Axum {
namespace ResourceType {
class Package;

// @TODO Remove AppendToModel from resource and write it in outliner to remove
// ui logic from the model
class Resource {
  friend class boost::serialization::access;

public:
  enum class Type {
    Generic,
    Folder,
    Font,
    ImageTexture,
    Package,
    Scene,
    VectorTexture,
    MaterialGraph,
    LogicGraph
  };
  enum PathType { Relative, Absolute};

  unsigned int uid = 0;
  bool isLinked = false;
  Type type = Type::Generic;
  Package *package = nullptr;

  /**
   * @brief Location of the resource including the filename and extension,if it
   * is linked type.
   *
   */
  std::string Path;
  Parameter::TextParam name{"RESOURCE_ATTRIBUTES_NAME", _("Name"),
                            _("Untitled Resource")};
  Parameter::TextParam description{"RESOURCE_ATTRIBUTES_DESCRIPTION",
                                   _("Description"), ""};
  Parameter::TextParam category{"RESOURCE_ATTRIBUTES_CATEGORY", _("Category"),
                                ""};
  Parameter::TextParam label{"RESOURCE_ATTRIBUTES_LABEL", _("Label"), ""};
  Parameter::TextParam author{"RESOURCE_ATTRIBUTES_AUTHOR", _("Author"), ""};
  Parameter::TextParam authorUrl{"RESOURCE_ATTRIBUTES_URL", _("Author URL"),
                                 ""};
  Parameter::TextParam tags{"RESOURCE_ATTRIBUTES_TAGS", _("Tags"), ""};
  Parameter::BooleanParam showInManager{"RESOURCE_ATTRIBUTES_SHOW_IN_MANAGER",
                                        _("Show in asset manager"), true};
  Parameter::EnumParam pathType{
      "RESOURCE_ATTRIBUTES_PATH_TYPE", _("Path type"),
      std::map<int, std::string>{{(int)PathType::Relative, _("Relative")},
                                 {(int)PathType::Absolute, _("Absolute")}},
      PathType::Absolute};

  Resource();

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

  LIST_PARAMETERS(&name, &description, &category, &label, &author, &authorUrl,
                  &pathType, &showInManager)

private:
  template <class Archive>
  void save(Archive &ar, const unsigned int version) const {
    ar &isLinked &uid &Path &name &description &category &label &author
        &authorUrl &tags &showInManager &pathType;
  }

  template <class Archive> void load(Archive &ar, const unsigned int version) {
    ar &isLinked &uid &Path &name &description &category &label &author
        &authorUrl &tags &showInManager &pathType;
  }
  BOOST_SERIALIZATION_SPLIT_MEMBER()
};
} // namespace ResourceType
} // namespace Axum
BOOST_CLASS_VERSION(Axum::ResourceType::Resource, 1)
#endif //_RESOURCE_H

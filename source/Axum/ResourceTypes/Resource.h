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
#include <boost/filesystem.hpp>
#include <boost/serialization/access.hpp>
#include <boost/serialization/split_member.hpp>
#include <boost/serialization/string.hpp>
#include <boost/serialization/vector.hpp>
#include <boost/serialization/version.hpp>
#include <gtkmm.h>
#include <string>


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
  Parameter::ParamCollection mParams;
  Parameter::ParamCollection attributes{mParams.GenerateUid(), "Attributes"};
  Parameter::TextParam name{attributes.GenerateUid(), "Name", "Untitled"};
  Parameter::TextParam description{attributes.GenerateUid(), "Description", ""};
  Parameter::TextParam category{attributes.GenerateUid(), "Category", ""};
  Parameter::TextParam label{attributes.GenerateUid(), "Label", ""};
  Parameter::TextParam author{attributes.GenerateUid(), "Author", ""};
  Parameter::TextParam authorUrl{attributes.GenerateUid(), "Author URL", ""};
  Parameter::TextParam tags{attributes.GenerateUid(), "Tags", ""};
  Parameter::BooleanParam showInManager{attributes.GenerateUid(), "Show in asset manager",
                             true};
  Parameter::EnumParam pathType{
      attributes.GenerateUid(), "Path type",
      std::map<int, std::string>{{PathType::Relative, "Relative"},
                                 {PathType::Absolute, "Absolute"}},
      PathType::Absolute};

  /**
   * @brief Opens the resource in the appropriate editor.
   */
  virtual void Open();

  /**
   * @brief Adds this resource to the tree model for representing in ui mostly
   * for outliner.
   *
   * @param row TreeIter to the row assigned to this resource.
   * @param store Pointer to the tree model.
   */
  virtual void AppendToModel(Gtk::TreeIter row, Gtk::TreeStore *store);

  /**
   * @brief Add items to @a menu. Called when the resource has to build context
   * menu in outliner.
   *
   * @param menu Pointer to context menu that will be shown in outliner.
   *
   * @note Memory management for the menu is handled by outliner.
   */
  virtual void OnRowContextMenu(Gtk::Menu *menu);

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

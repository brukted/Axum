/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#ifndef _FOLDER_H
#define _FOLDER_H

#include "Resource.h"
#include <boost/serialization/access.hpp>
#include <boost/serialization/base_object.hpp>
#include <boost/serialization/list.hpp>
#include <boost/serialization/split_free.hpp>
#include <boost/serialization/version.hpp>
#include <list>

namespace Axum {
namespace ResourceType {

class Folder : public Resource {
  friend class boost::serialization::access;

private:
  std::list<Resource *> Resources;
  std::list<Folder> SubFolders;

public:
  virtual void AppendToModel(Gtk::TreeIter row, Gtk::TreeStore *store) override;
  /**
   * @brief Adds resource to this folder.
   *
   * @param resource pointer to the resource to be addded.
   */
  void AddResource(Resource *resource);
  /**
   * @brief Removes resource from this folder.
   *
   * @param resource Pointer to the resource to be removed.
   *
   * @note This doesn't delete the resource.If you want to delete, call
   * DeleteResource from the package instade.
   */
  void RemoveResource(Resource *resource);
  /**
   * @brief Removes resource from this folder.
   *
   * @param _uid uid of the resource to be removed.
   *
   * @note This doesn't delete the resource.If you want to delete, call
   * DeleteResource from the package instade.
   */
  void RemoveResource(unsigned int _uid);

  std::list<Folder> &GetSubFolders() { return SubFolders; }

  std::list<Resource *> &GetResources() { return Resources; }

private:
  template <class Archive>
  void save(Archive &ar, const unsigned int version) const {
    ar &boost::serialization::base_object<Resource>(*this);
    ar &Resources, &SubFolders;
  }

  template <class Archive> void load(Archive &ar, const unsigned int version) {
    ar &boost::serialization::base_object<Resource>(*this);
    ar &Resources, &SubFolders;
  }
  BOOST_SERIALIZATION_SPLIT_MEMBER()
};
} // namespace ResourceType
} // namespace Axum
BOOST_CLASS_VERSION(Axum::ResourceType::Folder, 1)
#endif //_FOLDER_H

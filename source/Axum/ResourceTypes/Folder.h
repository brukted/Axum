/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#ifndef _FOLDER_H
#define _FOLDER_H

#include "Resource.h"
#include "Utils/Translation/Translation.h"
#include <boost/serialization/access.hpp>
#include <boost/serialization/base_object.hpp>
#include <boost/serialization/list.hpp>
#include <boost/serialization/split_free.hpp>
#include <boost/serialization/vector.hpp>
#include <boost/serialization/version.hpp>
#include <list>
#include <vector>

namespace Axum {
namespace ResourceType {

class Folder : public Resource {
  friend class boost::serialization::access;

private:
  std::vector<Resource *> Resources;
  std::list<Folder> SubFolders;
  unsigned int LastUID = 0;

public:
  Folder();

  /**
   * @brief Pointer to the parent folder. nullptr if this is the root folder.
   *
   */
  Folder *parent = nullptr;

  /**
   * @brief Adds resource to this folder.
   *
   * @param resource pointer to the resource to be addded.
   */
  void AddResource(Resource *resource);

  /**
   * @brief Add sub  folder to this folder.
   *
   * @param folder folder.
   *
   * @return Folder& Reference to the folder added in SubFolders.
   */
  Folder &AddFolder(Folder folder);

  /**
   * @brief Removes resource from this folder's heirarchy.
   *
   * @param resource Pointer to the resource to be removed.
   *
   * @return Folder* Pointer to the folder that was containing the resource.
   * nullptr If the resource was not contained in the heirarchy.
   *
   * @warning This doesn't delete the resource.If you want to delete the
   * resource, call RemoveResource from the package instade.
   */
  Folder *RemoveResource(Resource &resource);

  /**
   * @brief Removes resource from this folder's heirarchy.
   *
   * @param _uid uid of the resource to be removed.
   *
   * @return Folder* Pointer to the folder that was containing the resource.
   * nullptr If the resource was not contained in the heirarchy.
   *
   * @warning This doesn't delete the resource.If you want to delete the
   * resource, call RemoveResource from the package instade.
   */
  Folder *RemoveResource(unsigned int _uid);

  /**
   * @brief Removes folder from sub folders.
   *
   * @param folder Reference to the folder to be removed.
   *
   * @warning This doesn't delete resources contained in the sub folder.If you
   * want to delete the resource call remove resource from the package.
   */
  void RemoveFolder(Folder &folder);

  /**
   * @brief Removes folder from sub folders.This doesn't delete resources
   * contained in the folder.If you want to delete the resource call remove
   * resource from the package.
   *
   * @param _uid uid of the folder to be removed.
   *
   */
  void RemoveFolder(unsigned int _uid);

  /**
   * @brief Find folder.
   *
   * @param _uid uid of the folder.
   *
   * @return Folder& Reference to the folder.
   */
  Folder &FindFolder(unsigned int _uid);

  std::list<Folder> &GetSubFolders() { return SubFolders; }

  std::vector<Resource *> &GetResources() { return Resources; }

private:
  template <class Archive>
  void save(Archive &ar, const unsigned int /*version*/) const {
    ar &boost::serialization::base_object<Resource>(*this);
    std::vector<unsigned int> resourceIDs;
    for (auto *resource : Resources) {
      resourceIDs.push_back(resource->uid);
    }
    ar &resourceIDs &SubFolders &LastUID;
  }

  template <class Archive>
  void load(Archive &ar, const unsigned int /*version*/) {
    ar &boost::serialization::base_object<Resource>(*this);
    std::vector<unsigned int> resourceIDs;
    ar &resourceIDs;
    for (auto id : resourceIDs) {
      Resources.push_back(&(package->FindResource(id)));
    }
    ar &SubFolders &LastUID;
  }
  BOOST_SERIALIZATION_SPLIT_MEMBER()
};
} // namespace ResourceType
} // namespace Axum
BOOST_CLASS_VERSION(Axum::ResourceType::Folder, 1)
#endif //_FOLDER_H

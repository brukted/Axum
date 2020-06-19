/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#ifndef _PACKAGE_H
#define _PACKAGE_H

#include "../NodeGraph/Graph.h"
#include "../ResourceTypes/Resource.h"
#include "PathUtils.h"
#include "boost/archive/text_iarchive.hpp"
#include "boost/serialization/access.hpp"
#include "boost/serialization/base_object.hpp"
#include "boost/serialization/list.hpp"
#include "boost/serialization/split_member.hpp"
#include "boost/serialization/vector.hpp"
#include "boost/serialization/version.hpp"
#include <fstream>
#include <vector>

namespace Axum {
namespace ResourceType {

class Package : public Resource {
  friend class boost::serialization::access;

public:
  std::list<Resource> Resources;

  /**
   * @brief Get the Resource with the specified uid.
   *
   * @param _uid Unique identifier of the resource.
   * @return Resource& reference to the resource by uid.
   */
  Resource &GetResource(unsigned int _uid);

private:
  template <class Archive>
  void save(Archive &ar, const unsigned int version) const {
    ar &boost::serialization::base_object<Resource>(*this);
    if (this->resourceType == ResourceType::Embedded)
      ar &Resources;
  }

  template <class Archive> void load(Archive &ar, const unsigned int version) {
    ar &boost::serialization::base_object<Resource>(*this);
    if (this->resourceType == ResourceType::Embedded) {
      ar &Resources;
    } else {
      /**
       * @brief formattedPath Path with replaced internal dependency uri
       * with proper path eg: AX://test.pkg -> $resourcesPath/packages/test.pkg
       *
       */
      std::string formattedPath = mPath;
      std::size_t i = formattedPath.find("AX://");
      if (i != formattedPath.npos)
        formattedPath.replace(i, 5, (Utils::PathUtils::resourcesPath + "/"));
      std::ifstream ifs(std::move(formattedPath));
      boost::archive::text_iarchive ia(ifs);
      ia >> *this;
      this->resourceType = ResourceType::Linked;
    }
  }
  BOOST_SERIALIZATION_SPLIT_MEMBER()
};
} // namespace ResourceType
} // namespace Axum
BOOST_CLASS_VERSION(Axum::ResourceType::Package, 1)
#endif //_PACKAGE_H

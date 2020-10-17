/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#ifndef _SCENE_H
#define _SCENE_H

#include "Resource.h"
#include <array>
#include <boost/serialization/access.hpp>
#include <boost/serialization/array.hpp>
#include <boost/serialization/base_object.hpp>
#include <boost/serialization/split_member.hpp>
#include <boost/serialization/vector.hpp>
#include <boost/serialization/version.hpp>
#include <vector>

namespace Axum {
namespace ResourceType {
class Mesh {
  friend class boost::serialization::access;

public:
  std::vector<std::array<float, 3>> vertices;
  std::vector<std::array<float, 3>> normals;
  std::vector<unsigned int> indices;
  std::vector<Mesh> subMeshs;
  int materialId;

  Mesh(){};

private:
  bool NeedUpdate = true;
  template <class Archive>
  void save(Archive &ar, const unsigned int /*version*/) const {
    ar &vertices;
    ar &normals;
    ar &indices;
    ar &subMeshs;
    ar &materialId;
  }
  template <class Archive>
  void load(Archive &ar, const unsigned int /*version*/) {
    ar &vertices;
    ar &normals;
    ar &indices;
    ar &subMeshs;
    ar &materialId;
  }
  BOOST_SERIALIZATION_SPLIT_MEMBER()
};

class Scene : public Resource {
  friend class boost::serialization::access;

public:
  Scene();
  std::vector<Mesh> meshs;

private:
  template <class Archive>
  void save(Archive &ar, const unsigned int /*version*/) const {
    ar &boost::serialization::base_object<Resource>(*this);
    ar &meshs;
  }

  template <class Archive>
  void load(Archive &ar, const unsigned int /*version*/) {
    ar &boost::serialization::base_object<Resource>(*this);
    ar &meshs;
  }
  BOOST_SERIALIZATION_SPLIT_MEMBER()
};
} // namespace ResourceType
} // namespace Axum
BOOST_CLASS_VERSION(Axum::ResourceType::Mesh, 1)
BOOST_CLASS_VERSION(Axum::ResourceType::Scene, 1)
#endif //_SCENE_H

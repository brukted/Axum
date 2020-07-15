/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#ifndef _SCENE_H
#define _SCENE_H

#include "Resource.h"
#include "boost/serialization/access.hpp"
#include "boost/serialization/array.hpp"
#include "boost/serialization/base_object.hpp"
#include "boost/serialization/split_member.hpp"
#include "boost/serialization/vector.hpp"
#include "boost/serialization/version.hpp"
#include <vector>
namespace Axum {
namespace ResourceType {
class Mesh {
public:
  std::vector<float[3]> Vertices;
  std::vector<float[3]> Normals;
  std::vector<unsigned int> Indices;
  std::vector<Mesh> SubMeshs;
  int MaterialId;

private:
  bool NeedUpdate = true;
  template <class Archive>
  void save(Archive &ar, const unsigned int version) const {
    ar &Vertices;
    ar &Normals;
    ar &Indices;
    ar &SubMeshs;
    ar &MaterialId;
  }
  template <class Archive> void load(Archive &ar, const unsigned int version) {
    ar &Vertices;
    ar &Normals;
    ar &Indices;
    ar &SubMeshs;
    ar &MaterialId;
  }
  BOOST_SERIALIZATION_SPLIT_MEMBER()
};

class Scene : public Resource {
  friend class boost::serialization::access;

public:
  std::vector<Mesh> meshs;

  virtual void AppendToModel(Gtk::TreeIter row, Gtk::TreeStore *store) override;

private:
  template <class Archive>
  void save(Archive &ar, const unsigned int version) const {
    ar &boost::serialization::base_object<Resource>(*this);
    ar &meshs;
  }

  template <class Archive> void load(Archive &ar, const unsigned int version) {
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

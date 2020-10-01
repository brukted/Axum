/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#ifndef _MATERIALNODE_H
#define _MATERIALNODE_H

#include "../Material.h"
#include "../Node.h"
#include "Parameter/Parameter.h"
#include <boost/serialization/base_object.hpp>

namespace Axum::NodeGraph::Material {

class MaterialNode : public Node {
  friend class boost::serialization::access;

public:
  Parameter::EnumParam width{"MATERIAL_NODE_COMMON_WIDTH", outputSizes, 1024,
                             "Width"};
  Parameter::EnumParam height{"MATERIAL_NODE_COMMON_HEIGHT", outputSizes, 1024,
                              "Height"};
  Parameter::EnumParam imageFormat{"MATERIAL_NODE_COMMON_FORMAT", imageFormats,
                                   ImageFormat::EIGHT_BIT, "Image format"};
  Parameter::IntegerParam seed{"MATERIAL_NODE_COMMON_SEED", 0, "Random seed"};

  MaterialNode();

  LIST_PARAMETERS(&width, &height, &imageFormat, &seed)

private:
  template <class Archive>
  void save(Archive &ar, const unsigned int version) const {
    ar &width, &height, &imageFormat, &seed;
  }

  template <class Archive> void load(Archive &ar, const unsigned int version) {
    ar &width, &height, &imageFormat, &seed;
  }
  BOOST_SERIALIZATION_SPLIT_MEMBER()
};
} // namespace Axum::NodeGraph::Material
BOOST_CLASS_VERSION(Axum::NodeGraph::Material::MaterialNode, 1)
#endif //_MATERIALNODE_H

/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#ifndef _MATERIALGRAPH_H
#define _MATERIALGRAPH_H

#include "Graph.h"
#include "Material.h"
#include "Nodes/MaterialNode.h"
#include "Parameter/Parameter.h"

namespace Axum {
namespace NodeGraph::Material {
class MaterialGraph : public Graph {
  friend class boost::serialization::access;

public:
  Parameter::EnumParam width{"MATERIAL_DEFAULT_WIDTH", "Width", outputSizes,
                             1024};
  Parameter::EnumParam height{"MATERIAL_DEFAULT_HEIGHT", "Height", outputSizes,
                              1024};
  Parameter::EnumParam imageFormat{"MATERIAL_DEFAULT_FORMAT", "Image format",
                                   imageFormats, ImageFormat::EIGHT_BIT};
  Parameter::IntegerParam seed{"MATERIAL_DEFAULT_SEED", "Random seed", 0};
  Parameter::ParamCollection exposedParams{
      "MATERIAL_DEFAULT_EXPOSED_PARAMETRS", "Exposed Parameters", {}};

  MaterialGraph(unsigned int _uid);

  void SetupCache();

  void DeleteCache();

  void Process();

  ADD_PARAMTERS(Resource, &width, &height, &imageFormat, &seed,
                &exposedParams)

private:
  template <class Archive>
  void save(Archive &ar, const unsigned int version) const {
    ar &boost::serialization::base_object<Graph>(*this);
    ar &width, &height, &imageFormat, &seed, &exposedParams;
  }

  template <class Archive> void load(Archive &ar, const unsigned int version) {
    ar &boost::serialization::base_object<Graph>(*this);
    ar &width, &height, &imageFormat, &seed, &exposedParams;
  }
  BOOST_SERIALIZATION_SPLIT_MEMBER()
};
} // namespace NodeGraph::Material
} // namespace Axum
BOOST_CLASS_VERSION(Axum::NodeGraph::Material::MaterialGraph, 1)
#endif //_MATERIALGRAPH_H

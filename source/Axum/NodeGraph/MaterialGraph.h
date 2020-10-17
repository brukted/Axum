/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#ifndef _MATERIAL_GRAPH_H
#define _MATERIAL_GRAPH_H

#include "Graph.h"
#include "Material.h"
#include "Parameter/Parameter.h"
#include "Utils/Translation/Translation.h"

namespace Axum {
namespace NodeGraph::Material {
class MaterialGraph : public Graph {
  friend class boost::serialization::access;

public:
  Parameter::EnumParam width{"MATERIAL_DEFAULT_WIDTH", outputSizes, 1024,
                             "Width"};
  Parameter::EnumParam height{"MATERIAL_DEFAULT_HEIGHT", outputSizes, 1024,
                              "Height"};
  Parameter::EnumParam imageFormat{"MATERIAL_DEFAULT_FORMAT", imageFormats,
                                   ImageFormat::EIGHT_BIT, "Image format"};
  Parameter::IntegerParam seed{"MATERIAL_DEFAULT_SEED", 0, "Random seed"};
  Parameter::ParamCollection exposedParams{
      "MATERIAL_DEFAULT_EXPOSED_PARAMETERS", "Exposed Parameters"};

  MaterialGraph();

  ADD_PARAMTERS(Axum::ResourceType::Resource, &width, &height, &imageFormat,
                &seed, &exposedParams)
private:
  template <class Archive>
  void save(Archive &ar, const unsigned int /*version*/) const {
    ar &boost::serialization::base_object<Graph>(*this);
    ar &width, &height, &imageFormat, &seed, &exposedParams;
  }

  template <class Archive>
  void load(Archive &ar, const unsigned int /*version*/) {
    ar &boost::serialization::base_object<Graph>(*this);
    ar &width, &height, &imageFormat, &seed, &exposedParams;
  }
  BOOST_SERIALIZATION_SPLIT_MEMBER()
};

} // namespace NodeGraph::Material
} // namespace Axum
BOOST_CLASS_VERSION(Axum::NodeGraph::Material::MaterialGraph, 1)
#endif //_MATERIAL_GRAPH_H

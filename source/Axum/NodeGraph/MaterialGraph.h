/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#ifndef _MATERIALGRAPH_H
#define _MATERIALGRAPH_H

#include "../../Parameter/EnumParam.h"
#include "../../Parameter/Float2Param.h"
#include "../../Parameter/Integer2Param.h"
#include "../../Parameter/IntegerParam.h"
#include "Graph.h"
#include "Material.h"
#include "Nodes/MaterialNode.h"

namespace Axum {
namespace NodeGraph::Material {
class MaterialGraph : public Graph {
  friend class boost::serialization::access;

public:
  Parameter::ParamCollection defaultParams{mParams.GenerateUid(),
                                           "Default Parameters"};
  Parameter::ParamCollection size{defaultParams.GenerateUid(), "Size"};
  Parameter::EnumParam width{size.GenerateUid(), "Width", outputSizes, 1024};
  Parameter::EnumParam height{size.GenerateUid(), "Height", outputSizes, 1024};
  Parameter::EnumParam imageFormat{defaultParams.GenerateUid(), "Image format",
                                   imageFormats, ImageFormat::EIGHT_BIT};
  Parameter::IntegerParam seed{defaultParams.GenerateUid(), "Random seed", 0};
  Parameter::ParamCollection exposedParams{mParams.GenerateUid(),
                                           "Exposed Parameters"};

  MaterialGraph(unsigned int _uid);

  void SetupCache();

  void DeleteCache();

  void Process();

private:
  template <class Archive>
  void save(Archive &ar, const unsigned int version) const {
    ar &boost::serialization::base_object<Graph>(*this);
    ar &size, &width, &height, &imageFormat, &seed;
    ar &defaultParams, &size, &exposedParams;
  }

  template <class Archive> void load(Archive &ar, const unsigned int version) {
    ar &boost::serialization::base_object<Graph>(*this);
    ar &size, &width, &height, &imageFormat, &seed;
    ar &defaultParams, &size, &exposedParams;
  }
  BOOST_SERIALIZATION_SPLIT_MEMBER()
};
} // namespace NodeGraph::Material
} // namespace Axum
BOOST_CLASS_VERSION(Axum::NodeGraph::Material::MaterialGraph, 1)
#endif //_MATERIALGRAPH_H

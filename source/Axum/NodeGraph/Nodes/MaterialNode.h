/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#ifndef _MATERIALNODE_H
#define _MATERIALNODE_H

#include "../InputSockets/MaterialInSocket.h"
#include "../Material.h"
#include "../Node.h"
#include "../OutputSockets/MaterialOutSocket.h"
#include "Parameter/Parameter.h"
#include <boost/serialization/base_object.hpp>

namespace Axum::NodeGraph::Material {

static const std::map<int, std::string> outputSizes{
    {8, "8"},     {16, "16"},   {32, "32"},     {64, "64"},     {128, "128"},
    {256, "256"}, {512, "512"}, {1024, "1024"}, {2048, "2048"}, {4096, "4096"}};

static const std::map<int, std::string> imageFormats{
    {ImageFormat::EIGHT_BIT, "8 bit"},
    {ImageFormat::SIXTEEN_BIT, "16 bit"},
    {ImageFormat::SIXTEEN_BIT_FLOAT, "16 bit float"},
    {ImageFormat::THIRTY_TWO_BIT_FLOAT, "32 bit float"}};

class MaterialNode : public Node {
  friend class boost::serialization::access;

public:
  Parameter::EnumParam width{"MATERIAL_NODE_COMMON_WIDTH", "Width", outputSizes,
                             1024};
  Parameter::EnumParam height{"MATERIAL_NODE_COMMON_HEIGHT", "Height",
                              outputSizes, 1024};
  Parameter::EnumParam imageFormat{"MATERIAL_NODE_COMMON_FORMAT",
                                   "Image format", imageFormats,
                                   ImageFormat::EIGHT_BIT};
  Parameter::IntegerParam seed{"MATERIAL_NODE_COMMON_SEED", "Random seed", 0};

  /**
   * @brief Don't use it.Construct a new Material Node object.
   *
   */
  MaterialNode();

  MaterialNode(unsigned int _uid);

  /**
   * @brief Initializes textures on the GPU.
   *
   */
  void SetupCache();

  /**
   * @brief Deletes textures on the GPU.
   *
   */
  void DeleteCache();

  /**
   * @brief Executes compiles the shader process and writes data on textures in
   * each output sockets.
   *
   */
  virtual void Excute();

  /**
   * @brief Excutes the node and nodes that are connected to it's output
   * sockets.
   *
   */
  void ExcuteForward();

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

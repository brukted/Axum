/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#ifndef __AXUM_NODE_GRAPH_LINK_H__
#define __AXUM_NODE_GRAPH_LINK_H__

#include <boost/serialization/serialization.hpp>

namespace Axum::NodeGraph {

enum DataType {
  None,
  // Material socket types
  Grayscale,
  Color,
  // Math(logic) socket types
  Float3,
  Float4,
  Float2,
  Float,
  Int4,
  Int3,
  Int2,
  Int,
  Boolean
};

/**
 * @brief Struct to contain ui layout information of a node.
 *
 */
struct UiInfo {
  float xGridPos = 0;
  float yGridPos = 0;
  bool isCollapsed = false;
  template <class Archive>
  void serialize(Archive &ar, const unsigned int version) {
    ar &xGridPos &yGridPos &isCollapsed;
  };
};

enum NodeType { GenericType, MaterialType, LogicType };
enum NodeSubType { GenericNode, Comment, Reroute };

} // namespace Axum::NodeGraph
#endif // __AXUM_NODE_GRAPH_LINK_H__
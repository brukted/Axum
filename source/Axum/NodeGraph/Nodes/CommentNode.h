/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#ifndef _AXUM_NODEGRAPH_NODES_COMMENT_H
#define _AXUM_NODEGRAPH_NODES_COMMENT_H

#include "../Node.h"
#include <boost/serialization/base_object.hpp>
#include <boost/serialization/string.hpp>
#include <string>
#include <string_view>

namespace Axum {
namespace NodeGraph {

class CommentNode : public Node {
public:
  std::string commentText;

  CommentNode(std::string_view comment = "Comment");

  ADD_PARAMTERS(Node)

  void draw() override;

  // clang-format off
  template <class Archive> 
  void serialize(Archive &ar, const unsigned int) {
    // clang-format on
    ar &boost::serialization::base_object<Node>(*this);
    ar &commentText;
  }
};
} // namespace NodeGraph
} // namespace Axum
BOOST_CLASS_VERSION(Axum::NodeGraph::CommentNode, 0)
#endif //_AXUM_NODEGRAPH_NODES_COMMENT_H

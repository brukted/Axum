
#include "CommentNode.h"
// clang-format off
#include <boost/serialization/export.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>
// clang-format on

namespace Axum::NodeGraph {

CommentNode::CommentNode(std::string_view comment)
    : Node(NodeType::GenericType, NodeSubType::Comment),
      commentText(comment) {}

void CommentNode::draw() {
  imnodes::BeginNode(uid);
  auto size = ImGui::CalcTextSize(commentText.c_str());
  ImGui::PushItemWidth(size.x);
  ImGui::InputText("##Comment", &commentText);
  imnodes::EndNode();
}

} // namespace Axum::NodeGraph

BOOST_CLASS_EXPORT(Axum::NodeGraph::CommentNode);

/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#include "Node.h"

/**
 * Node implementation
 *
 * Generic node class.Node class defines basic common aspects of all kinds
 * nodes. Note:If you want to create new type of node graph system you should
 * create derived node class from this as well as a specialized node tree,graph
 * and sockets.
 */

namespace Axum::NodeGraph {

Node::Node(NodeType type, NodeSubType SubType) : type(type), subType(SubType) {}

OutputSocket &Node::GetOutputSocket(int _uid) {
  for (auto &Var : this->OutputSockets) {
    if (Var.GetUID() == _uid)
      return Var;
  }
  AX_LOG_CORE_CRITICAL(
      "Requested an output socket that doesn't exist with uid = {0:d}", _uid)
  assert(false && "Output socket doesn't exist");
}

InputSocket &Node::GetInputSocket(int _uid) {
  for (auto &Var : this->InputSockets) {
    if (Var.GetUID() == _uid)
      return Var;
  }
  AX_LOG_CORE_CRITICAL(
      "Requested an input socket that doesn't exist with uid = {0:d}", _uid)
  assert(false && "Input socket doesn't exist");
}

std::vector<OutputSocket> &Node::GetOutputSockets() { return OutputSockets; }

std::vector<InputSocket> &Node::GetInputSockets() { return InputSockets; }

void Node::draw() {
  imnodes::BeginNode(uid);
  imnodes::BeginNodeTitleBar();
  ImGui::TextUnformatted(UIName.c_str());
  imnodes::EndNodeTitleBar();
  for (auto &inSocket : InputSockets) {
    imnodes::BeginInputAttribute(inSocket.uid);
    ImGui::TextUnformatted(inSocket.UIName.c_str());
    imnodes::EndInputAttribute();
  }
  for (auto &outSocket : OutputSockets) {
    imnodes::BeginOutputAttribute(outSocket.uid);
    ImGui::TextUnformatted(outSocket.UIName.c_str());
    imnodes::EndOutputAttribute();
  }
  imnodes::EndNode();
}

bool Node::isInputsVisited() {
  for (auto &InSocket : InputSockets) {
    if (InSocket.linkedSocket->parentNode->isVisited == false)
      return false;
  }
  return true;
}

bool Node::isEndNode() {
  if (OutputSockets.size() == 0) {
    return true;
  } else {
    for (auto &OutSocket : OutputSockets) {
      if (OutSocket.isLinked())
        return false;
    }
  }
  return true;
}

bool Node::isStartNode() {
  if (InputSockets.size() == 0) {
    return true;
  } else {
    for (auto &InSocket : InputSockets) {
      if (InSocket.isLinked())
        return false;
    }
  }
  return true;
}
} // namespace Axum::NodeGraph
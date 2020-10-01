/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#include "Graph.h"

/**
 * Graph implementation
 */

namespace Axum::NodeGraph {

Node &Graph::GetNode(int _uid) {
  auto i = std::find_if(
      mNodes.begin(), mNodes.end(),
      [&](const std::unique_ptr<Node> &val) { return val->GetUID() == _uid; });
  if (i != std::end(mNodes))
    return *(i->get());
  else {
    AX_LOG_CORE_ERROR("Tried to get node that doesn't exist uid = {0:d} .",
                      _uid);
    throw "Node with the specified identifer does not exist.";
  }
}

std::vector<std::unique_ptr<Node>> const &Graph::getNodes() { return mNodes; }

void Graph::AddNode(Node *node) {
  Graph::mNodes.emplace_back(node);
}

void Graph::DeleteNode(int _uid) {}

std::vector<Node *> Graph::transverse() {
  // reset all nodes to unvisited
  for (auto &node : mNodes) {
    node->isVisited = false;
  }

  auto nodes = std::vector<Node *>();
  auto currentNodes = std::vector<Node *>();
  auto nextNodes = std::vector<Node *>();
  // add the first layer which is nodes with no inputs
  for (auto &node : mNodes) {
    if (node->isStartNode()) {
      nodes.push_back(node.get());
      currentNodes.push_back(node.get());
      node->isVisited = true;
    }
  }
  do {
    // adds next layer of nodes
    for (auto node : currentNodes) {
      for (auto &outSocket : node->GetOutputSockets()) {
        for (auto inSocket : outSocket.linkedSockets) {
          if (inSocket->ParentNode->isInputsVisited()) {
            inSocket->ParentNode->isVisited = true;
            nextNodes.push_back(inSocket->ParentNode);
          }
        }
      }
    }
    currentNodes.clear();
    // append the next layer to nodes and assign it as current layer
    for (auto node : nextNodes) {
      nodes.push_back(node);
      currentNodes.push_back(node);
    }
    nextNodes.clear();
  } while (currentNodes.size() != 0);
  return nodes;
}

} // namespace Axum::NodeGraph
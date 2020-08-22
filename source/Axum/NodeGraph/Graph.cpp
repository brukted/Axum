/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#include "Graph.h"

/**
 * Graph implementation
 */

namespace Axum::NodeGraph {

Node &Graph::GetNode(unsigned int _uid) {
  auto i = std::find_if(mNodes.begin(), mNodes.end(),
                        [&](const Node &val) { return val.GetUID() == _uid; });
  if (i != std::end(mNodes))
    return *i;
  else {
    AX_LOG_CORE_CRITICAL("Tried to get node that doesn't exist uid = {0:d} .",
                         _uid);
    throw "Node with the specified identifer does not exist.";
  }
}

std::list<Node>::iterator Graph::GetNodeIterator(unsigned int _uid) {
  auto i = std::find_if(mNodes.begin(), mNodes.end(),
                        [&](const Node &val) { return val.GetUID() == _uid; });
  if (i != std::end(mNodes))
    return i;
  else {
    AX_LOG_CORE_CRITICAL("Tried to get node that doesn't exist uid = {0:d} .",
                         _uid);
    throw "Node with the specified identifer does not exist.";
  }
}

void Graph::AddNode(Node n) { Graph::mNodes.push_back(std::move(n)); }

void Graph::DeleteNode(unsigned int _uid) {

  mNodes.erase(Graph::GetNodeIterator(_uid));
}

std::vector<Node *> Graph::transverse() {
  // reset all nodes to unvisited
  for (auto &node : mNodes) {
    node.isVisited = false;
  }

  auto nodes = std::vector<Node *>();
  auto currentNodes = std::vector<Node *>();
  auto nextNodes = std::deque<Node *>();
  // add the first layer which is nodes with no inputs
  for (auto &n : mNodes) {
    if (n.isStartNode()) {
      nodes.push_back(&n);
      currentNodes.push_back(&n);
      n.isVisited = true;
    }
  }
  do {
    // adds next layer of nodes
    for (auto node : currentNodes) {
      for (auto &outSocket : node->GetOutputSockets()) {
        for (auto inSocket : outSocket.LinkedSockets) {
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
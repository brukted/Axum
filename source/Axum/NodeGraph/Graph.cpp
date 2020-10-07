/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#include "Graph.h"

/**
 * Graph implementation
 */

namespace Axum::NodeGraph {

Node &Graph::getNode(int nodeUid) {
  auto i = std::find_if(mNodes.begin(), mNodes.end(),
                        [nodeUid](const std::unique_ptr<Node> &val) {
                          return val->uid == nodeUid;
                        });
  assert(i != mNodes.end());
  return *(i->get());
}

std::vector<std::unique_ptr<Node>> const &Graph::getNodes() { return mNodes; }

std::vector<Link> const &Graph::getLinks() { return links; }

void Graph::addNode(Node *node) {
  node->uid = ++lastNodeUID;
  node->parentGraph = this;
  Graph::mNodes.emplace_back(node);
}

void Graph::deleteNode(int nodeUid) {
  AX_LOG_EDITOR_DEBUG("Deleting node, uid = {}", nodeUid)
  auto &node = getNode(nodeUid);
  for (auto &InSocket : node.GetInputSockets()) {
    if (InSocket.isLinked())
      deleteLink(&InSocket);
  }
  for (auto &OutSocket : node.GetOutputSockets()) {
    if (OutSocket.isLinked()) {
      for (auto *InSocket : OutSocket.linkedSockets) {
        deleteLink(InSocket);
      }
    }
  }
  auto it = std::find_if(mNodes.begin(), mNodes.end(),
                         [nodeUid](const std::unique_ptr<Node> &val) {
                           return val->uid == nodeUid;
                         });
  assert(it != mNodes.end());
  mNodes.erase(it);
}

void Graph::addLink(Link link) {
  link.id = ++(lastLinkUID);
  links.emplace_back(std::move(link));
}

void Graph::deleteLink(int LinkId) {
  auto LinkIt = std::find_if(links.begin(), links.end(), [LinkId](Link &link) {
    return link.id == LinkId;
  });
  assert(LinkIt != links.end());
  LinkIt->fromSocket->UnlinkFrom(LinkIt->toSocket);
  links.erase(LinkIt);
}

void Graph::deleteLink(InputSocket *targetSocket) {
  auto it =
      std::find_if(links.begin(), links.end(), [targetSocket](Link &link) {
        return (link.toSocketUID == targetSocket->uid);
      });
  assert(it != links.end());
  targetSocket->linkedSocket->UnlinkFrom(targetSocket);
  links.erase(it);
}

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
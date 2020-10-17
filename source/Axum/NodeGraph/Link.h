/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#ifndef _AXUM_NODE_GRAPH_LINK_H__
#define _AXUM_NODE_GRAPH_LINK_H__

#include "InputSocket.h"
#include "Node.h"
#include "OutputSocket.h"
#include <boost/serialization/serialization.hpp>

namespace Axum::NodeGraph {

struct Link {
  int id;
  Node *fromNode;
  Node *toNode;
  InputSocket *toSocket;
  OutputSocket *fromSocket;

  /// Performace optimization to avoid dereferecing pointers
  int fromNodeUID;
  int fromSocketUID;
  int toNodeUID;
  int toSocketUID;
  Link(){};
  Link(int id, Node *fromNode, OutputSocket *fromSocket, Node *toNode,
       InputSocket *toSocket)
      : id(id), fromNode(fromNode), fromSocket(fromSocket), toNode(toNode),
        toSocket(toSocket) {
    fromNodeUID = fromNode->uid;
    fromSocketUID = fromSocket->uid;
    toNodeUID = toNode->uid;
    toSocketUID = toSocket->uid;
  };
  template <class Archive>
  void serialize(Archive &ar, const unsigned int /*version*/) {
    ar &id &fromNode &fromNode &toSocket &fromSocket &fromNodeUID &fromSocketUID
        &toSocketUID &toNodeUID;
  }
};

} // namespace Axum::NodeGraph

#endif // _AXUM_NODE_GRAPH_LINK_H__
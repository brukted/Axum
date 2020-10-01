/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#ifndef _OUTPUTSOCKET_H
#define _OUTPUTSOCKET_H

#include "Node.h"
#include "NodeGraphHelpers.h"
#include <boost/serialization/serialization.hpp>
#include <boost/serialization/vector.hpp>
#include <string>
#include <string_view>
#include <vector>

namespace Axum {
namespace NodeGraph {

class Node;
class InputSocket;

class OutputSocket {

public:
  Node *parentNode;
  int uid = 0;
  std::string UIName;
  DataType type = DataType::None;
  std::vector<InputSocket *> linkedSockets;

  OutputSocket(int uid, Node *parentNode, std::string_view name, DataType type);

  OutputSocket(){};

  // These functions don't affect links in a graph
  void LinkTo(InputSocket *socket);

  void UnlinkFrom(int uid);

  void UnlinkFrom(InputSocket *socket);

  bool isLinked();

  inline int GetUID() { return uid; };

  template <class Archive>
  void serialize(Archive &ar, const unsigned int version) {
    ar &uid &type;
  }
};

} // namespace NodeGraph
} // namespace Axum
#endif //_OUTPUTSOCKET_H

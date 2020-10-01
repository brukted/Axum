/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#ifndef _INPUT_SOCKET_H
#define _INPUT_SOCKET_H

#include "Node.h"
#include "NodeGraphHelpers.h"
#include "OutputSocket.h"
#include <boost/serialization/serialization.hpp>
#include <boost/serialization/string.hpp>
#include <string>

namespace Axum {
namespace NodeGraph {

class Node;
class OutputSocket;

class InputSocket {
  friend class OutputSocket;

protected:
  // These functions don't affect links in a graph. Also doesn't affect the
  // linked socket.
  void HalfLink(OutputSocket *socket);
  void halfUnlink();

public:
  // Runtime data  not serialized
  OutputSocket *linkedSocket = nullptr;
  Node *ParentNode = nullptr;

  /// Unique identifer of this socket.
  int uid = 0;
  /// Name of the node to be displayed on ui
  std::string UIName;
  DataType type = DataType::None;

  InputSocket(int uid, Node *parentNode, std::string_view uiName,
              DataType type);

  // For serialization  only
  InputSocket(){};

  bool isLinked();

  inline int GetUID() { return uid; };

  template <class Archive>
  void serialize(Archive &ar, const unsigned int version) {
    ar &uid &type;
  }
};

} // namespace NodeGraph
} // namespace Axum
#endif //_INPUT_SOCKET_H

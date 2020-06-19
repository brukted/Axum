/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#ifndef _INPUT_SOCKET_H
#define _INPUT_SOCKET_H

#include "Node.h"
#include "OutputSocket.h"
#include <string>

namespace Axum {
namespace NodeGraph {

class Node;
class OutputSocket;

class InputSocket {
  friend class OutputSocket;

protected:
  /**
   * @brief Unique identifer of this socket.
   *
   */
  unsigned int uid;
  /**
   * @brief Creates one sided link with @a socket
   *
   *@param socket Source socket of the link
   **/
  void HalfLink(OutputSocket *socket);

public:
  OutputSocket *LinkedSocket = nullptr;

  Node *ParentNode = nullptr;

  /**
   *@brief Name of the node to be displayed on ui
   **/
  std::string UIName;

  void Unlink();

  bool isLinked();

  inline unsigned int GetUID() { return uid; };
};

} // namespace NodeGraph
} // namespace Axum
#endif //_INPUT_SOCKET_H

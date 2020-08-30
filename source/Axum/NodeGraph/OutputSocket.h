/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#ifndef _OUTPUTSOCKET_H
#define _OUTPUTSOCKET_H

#include "Node.h"
#include <string>
#include <vector>

namespace Axum {
namespace NodeGraph {

class Node;
class InputSocket;

class OutputSocket {

public:
  Node *ParentNode;
  /**
   * @brief Unique identifer of this socket in the parent nodes output sockets.
   *
   */
  unsigned int uid;
  /**
   *Name of the node to be displayed on ui
   **/
  std::string UIName;
  std::vector<InputSocket *> LinkedSockets;

  OutputSocket(std::string &_name, unsigned int _uid);

  OutputSocket(const char *_name, unsigned int _uid);

  /**
   * @brief Links this socket to @a socket two way.
   *
   * @param socket Socket to link to
   */
  void LinkTo(InputSocket *socket);

  void UnlinkFrom(unsigned int _uid);

  void UnlinkFrom(InputSocket *);

  bool isLinked();

  inline unsigned int GetUID() { return uid; };
};

} // namespace NodeGraph
} // namespace Axum
#endif //_OUTPUTSOCKET_H

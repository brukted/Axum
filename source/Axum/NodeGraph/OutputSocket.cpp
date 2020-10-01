/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#include "OutputSocket.h"

/**
 * OutputSocket implementation
 *
 * Generic Output socket containing common aspects of all output socket types.
 */

namespace Axum::NodeGraph {

void OutputSocket::LinkTo(InputSocket *socket) {
  linkedSockets.push_back(socket);
  socket->HalfLink(this);
}

void OutputSocket::UnlinkFrom(int SocketUid) {
  auto it = std::find_if(
      linkedSockets.begin(), linkedSockets.end(),
      [SocketUid](InputSocket *socket) { return (socket->uid == SocketUid); });
  assert(it != linkedSockets.end());
  (*it)->halfUnlink();
  linkedSockets.erase(it);
}

void OutputSocket::UnlinkFrom(InputSocket *socket) { UnlinkFrom(socket->uid); }

bool OutputSocket::isLinked() { return (linkedSockets.size() != 0); }

OutputSocket::OutputSocket(int uid, Node *parentNode, std::string_view name,
                           DataType type)
    : parentNode(parentNode), uid(uid), UIName(name), type(type) {}

} // namespace Axum::NodeGraph
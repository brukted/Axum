/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#include "InputSocket.h"

/**
 * InputSocket implementation
 *
 * Generic Input Socket.Defines common and basic aspects of all input socket
 * types.
 */

namespace Axum::NodeGraph {

void InputSocket::HalfLink(OutputSocket *socket) {
  this->LinkedSocket = socket;
}

void InputSocket::Unlink() { this->LinkedSocket = nullptr; }

bool InputSocket::isLinked() {
  if (LinkedSocket == nullptr) {
    return false;
  } else {
    return true;
  }
}

} // namespace Axum::NodeGraph
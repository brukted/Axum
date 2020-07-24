/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#include "Connection.h"

/**
 * Connection implementation
 *
 * Serializable representation of links between nodes.
 */

namespace Axum::Utils {

Connection::Connection(unsigned int _FromNode, unsigned int _FromSocket,
                       unsigned int _ToNode, unsigned int _ToSocket) {
  FromNode = _FromNode;
  FromSocket = _FromSocket;
  ToNode = _ToNode;
  ToSocket = _ToSocket;
}

} // namespace Axum::Utils
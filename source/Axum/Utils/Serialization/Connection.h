/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#ifndef _CONNECTION_H
#define _CONNECTION_H

#include <boost/serialization/access.hpp>
#include <boost/serialization/version.hpp>

namespace Axum {
namespace Utils {
class Connection {
  friend class boost::serialization::access;

public:
  Connection(unsigned int _FromNode, unsigned int _FromSocket,
             unsigned int _ToNode, unsigned int _ToSocket);
  /**
   * @brief UID of the source node
   *
   */
  unsigned int FromNode;
  /**
   * @brief UID of the source socket in the source node
   *
   */
  unsigned int FromSocket;
  /**
   * @brief UID of the destination(sink) node
   *
   */
  unsigned int ToNode;
  /**
   * @brief UID of the destination(Sink)  socket.
   *
   */
  unsigned int ToSocket;

private:
  template <class Archive>
  void serialize(Archive &ar, const unsigned int version) const {
    ar &FromNode;
    ar &FromSocket;
    ar &ToNode;
    ar &ToSocket;
  }
};
} // namespace Utils
} // namespace Axum
#endif //_CONNECTION_H

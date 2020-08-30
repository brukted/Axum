/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#ifndef _CONNECTION_H
#define _CONNECTION_H

#include <boost/serialization/access.hpp>
#include <boost/serialization/serialization.hpp>
#include <boost/serialization/split_member.hpp>
#include <boost/serialization/version.hpp>

namespace Axum {
namespace Utils {
class Connection {
  friend class boost::serialization::access;

public:
  Connection(){};
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
  void save(Archive &ar, const unsigned int version) const {
    ar &FromNode &FromSocket &ToNode &ToSocket;
  }

  template <class Archive> void load(Archive &ar, const unsigned int version) {
    ar &FromNode &FromSocket &ToNode &ToSocket;
  }
  BOOST_SERIALIZATION_SPLIT_MEMBER()
};
} // namespace Utils
} // namespace Axum
BOOST_CLASS_VERSION(Axum::Utils::Connection, 1)
#endif //_CONNECTION_H

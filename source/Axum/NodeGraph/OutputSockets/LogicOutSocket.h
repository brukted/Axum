/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#ifndef _LOGICOUTSOCKET_H
#define _LOGICOUTSOCKET_H

#include "../InputSockets/LogicInSocket.h"
#include "../OutputSocket.h"

namespace Axum::NodeGraph::Logic {

class LogicOutSocket : public OutputSocket {
private:
  /**
   * @brief Name of the variable output is stored in
   *
   */
  std::string variableName{"  ", 2};
  DataType type = DataType::int1;

public:
  DataType GetType() const;

  void SetType(DataType type);
};
} // namespace Axum::NodeGraph::Logic
#endif //_LOGICOUTSOCKET_H

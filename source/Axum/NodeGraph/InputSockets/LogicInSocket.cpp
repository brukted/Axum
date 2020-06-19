/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#include "LogicInSocket.h"

/**
 * LogicInSocket implementation
 */

namespace Axum::NodeGraph::Logic {

DataType LogicInSocket::GetType() const { return type; }

void LogicInSocket::SetType(DataType _type) { type = _type; }
} // namespace Axum::NodeGraph::Logic
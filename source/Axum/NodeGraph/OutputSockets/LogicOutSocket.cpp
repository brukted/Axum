/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#include "LogicOutSocket.h"

/**
 * LogicOutSocket implementation
 */

namespace Axum::NodeGraph::Logic {

DataType LogicOutSocket::GetType() const { return type; }

void LogicOutSocket::SetType(DataType type) { type = type; }
} // namespace Axum::NodeGraph::Logic
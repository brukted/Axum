/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#include "LogicNode.h"

/**
 * LogicNode implementation
 *
 * A specialized sub class of node class for function editing and also a base
 * class for all function node types.
 */
namespace Axum::NodeGraph::Logic {

LogicNode::LogicNode() {}

void LogicNode::getHeaderPart(std::shared_ptr<std::string> &code,
                              std::function<std::string()> generator) {
  return;
}

void LogicNode::getFunctionPart(std::shared_ptr<std::string> &code,
                                std::function<std::string()> generator) {
  return;
}

} // namespace Axum::NodeGraph::Logic
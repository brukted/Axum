/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#include "LogicNode.h"

/**
 * LogicNode implementation
 * 
 * A specialized sub class of node class for function editing and also a base class for all function node types.
 */

LogicNode::LogicNode()
{
}

LogicNode::LogicNode(unsigned int _uid)
{
    uid = _uid;
}

void LogicNode::getHeaderPart(std::shared_ptr<std::string> &code, ParamCollection &GraphParams) { return; }

void LogicNode::getFunctionPart(std::shared_ptr<std::string> &code, ParamCollection &GraphParams) { return; }

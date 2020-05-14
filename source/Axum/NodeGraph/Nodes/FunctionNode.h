/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#ifndef _FUNCTIONNODE_H
#define _FUNCTIONNODE_H

#include <string>
#include "../Node.h"

class FunctionNode : public Node
{
public:
    /**
 * @brief Concrete function nodes add their specific code to the source code here.
 * 
 * @param code Source code output.
 * @param GraphParams Paramaters of the parent graph.
 */
    virtual void Compile(std::shared_ptr<std::string> &code, ParamCollection &GraphParams);
};

#endif //_FUNCTIONNODE_H

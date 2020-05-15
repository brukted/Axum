/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#ifndef _LOGIC_NODE_H_
#define _LOGIC_NODE_H_

#include <string>
#include "../Node.h"

class LogicNode : public Node
{
public:
   /**
 * @brief Get the Header Part string.
 * 
 * @param code Source code output.
 * @param GraphParams Parameters of the parent graph.
 */
   virtual void getHeaderPart(std::shared_ptr<std::string> &code, ParamCollection &GraphParams);

   /**
 * @brief Concrete function nodes add their specific code to the source code here.
 * 
 * @param code Source code output.
 * @param GraphParams Paramaters of the parent graph.
 */
   virtual void getFunctionPart(std::shared_ptr<std::string> &code, ParamCollection &GraphParams);
};

#endif //_LOGIC_NODE_H_

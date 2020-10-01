/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#ifndef _LOGIC_NODE_H_
#define _LOGIC_NODE_H_

#include "../Node.h"
#include <functional>
#include <string>

namespace Axum::NodeGraph::Logic {

class LogicNode : public Node {
protected:
  LogicNode();

public:
  LogicNode(int uid);

  /**
   * @brief Get the Header Part string.
   *
   * @param code Source code output.
   * @param generator Functor to the variable name generator of the graph.
   */
  virtual void getHeaderPart(std::shared_ptr<std::string> &code,
                             std::function<std::string()> generator);

  /**
   * @brief Concrete function nodes add their specific code to the source code
   * here.
   *
   * @param code Source code output.
   * @param generator Functor to the variable name generator of the graph.
   */
  virtual void getFunctionPart(std::shared_ptr<std::string> &code,
                               std::function<std::string()> generator);
};
} // namespace Axum::NodeGraph::Logic
#endif //_LOGIC_NODE_H_

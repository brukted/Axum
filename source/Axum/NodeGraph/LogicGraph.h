/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#ifndef _LOGICGRAPH_H
#define _LOGICGRAPH_H

#include "Graph.h"
#include "InputSockets/LogicInSocket.h"
#include "Log.h"
#include "Nodes/LogicNode.h"
#include "OutputSockets/LogicOutSocket.h"
#include "fmt/format.h"
#include <array>
#include <functional>
#include <string>

namespace Axum::NodeGraph::Logic {

class LogicGraph : public Graph {
private:
  static std::array<char, 52> firstVariableLetters;
  static std::array<char, 63> secondaryVariableLetters;
  /**
   * @brief Pointer to the node assigned as output for this graph.
   *
   */
  LogicNode *output = nullptr;

public:
  /**
   * @brief Compiles the function graph and return as glsl shader
   * with a function with the graph's name.
   *
   * @return std::shared_ptr<std::string> Shared pointer to GLSL source code
   */
  std::shared_ptr<std::string> compileGL();

  /**
   * @brief Compiles the function graph and return as glsl shader
   * with a function with the graph's name.
   *
   * @return std::shared_ptr<std::string>  Shared pointer to Python source code
   */
  std::shared_ptr<std::string> compilePy();

  /**
   * @brief Maps data type to glsl data types.
   *
   * @param d data type
   * @return std::string glsl data type name
   */
  std::string DataTypeToGLSL(DataType d);
};

} // namespace Axum::NodeGraph::Logic
#endif //_LOGICGRAPH_H

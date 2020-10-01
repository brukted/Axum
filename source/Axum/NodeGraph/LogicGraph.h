/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#ifndef _LOGICGRAPH_H
#define _LOGICGRAPH_H

#include "Graph.h"
#include "Nodes/LogicNode.h"
#include "Utils/Log/Log.h"
#include <array>
#include <fmt/format.h>
#include <functional>
#include <string>

namespace Axum::NodeGraph::Logic {

class LogicGraph : public Graph {
private:
  static const std::array<char, 52> firstVariableLetters;
  static const std::array<char, 63> secondaryVariableLetters;
  /**
   * @brief Pointer to the node assigned as output for this graph.
   *
   */
  LogicNode *OutputNode = nullptr;

public:
  LogicGraph();

  /**
   * @brief Compiles the function graph and return as glsl shader
   * with a function with the graph's name.
   *
   * @return std::shared_ptr<std::string> Shared pointer to GLSL source code
   */
  std::shared_ptr<std::string> compileGL();

  /**
   * @brief Maps data type to glsl data types.
   *
   * @param type data type
   * @return std::string glsl data type name
   */
  std::string DataTypeToGLSL(DataType type);
};

} // namespace Axum::NodeGraph::Logic
#endif //_LOGICGRAPH_H

/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#ifndef _AXUM_NODEGRAPH_NODE_H_
#define _AXUM_NODEGRAPH_NODE_H_

#include "InputSocket.h"
#include "NodeGraphHelpers.h"
#include "OutputSocket.h"
#include "Parameter/Parameter.h"
#include "Utils/Log/Log.h"
#include <assert.h>
#include <boost/serialization/access.hpp>
#include <boost/serialization/array.hpp>
#include <boost/serialization/split_member.hpp>
#include <boost/serialization/vector.hpp>
#include <boost/serialization/version.hpp>
#include <imgui.h>
#include <imgui_stdlib.h>
#include <imnodes.h>
#include <string>
#include <vector>

namespace Axum {
namespace NodeGraph {

class InputSocket;
class OutputSocket;
class Graph;

class Node {
private:
  friend class boost::serialization::access;
  friend class Graph;
  bool isVisited = false;

protected:
  std::vector<InputSocket> InputSockets{};
  std::vector<OutputSocket> OutputSockets{};

public:
  Node(NodeType type = NodeType::GenericType,
       NodeSubType SubType = NodeSubType::GenericNode);
  // Name of the node to be displayed on the ui.
  std::string UIName{"Node"};
  std::string description{"Description"};
  UiInfo uiInfo;

  Graph *parentGraph = nullptr;
  /**
   * Unique identifer of the node in the graph
   **/
  int uid = 0;

  /// For easier RTTI
  NodeType type;
  NodeSubType subType;

  /**
   * @brief Get the output socket with the uid = @a uid
   *
   * @param uid uid of the socket to find
   * @return OutputSocket& reference to the socket with uid = @a uid
   */
  OutputSocket &GetOutputSocket(int uid);

  /**
   * @brief Get the Input Socket with the specified uid.
   *
   * @param _uid uid of the socket to find.
   * @return InputSocket&
   */
  InputSocket &GetInputSocket(int uid);

  std::vector<OutputSocket> &GetOutputSockets();

  std::vector<InputSocket> &GetInputSockets();

  int GetUID() const { return uid; }

  virtual void draw();

  LIST_PARAMETERS()

private:
  template <class Archive>
  void save(Archive &ar, const unsigned int /*version*/) const {
    ar &uiInfo &InputSockets &OutputSockets &uid &type &subType;
  }

  template <class Archive>
  void load(Archive &ar, const unsigned int /*version*/) {
    ar &uiInfo &InputSockets &OutputSockets &uid &type &subType;
    for (auto &InSocket : InputSockets) {
      InSocket.ParentNode = this;
    }
    for (auto &OutSocket : OutputSockets) {
      OutSocket.parentNode = this;
    }
  }
  /**
   * @brief Returns whether inputs are visited.
   *
   * @return true All input providing nodes are visited.
   * @return false Some input providing nodes are not visited.
   */
  bool isInputsVisited();
  /**
   * @brief Returns whether the node relays on other nodes output or not.
   *
   * @return true The node can excute on it's ownself.
   * @return false The node requires other nodes output.
   */
  bool isStartNode();

  /**
   * @brief Returns whether the node has output reqired by other nodes.
   *
   * @return true The node has output sockets connected to other nodes.
   * @return false The node has no output sockets or they are not connected to
   * other nodes.
   */
  bool isEndNode();

  BOOST_SERIALIZATION_SPLIT_MEMBER()
};
} // namespace NodeGraph
} // namespace Axum
BOOST_CLASS_VERSION(Axum::NodeGraph::Node, 0)
#endif //_AXUM_NODEGRAPH_NODE_H_

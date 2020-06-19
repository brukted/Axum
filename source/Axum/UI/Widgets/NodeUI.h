/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#ifndef _NODEUI_H
#define _NODEUI_H

#include "InputSocketUI.h"
#include "OutputSocketUI.h"
#include <vector>

namespace NodeGraph = Axum::NodeGraph;

namespace Axum {
namespace NodeGraph {
class Node;
}
namespace UI::Widget {

class OutputSocketUI;
class InputSocketUI;
class NodeUI {
public:
  std::vector<OutputSocketUI> mOutputSockts;
  std::vector<InputSocketUI> mInputSockets;
  NodeGraph::Node *mNode;
};
} // namespace UI::Widget
} // namespace Axum
#endif //_NODEUI_H

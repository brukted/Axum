/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#ifndef _GRAPHUI_H
#define _GRAPHUI_H

#include "../../NodeGraph/Graph.h"
#include "NodeLinkUI.h"
#include "NodeUI.h"
#include <vector>

namespace Axum::UI::Widget {

namespace ng = Axum::NodeGraph;

class GraphUI {
public:
  std::vector<NodeUI> UINodes;
  std::vector<NodeLinkUI> UILinks;
  ng::Graph *mGraph;
};

} // namespace Axum::UI::Widget
#endif //_GRAPHUI_H

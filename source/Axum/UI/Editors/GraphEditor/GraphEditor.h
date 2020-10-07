/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#ifndef _AXUM_UI_EDITORS_GRAPH_EDITOR_GRAPH_EDITOR_H__
#define _AXUM_UI_EDITORS_GRAPH_EDITOR_GRAPH_EDITOR_H__

#include "../Editor.h"
#include "NodeGraph/Graph.h"
#include "NodeGraph/InputSocket.h"
#include "NodeGraph/Link.h"
#include "NodeGraph/Material.h"
#include "NodeGraph/MaterialGraph.h"
#include "NodeGraph/Node.h"
#include "NodeGraph/Nodes/CommentNode.h"
#include "NodeGraph/OutputSocket.h"
#include <algorithm>
#include <imgui_stdlib.h>
#include <imnodes.h>
#include <limits>
#include <map>
#include <vector>

namespace Axum::UI::Editor {
class GraphEditor : public Editor {
protected:
  NodeGraph::Graph *ActiveGraph;
  std::map<int, NodeGraph::Node *> nodes;

private:
  // A work around to not change the graph mid frame
  static NodeGraph::Graph *graphToOpen;
  imnodes::EditorContext *context;
  void drawNodes();
  void drawNodeLinks();
  void checkForNewLinks();
  void checkForDestroyedLinks();
  void checkForDeletedNodes();
  void showMainContextMenu();
  void showNodeContextMenu();
  /// Checks for circular dependency between source and target nodes.
  bool dectectCycle(NodeGraph::Node *source, NodeGraph::Node *target);
  void bindGraph(NodeGraph::Graph *graph);
  void unlinkInputSocket(NodeGraph::InputSocket *socket);
  inline void deleteNode(int nodeId) {
    ActiveGraph->deleteNode(nodeId);
    auto nodeIt =
        std::find_if(nodes.begin(), nodes.end(),
                     [nodeId](std::pair<int, NodeGraph::Node *> nodeIdPair) {
                       return (nodeId == nodeIdPair.first);
                     });
    nodes.erase(nodeIt);
  };

protected:
  virtual void drawToolBar();
  virtual bool isLinkValid(const NodeGraph::Link &link);
  virtual void drawNodeContextMenu(NodeGraph::Node &node);
  virtual void drawMainContextMenu(ImVec2 &mousePos);

public:
  GraphEditor();
  void draw() override;
  static void openGraph(NodeGraph::Graph *graph);
};
} // namespace Axum::UI::Editor
#endif // _AXUM_UI_EDITORS_GRAPH_EDITOR_GRAPH_EDITOR_H__
#include "GraphEditor.h"

using namespace Axum::NodeGraph;

namespace Axum::UI::Editor {
NodeGraph::Graph *GraphEditor::graphToOpen = nullptr;

GraphEditor::GraphEditor() {}

void GraphEditor::draw() {
  static const auto &io = ImGui::GetIO();
  if (graphToOpen != nullptr) {
    bindGraph(graphToOpen);
    graphToOpen = nullptr;
  }
  if (!ImGui::Begin(_("Graph editor")) || (ActiveGraph == nullptr)) {
    ImGui::End();
    return;
  }
  imnodes::EditorContextSet(context);
  checkForDeletedNodes();
  showMainContextMenu();
  showNodeContextMenu();
  imnodes::BeginNodeEditor();
  drawNodes();
  drawNodeLinks();
  imnodes::EndNodeEditor();
  checkForNewLinks();
  checkForDestroyedLinks();
  ImGui::PushID("scrolling_region");
  if (ImGui::BeginDragDropTarget()) {
    auto data = ImGui::GetDragDropPayload();
    if (data->IsDataType("resource")) {
      ImGui::AcceptDragDropPayload(
          "resource", ImGuiDragDropFlags_::ImGuiDragDropFlags_None);
      if (data->IsDelivery()) {
        ResourceType::Resource *resource =
            *((ResourceType::Resource **)(data->Data));
        auto resourceName = resource->name.getValue().data();
        AX_LOG_EDITOR_DEBUG("Dropped resource \"{}\" on graph editor",
                            resourceName)
        onResourceDropped(resource);
      }
    }
    ImGui::EndDragDropTarget();
  }
  ImGui::PopID();
  ImGui::End();
}

void GraphEditor::openGraph(NodeGraph::Graph *graph) { graphToOpen = graph; }

void GraphEditor::bindGraph(NodeGraph::Graph *graph) {
  if (ActiveGraph != nullptr) {
    imnodes::EditorContextSet(context);
    for (auto &nodePtr : ActiveGraph->getNodes()) {
      auto nodePos = imnodes::GetNodeGridSpacePos(nodePtr->uid);
      nodePtr->uiInfo.xGridPos = nodePos.x;
      nodePtr->uiInfo.yGridPos = nodePos.y;
    }
  }
  if (ActiveGraph != graph) {
    if (context != nullptr)
      imnodes::EditorContextFree(context);
    context = imnodes::EditorContextCreate();
    imnodes::EditorContextSet(context);
    AX_LOG_EDITOR_INFO("Opening material graph \"{}\" uid {}",
                       graph->name.getValue().data(), graph->uid)
    nodes.clear();
    ActiveGraph = graph;
    for (auto &nodePtr : ActiveGraph->getNodes()) {
      nodes.emplace(nodePtr->uid, nodePtr.get());
      imnodes::SetNodeGridSpacePos(
          nodePtr->uid, {nodePtr->uiInfo.xGridPos, nodePtr->uiInfo.yGridPos});
    }
    imnodes::PushAttributeFlag(
        imnodes::AttributeFlags_EnableLinkDetachWithDragClick);
  }
}

void GraphEditor::unlinkInputSocket(NodeGraph::InputSocket *socket) {
  ActiveGraph->deleteLink(socket);
}

void GraphEditor::drawNodes() {
  for (auto &node : ActiveGraph->getNodes()) {
    node->draw();
  }
}

void GraphEditor::drawNodeContextMenu(NodeGraph::Node &) {
  ImGui::TextUnformatted("Hello node context menu");
}

void GraphEditor::drawMainContextMenu(ImVec2 & /*mousePos*/) {
  ImGui::TextUnformatted("Hello main context menu");
}

void GraphEditor::drawNodeLinks() {
  for (auto &link : ActiveGraph->getLinks()) {
    imnodes::Link(link.id, link.fromSocketUID, link.toSocketUID);
  }
}

void GraphEditor::checkForNewLinks() {
  int sourceNode;
  int sourceSocket;
  int destNode;
  int destSocket;
  if (imnodes::IsLinkCreated(&sourceNode, &sourceSocket, &destNode,
                             &destSocket)) {
    AX_LOG_EDITOR_DEBUG("Creating link from node {} from socket "
                        "{} -> node {} to socket {}",
                        sourceNode, sourceSocket, destNode, destSocket)
    Node *fromNode = nodes.find(sourceNode)->second;
    auto *fromSocket = &(fromNode->GetOutputSocket(sourceSocket));
    Node *toNode = nodes.find(destNode)->second;
    auto *toSocket = &(toNode->GetInputSocket(destSocket));
    if (dectectCycle(fromNode, toNode)) {
      AX_LOG_EDITOR_INFO("Circular cycle found while trying to create link")
      return;
    } else {
      if (toSocket->isLinked()) {
        unlinkInputSocket(toSocket);
      }
      auto link = Link(0, fromNode, fromSocket, toNode, toSocket);
      if (isLinkValid(link)) {
        ActiveGraph->addLink(std::move(link));
        fromSocket->LinkTo(toSocket);
      }
      AX_LOG_EDITOR_DEBUG("Link created")
    }
  }
}

void GraphEditor::checkForDestroyedLinks() {
  int LinkId;
  if (imnodes::IsLinkDestroyed(&LinkId)) {
    ActiveGraph->deleteLink(LinkId);
  }
}

void GraphEditor::checkForDeletedNodes() {
  static const auto &io = ImGui::GetIO();
  // Update Selected Nodes
  const auto SelectedNodesNum = imnodes::NumSelectedNodes();
  int SelectedNodeIDs[200];
  imnodes::GetSelectedNodes(SelectedNodeIDs);
  // Check for deleted nodes
  // TODO Hard coded keyboard shortcut
  if (SelectedNodesNum && ImGui::IsKeyPressed(io.KeyMap[ImGuiKey_Delete]) &&
      ImGui::IsWindowFocused(ImGuiFocusedFlags_RootAndChildWindows)) {
    for (int i = 0; i < SelectedNodesNum; ++i) {
      deleteNode(SelectedNodeIDs[i]);
    }
    imnodes::ClearNodeSelection();
  }
}

void GraphEditor::showMainContextMenu() {
  static ImVec2 mousePos;
  int HoveredNode;
  if (ImGui::IsWindowHovered(ImGuiHoveredFlags_ChildWindows) &&
      ImGui::IsMouseDown(ImGuiMouseButton_Right) &&
      !imnodes::IsNodeHovered(&HoveredNode)) {
    ImGui::OpenPopup("MainContextMenu");
    mousePos = ImGui::GetMousePos();
  }
  if (ImGui::BeginPopup("MainContextMenu")) {
    drawMainContextMenu(mousePos);
    ImGui::EndPopup();
  }
}

void GraphEditor::showNodeContextMenu() {
  int HoveredNodeId;
  static Node *node = nullptr;
  if (imnodes::IsNodeHovered(&HoveredNodeId) &&
      ImGui::IsMouseDown(ImGuiMouseButton_Right)) {
    auto NodeIt = nodes.find(HoveredNodeId);
    assert(NodeIt != nodes.end());
    node = NodeIt->second;
    ImGui::OpenPopup("NodeContextMenu");
  }
  if (ImGui::BeginPopup("NodeContextMenu")) {
    drawNodeContextMenu(*node);
    ImGui::EndPopup();
  }
}

bool GraphEditor::dectectCycle(Node *source, Node *target) {
  // TODO Not sure if it can dectect cycles in complex graphs
  assert((source != nullptr));
  assert((target != nullptr));
  if (source->uid == target->uid) {
    return true;
  }
  for (auto &OutSocket : target->GetOutputSockets()) {
    for (auto *linkedSocket : OutSocket.linkedSockets) {
      if (linkedSocket->ParentNode->uid == source->uid) {
        return true;
      } else {
        if (dectectCycle(source, linkedSocket->ParentNode))
          return true;
      }
    }
  }
  return false;
}

} // namespace Axum::UI::Editor

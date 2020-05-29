/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#include "Graph.h"

/**
 * Graph implementation
 */

Graph::Graph(unsigned int _uid) : uid(_uid) {}

/**
 * @brief Searchs for the node with the specified uid.
 * 
 * @param identifier unique identifier of the node. 
 * @return Node& reference to the node with uid is identifer. 
 */
Node &Graph::GetNode(unsigned int identifier)
{
    auto i = std::find_if(mNodes.begin(), mNodes.end(), [&](const Node &val) { return val.GetUID() == uid; });
    if (i != std::end(mNodes))
        return *i;
    else
    {
        AX_LOG_CORE_CRITICAL(fmt::format("Tried to get node that doesn't exist uid = {0:d} .", uid));
        std::__throw_runtime_error("Node with the specified identifer does not exist.");
    }
}

std::list<Node>::iterator Graph::GetNodeIterator(unsigned int uid)
{
    auto i = std::find_if(mNodes.begin(), mNodes.end(), [&](const Node &val) { return val.GetUID() == uid; });
    if (i != std::end(mNodes))
        return i;
    else
    {
        AX_LOG_CORE_CRITICAL(fmt::format("Tried to get node that doesn't exist uid = {0:d} .", uid));
        std::__throw_runtime_error("Node with the specified identifer does not exist.");
    }
}

void Graph::AddNode(Node n)
{
    Graph::mNodes.push_back(std::move(n));
}

void Graph::DeleteNode(unsigned int uid)
{

    mNodes.erase(Graph::GetNodeIterator(uid));
}

std::vector<Node *> Graph::transverse()
{
    //reset all nodes to unvisited
    for (auto &node : mNodes)
    {
        node.isVisited = false;
    }

    auto nodes = std::vector<Node *>();
    auto currentNodes = std::vector<Node *>();
    auto nextNodes = std::deque<Node *>();
    //add the first layer which is nodes with no inputs
    for (auto &n : mNodes)
    {
        if (n.isStartNode())
        {
            nodes.push_back(&n);
            currentNodes.push_back(&n);
            n.isVisited = true;
        }
    }
    do
    {
        //adds next layer of nodes
        for (auto node : currentNodes)
        {
            for (auto &outSocket : node->GetOutputSockets())
            {
                for (auto inSocket : outSocket.LinkedSockets)
                {
                    if (inSocket->ParentNode->isInputsVisited())
                    {
                        inSocket->ParentNode->isVisited = true;
                        nextNodes.push_back(inSocket->ParentNode);
                    }
                }
            }
        }
        currentNodes.clear();
        //append the next layer to nodes and assign it as current layer
        for (auto node : nextNodes)
        {
            nodes.push_back(node);
            currentNodes.push_back(node);
        }
        nextNodes.clear();
    } while (currentNodes.size() != 0);
    return nodes;
}
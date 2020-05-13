/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#include "Graph.h"

/**
 * Graph implementation
 */

/**
 * @param identifier
 */
Node &Graph::GetNode(unsigned int identifier)
{
    for (auto &var : this->mNodes)
    {
        if (var.GetUID() == identifier)
            return var;
    }
}

std::list<Node>::iterator Graph::GetNodeIterator(unsigned int uid)
{
    auto i = mNodes.begin();
    do
    {
        if (i->GetUID() == uid)
            return i;
        i++;

    } while (i != mNodes.cend());
}

void Graph::SetupCache()
{
    for (auto &node : mNodes)
    {
        node.SetupCache();
    }
}

void Graph::ClearCache()
{
    for (auto &node : mNodes)
    {
        node.ClearCache();
    }
}

void Graph::DeleteCache()
{
    for (auto &node : mNodes)
    {
        node.DeleteCache();
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
        if (n.GetInputSockets().size() == 0)
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
                    (inSocket->ParentNode)->isVisited = true;
                    nextNodes.push_back((inSocket->ParentNode));
                }
            }
        }
        currentNodes.clear();
        //transverse uncought nodes
        {
            auto currentUncought = std::vector<Node *>();
            auto nextUncought = std::vector<Node *>();
            for (auto node : nextNodes)
            {
                for (auto &in : node->GetInputSockets())
                {
                    if (in.ParentNode->isVisited != true)
                    {
                        currentUncought.push_back(in.ParentNode);
                        nextNodes.push_front(in.ParentNode);
                    }
                }
            }
            do
            {
                for (auto node : currentUncought)
                {
                    for (auto &in : node->GetInputSockets())
                    {
                        if (in.ParentNode->isVisited != true)
                        {
                            nextUncought.push_back(in.ParentNode);
                            nextNodes.push_front(in.ParentNode);
                        }
                    }
                }
                currentUncought.clear();
                currentUncought = nextUncought;
                nextUncought.clear();
            } while (currentUncought.size() != 0);
        }
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
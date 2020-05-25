/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#include "Node.h"

/**
 * Node implementation
 * 
 * Generic node class.Node class defines basic common aspects of all kinds nodes.
 * Note:If you want to create new type of node graph system you should create derived node class from this as well as a specialized node tree,graph and sockets.
 */

Node::Node() {}

Node::Node(unsigned int _uid) : uid(_uid) {}

/**
 * Invalidate makes the current cache invalid and all  nodes based upon it.
 */
void Node::Invalidate()
{
    this->SetNeedUpdate(true);
    //Invalidates each nodes connected to the output sockets
    for (auto &outSocket : this->mOutputSockets)
    {
        for (auto &inSocket : outSocket.LinkedSockets)
        {
            inSocket->ParentNode->Invalidate();
        }
    }
}

/**
 * @param IdName
 * @return OutputSocket
 */
OutputSocket &Node::GetOutputSocket(unsigned int uid)
{
    for (auto &var : this->mOutputSockets)
    {
        if (var.uid == uid)
            return var;
    }
}

/**
 * @param IdName
 * @return InputSocket
 */
InputSocket &Node::GetInputSocket(unsigned int uid)
{
    for (auto &var : this->mInputSockets)
    {
        if (var.uid == uid)
            return var;
    }
}

/**
 * @return NodeUI
*/
NodeUI Node::GetUI()
{
    return NodeUI();
}

std::vector<OutputSocket> &Node::GetOutputSockets()
{
    return Node::mOutputSockets;
}

std::vector<InputSocket> &Node::GetInputSockets()
{
    return Node::mInputSockets;
}

bool Node::isInputsVisited()
{
    for (auto &i : mInputSockets)
    {
        if (i.LinkedSocket->ParentNode->isVisited == false)
            return false;
    }
    return true;
}

bool Node::isEndNode()
{
    //The node has no output socket so return true
    if (mOutputSockets.size() == 0)
    {
        return true;
    }
    //The node has output socket so check if they are connected
    else
    {
        for (auto &out : mOutputSockets)
        {
            //One of the output sockets has link so return false
            if (out.isLinked())
                return false;
        }
    }
    //Default
    return true;
}

bool Node::isStartNode()
{
    //The node has no input sockets so return true
    if (mInputSockets.size() == 0)
    {
        return true;
    }
    //The node has input socket so check if they has link
    else
    {
        for (auto &in : mInputSockets)
        {
            if (in.isLinked())
                return false;
        }
    }
    return true;
}
/**
 * Project Material Lab
 * @author Bruk Tedla
 */


#include "Node.h"

/**
 * Node implementation
 * 
 * Generic node class.Node class defines basic common aspects of all kinds nodes.
 * Note:If you want to create new type of node graph system you should create drived node class from this as well as a speciliazied node tree,graph and sockets.
 */


/**
 * Invalidate makes the current cache invalide and all  nodes based upon it.
 */
void Node::Invalidate() {

}

/**
 * @param IdName
 * @return OutputSocket
 */
OutputSocket& Node::GetOutputSocket(unsigned int uid) {
    for(auto &var : this->mOutputSockets)
    {
        if(var.uid == uid) return var;
    }
}

/**
 * @param IdName
 * @return InputSocket
 */
InputSocket& Node::GetInputSocket(unsigned int uid) {
    for(auto &var : this->mInputSockets)
    {
        if(var.uid == uid) return var;
    }
}

/**
 * @return NodeUI
*/
NodeUI Node::GetUI() {
    return NodeUI();
}

/**
 * Project Material Lab
 * @author Bruk Tedla
 */


#ifndef _NODEUI_H
#define _NODEUI_H

#include <vector>
#include "../../NodeGraph/Node.h"
#include "OutputSocketUI.h"
#include "InputSocketUI.h"

class Node;
class OutputSocketUI;
class InputSocketUI;

class NodeUI {
public: 
	std::vector<OutputSocketUI> mOutputSockts;
	std::vector<InputSocketUI> mInputSockets;
	Node *mNode;
};

#endif //_NODEUI_H

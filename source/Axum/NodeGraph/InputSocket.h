/**
 * Project Material Lab
 * @author Bruk Tedla
 */


#ifndef _INPUTSOCKET_H
#define _INPUTSOCKET_H
#include <string>
#include <vector>
#include "Node.h"
#include "OutputSocket.h"

class Node;
class OutputSocket;

class InputSocket {
public: 
	std::vector<OutputSocket*> LinkedSockets;
	Node *ParentNode;
	/**
	 * unique id 
	**/
	unsigned int uid;
	/**
	 *Name of the node to be displayed on ui
	 **/
	std::string UIName;
	
/**
 * @param *Socket
 */
void LinkTo(OutputSocket* Socket);
};

#endif //_INPUTSOCKET_H

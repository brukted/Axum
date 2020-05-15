/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#ifndef _INPUTSOCKET_H
#define _INPUTSOCKET_H
#include <string>
#include "Node.h"
#include "OutputSocket.h"

class Node;
class OutputSocket;

class InputSocket
{
public:
	OutputSocket *LinkedSocket = nullptr;
	Node *ParentNode = nullptr;
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
	void LinkTo(OutputSocket *);

	void Unlink();

	bool isLinked();
};

#endif //_INPUTSOCKET_H

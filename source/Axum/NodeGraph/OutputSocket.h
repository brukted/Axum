/**
 * Project Material Lab
 * @author Bruk Tedla
 */


#ifndef _OUTPUTSOCKET_H
#define _OUTPUTSOCKET_H

#include <vector>
#include <string>
#include "InputSocket.h"
#include "Node.h"

class Node;
class InputSocket;

class OutputSocket {
public: 
	std::vector<InputSocket*> LinkedSockets;
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
void LinkTo(OutputSocket *Socket);

//Initilizes data for live preview
virtual void SetupCache();

//Resets cache data
virtual void ClearCache();

//Deletes cache data
virtual void DeleteCache();
};

#endif //_OUTPUTSOCKET_H

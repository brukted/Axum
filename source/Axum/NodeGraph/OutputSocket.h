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

class OutputSocket
{
protected:
	/**
	 * @brief Unique identifer of this socket in the parent nodes output sockets.
	 * 
	 */
	unsigned int uid;

public:
	std::vector<InputSocket *> LinkedSockets;

	Node *ParentNode;

	/**
	 *Name of the node to be displayed on ui
	 **/
	std::string UIName;

	OutputSocket(std::string &_name, unsigned int _uid);

	OutputSocket(const char *_name, unsigned int _uid);

	/**
 * @param *Socket
 */
	void LinkTo(InputSocket *);

	void UnlinkFrom(unsigned int uid);

	void UnlinkFrom(InputSocket *);

	bool isLinked();

	inline unsigned int GetUID() { return uid; };
};

#endif //_OUTPUTSOCKET_H

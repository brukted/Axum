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
	friend class OutputSocket;

protected:
	/**
	 * @brief Unique identifer of this socket.
	 * 
	 */
	unsigned int uid;
	/**
	 * @brief Creates one sided link with @a socket
	 * 
	 *@param socket Source socket of the link
 	**/
	void HalfLink(OutputSocket *socket);

public:
	OutputSocket *LinkedSocket = nullptr;

	Node *ParentNode = nullptr;

	/**
	 *@brief Name of the node to be displayed on ui
	 **/
	std::string UIName;

	void Unlink();

	bool isLinked();

	inline unsigned int GetUID() { return uid; };
};

#endif //_INPUTSOCKET_H

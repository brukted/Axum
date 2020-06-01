/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#ifndef _CONNECTION_H
#define _CONNECTION_H

class Connection
{
public:
	Connection(unsigned int _FromNode, unsigned int _FromSocket, unsigned int _ToNode, unsigned int _ToSocket);
	/**
 * UID of the source node
 */
	unsigned int FromNode;
	/**
 * UID of the source socket in the source node
 */
	unsigned int FromSocket;
	/**
 * UID of the destination(sink) node
 */
	unsigned int ToNode;
	/**
 * UID of the destination(Sink)  socket.
 */
	unsigned int ToSocket;
};

#endif //_CONNECTION_H

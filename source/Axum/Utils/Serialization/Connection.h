/**
 * Project Material Lab
 * @author Bruk Tedla
 */


#ifndef _CONNECTION_H
#define _CONNECTION_H

class Connection {
public: 
	/**
 * UID of the source node
 */
long FromNode;
	/**
 * UID of the source socket in the source node
 */
long FromSocket;
	/**
 * UID of the destination(sink) node
 */
long ToNode;
	/**
 * UID of the destination(Sink)  socket.
 */
long ToSocket;
};

#endif //_CONNECTION_H

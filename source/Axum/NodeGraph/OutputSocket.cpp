/**
 * Project Material Lab
 * @author Bruk Tedla
 */


#include "OutputSocket.h"

/**
 * OutputSocket implementation
 * 
 * Generic Output socket containing common aspects of all output socket types.
 */


/**
 * @param *Socket
 */
void OutputSocket::LinkTo(InputSocket *socket) {
    this->LinkedSockets.push_back(socket);
}

void OutputSocket::SetupCache(){return;}

void OutputSocket::ClearCache(){return;}

void OutputSocket::DeleteCache(){return;}
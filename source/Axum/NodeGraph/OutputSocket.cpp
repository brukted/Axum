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
void OutputSocket::LinkTo(InputSocket *socket)
{
    this->LinkedSockets.push_back(socket);
}

void OutputSocket::UnlinkFrom(unsigned int uid)
{
    for (auto i = this->LinkedSockets.begin(); i < this->LinkedSockets.end(); i++)
    {
        if ((*i)->uid == uid)
            this->LinkedSockets.erase(i);
    }
}

void OutputSocket::UnlinkFrom(InputSocket *socket)
{
    for (auto i = this->LinkedSockets.begin(); i < this->LinkedSockets.end(); i++)
    {
        if ((*i)->uid == socket->uid)
            this->LinkedSockets.erase(i);
        if (i == this->LinkedSockets.end())
            break;
    }
}

bool OutputSocket::isLinked()
{
    if (LinkedSockets.size() == 0)
    {
        return false;
    }
    else
    {
        return true;
    }
}
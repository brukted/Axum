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
 * @brief Links the socket on both end
 * 
 * @param socket Destination(end) socket
 */
void OutputSocket::LinkTo(InputSocket *socket)
{
    this->LinkedSockets.push_back(socket);
    socket->HalfLink(this);
}

void OutputSocket::UnlinkFrom(unsigned int _uid)
{
    for (auto i = this->LinkedSockets.begin(); i < this->LinkedSockets.end(); i++)
    {
        if ((*i)->GetUID() == _uid)
            this->LinkedSockets.erase(i);
    }
}

void OutputSocket::UnlinkFrom(InputSocket *socket)
{
    for (auto i = this->LinkedSockets.begin(); i < this->LinkedSockets.end(); i++)
    {
        if ((*i)->GetUID() == socket->GetUID())
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

OutputSocket::OutputSocket(const char *_name, unsigned int _uid) : UIName(_name), uid(_uid) {}

OutputSocket::OutputSocket(std::string &_name, unsigned int _uid) : UIName(_name), uid(_uid) {}

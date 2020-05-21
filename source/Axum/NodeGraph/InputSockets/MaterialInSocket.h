/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#ifndef _MATERIALINSOCKET_H
#define _MATERIALINSOCKET_H

#include "../InputSocket.h"
#include "../Material.h"

class MaterialInSocket : public InputSocket
{
public:
	Channel dataType = Channel::RGB;
};

#endif //_MATERIALINSOCKET_H

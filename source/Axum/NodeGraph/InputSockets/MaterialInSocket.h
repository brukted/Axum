/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#ifndef _MATERIALINSOCKET_H
#define _MATERIALINSOCKET_H

#include "../InputSocket.h"

enum class Channel
{
	RGBA,
	RGB,
	R,
	G,
	B,
	A
};

class MaterialInSocket : public InputSocket
{
public:
	Channel dataType = Channel::RGB;
};

#endif //_MATERIALINSOCKET_H

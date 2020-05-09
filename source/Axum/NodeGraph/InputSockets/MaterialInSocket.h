/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#ifndef _MATERIALINSOCKET_H
#define _MATERIALINSOCKET_H

#include "../InputSocket.h"

enum DataType
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
	DataType channels;
};

#endif //_MATERIALINSOCKET_H

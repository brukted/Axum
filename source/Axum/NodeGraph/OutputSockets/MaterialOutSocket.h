/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#ifndef _MATERIALOUTSOCKET_H
#define _MATERIALOUTSOCKET_H

#include "../OutputSocket.h"
#include "../InputSockets/MaterialInSocket.h"

class MaterialOutSocket : public OutputSocket
{
public:
	DataType channels;
};

#endif //_MATERIALOUTSOCKET_H

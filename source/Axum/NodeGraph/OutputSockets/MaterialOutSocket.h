/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#ifndef _MATERIALOUTSOCKET_H
#define _MATERIALOUTSOCKET_H

#include "../OutputSocket.h"
#include "../InputSockets/MaterialInSocket.h"
#include "../Material.h"

class MaterialOutSocket : public OutputSocket
{
private:
	/**Id of the texture on gpu used for live preview execution
	 * exists only if setup cache is called it is 0 if not initalized
	**/
	unsigned int GPUtexture = 0;

public:
	Channel channels;
};

#endif //_MATERIALOUTSOCKET_H

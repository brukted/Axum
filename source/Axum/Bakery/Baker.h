/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#ifndef _BAKER_H
#define _BAKER_H

#include "BakerParams.h"
#include "BakeryParams.h"

class Baker
{
public:
	/**
 * The list of the baker's personal parameters.
 */
	BakerParams mParams;

	/**
 * @param *BakeryParms
 */
	void bake(BakeryParams *BakeryParms);
};

#endif //_BAKER_H

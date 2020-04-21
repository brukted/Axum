/**
 * Project Material Lab
 * @author Bruk Tedla
 */


#ifndef _BAKERY_H
#define _BAKERY_H

#include <vector>
#include "BakerParams.h"
#include "Baker.h"

class Bakery {
public: 
	BakeryParams Parms;
	std::vector<Baker> Bakers;
	
/**
 * Calls bake on all bakers.
 */
void Bake();
	
/**
 * @param baker
 */
void AddBaker(Baker baker);
};

#endif //_BAKERY_H

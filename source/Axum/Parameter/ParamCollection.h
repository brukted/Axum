/**
 * Project Material Lab
 * @author Bruk Tedla
 */


#ifndef _PARAMCOLLECTION_H
#define _PARAMCOLLECTION_H

#include <vector>
#include "Param.h"


class ParamCollection: public Param {
public: 
	std::vector<Param> Params;
	
/**
 * @param uid unique identifer of the parameter
 * @return a pointer to a sub parameter
 * 
 */
Param* GetParameter(unsigned int uid);
	
/**
 * @param Parameter
 */
void AddParameter(Param Parameter);
};

#endif //_PARAMCOLLECTION_H

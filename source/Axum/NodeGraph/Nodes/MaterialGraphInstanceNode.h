/**
 * Project Material Lab
 * @author Bruk Tedla
 */


#ifndef _MATERIALGRAPHINSTANCENODE_H
#define _MATERIALGRAPHINSTANCENODE_H

#include "MaterialNode.h"
#include "../MaterialGraph.h"

class MaterialGraphInstanceNode: public MaterialNode {
public: 
	MaterialGraph *Graph;
};

#endif //_MATERIALGRAPHINSTANCENODE_H

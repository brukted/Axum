/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#ifndef _MATERIALGRAPHINSTANCENODE_H
#define _MATERIALGRAPHINSTANCENODE_H

#include "../Node.h"
#include "../MaterialGraph.h"

namespace Axum::NodeGraph::Material{

class MaterialGraphInstanceNode : public Node
{
public:
	MaterialGraph *Graph;
};

}
#endif //_MATERIALGRAPHINSTANCENODE_H

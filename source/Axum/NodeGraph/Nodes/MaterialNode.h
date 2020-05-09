/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#ifndef _MATERIALNODE_H
#define _MATERIALNODE_H

#include "../Node.h"

class MaterialNode : public Node
{
public:
    /**
 * Submit your procssing kernel and arguments to the flow graph here.Material Nodes should override this.
 * @param *flowGraph
 */
    virtual void AddToFlowGraph();
};

#endif //_MATERIALNODE_H

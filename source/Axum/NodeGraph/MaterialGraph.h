/**
 * Project Material Lab
 * @author Bruk Tedla
 */


#ifndef _MATERIALGRAPH_H
#define _MATERIALGRAPH_H

#include "Graph.h"


class MaterialGraph: public Graph {
public:
virtual void SetupCache() override;
virtual void ClearCache() override;
virtual void DeleteCache() override;
};

#endif //_MATERIALGRAPH_H

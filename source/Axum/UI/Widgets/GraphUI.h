/**
 * Project Material Lab
 * @author Bruk Tedla
 */


#ifndef _GRAPHUI_H
#define _GRAPHUI_H

#include <vector>
#include "NodeUI.h"
#include "NodeLinkUI.h"
#include "../../NodeGraph/Graph.h"

class GraphUI {
public: 
	std::vector<NodeUI> UINodes;
	std::vector<NodeLinkUI> UILinks;
	Graph *mGraph;
};

#endif //_GRAPHUI_H

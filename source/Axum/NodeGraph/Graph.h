/**
 * Project Material Lab
 * @author Bruk Tedla
 */


#ifndef _GRAPH_H
#define _GRAPH_H

#include<vector>
#include "../Resources/Resource.h"
#include "Node.h"
#include "../Parameter/GraphParam.h"

class Graph: public Resource {
public: 
	/**
	 * List of parameters that nodes in the node tree can refer to.
 	*/
	GraphParam mParms;
	std::vector<Node> mNodes;
	
/**
 * @param Identifier
 */
Node* GetNode(unsigned int uid);
	
/**
 * @param node
 */
void AddNode(Node node);
	
/**
 * @param identifier
 */
void DeleteNode(unsigned int uid);
	
void SetupCache();
	
void ClearCache();
	
void DeleteCache();
};

#endif //_GRAPH_H

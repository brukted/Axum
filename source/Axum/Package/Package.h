/**
 * Project Material Lab
 * @author Bruk Tedla
 */


#ifndef _PACKAGE_H
#define _PACKAGE_H

#include<vector>
#include"../NodeGraph/Graph.h"
#include"../Resources/Resource.h"

class Package {
public: 
	std::vector<Resource> Resources;
	
/**
 * @param graph
 */
void AddGraph(Graph graph);
	
/**
 * @param UUID
 */
void DeleteGraph(int UUID);
	
/**
 * @param UUID
 */
Resource* GetResource(int UUID);
};

#endif //_PACKAGE_H

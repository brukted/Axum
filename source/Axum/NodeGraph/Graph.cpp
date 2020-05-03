/**
 * Project Material Lab
 * @author Bruk Tedla
 */


#include "Graph.h"

/**
 * Graph implementation
 */


/**
 * @param identifier
 */
Node& Graph::GetNode(unsigned int identifier) {
for(auto &var : this->mNodes)
{
    if(var.GetUID() == identifier) return var;
}
}

void Graph::SetupCache() {
    for(auto &node : mNodes)
    {
        node.SetupCache();
    }
}

void Graph::ClearCache() {
    for(auto &node : mNodes)
    {
        node.ClearCache();
    }
}

void Graph::DeleteCache() {
    for(auto &node : mNodes)
    {
        node.DeleteCache();
    }
}
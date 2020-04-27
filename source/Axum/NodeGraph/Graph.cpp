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
    if(var.uid == identifier) return var;
}
}

void Graph::SetupCache() {

}

void Graph::ClearCache() {

}

void Graph::DeleteCache() {

}
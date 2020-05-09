/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#include "MaterialGraph.h"

/**
 * MaterialGraph implementation
 */

MaterialGraph::MaterialGraph()
{
}

void MaterialGraph::SetupCache()
{
    this->::Graph::SetupCache();
}
void MaterialGraph::ClearCache()
{
    this->::Graph::ClearCache();
}
void MaterialGraph::DeleteCache()
{
    this->Graph::DeleteCache();
}
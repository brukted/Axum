/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#include "MaterialGraph.h"

/**
 * MaterialGraph implementation
 */

namespace Axum {
namespace NodeGraph::Material {

MaterialGraph::MaterialGraph() {
  name.setValue(_("Untitled Material Graph"));
  this->type = Type::MaterialGraph;
}

} // namespace NodeGraph::Material
} // namespace Axum
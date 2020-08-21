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

MaterialGraph::MaterialGraph(unsigned int _uid) : Graph(_uid) {}

void MaterialGraph::SetupCache() {
  for (auto &n : mNodes) {
    static_cast<MaterialNode &>(n).SetupCache();
  }
}

void MaterialGraph::DeleteCache() {
  for (auto &n : mNodes) {
    static_cast<MaterialNode &>(n).DeleteCache();
  }
}

void MaterialGraph::Process() {
  auto nodes = this->transverse();
  for (auto n : nodes) {
    static_cast<MaterialNode *>(n)->Excute();
  }
}

} // namespace NodeGraph::Material
} // namespace Axum
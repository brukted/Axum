/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#include "MaterialGraph.h"

/**
 * MaterialGraph implementation
 */

using namespace Axum::NodeGraph::Material;

MaterialGraph::MaterialGraph(unsigned int _uid) : Graph(_uid) {
  size.AddParameter(&width);
  size.AddParameter(&height);
  defaultParams.AddParameter(&size);
  defaultParams.AddParameter(&imageFormat);
  defaultParams.AddParameter(&seed);
  mParams.AddParameter(&defaultParams);
}

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
/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#include "MaterialNode.h"

/**
 * MaterialNode implementation
 *
 * A base class for all material nodes such as texture,normal etc.
 */

namespace Axum::NodeGraph::Material {

MaterialNode::MaterialNode() {}

MaterialNode::MaterialNode(unsigned int _uid) : Node(_uid) {}

void MaterialNode::SetupCache() {
  for (auto &socket : mOutputSockets) {
    static_cast<MaterialOutSocket &>(socket).SetupCache();
  }
}

void MaterialNode::DeleteCache() {
  for (auto &socket : mOutputSockets) {
    static_cast<MaterialOutSocket &>(socket).DeleteCache();
  }
}

void MaterialNode::Excute() { return; }

void MaterialNode::ExcuteForward() {
  for (auto var : mInputSockets) {
    if (var.LinkedSocket->ParentNode->GetNeedUpdate() == true) {
      return; //* Do nothing inputs are not satisfied yet
    }
  }

  Excute();
  for (auto &socket : mOutputSockets) {
    for (auto inSocket : socket.LinkedSockets) {
      static_cast<MaterialNode &>(*(inSocket->ParentNode)).ExcuteForward();
    }
  }
}
} // namespace Axum::NodeGraph::Material
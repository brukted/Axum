/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#include "InputSocket.h"

namespace Axum::NodeGraph {

void InputSocket::HalfLink(OutputSocket *socket) { linkedSocket = socket; }

InputSocket::InputSocket(int uid, Node *parentNode, std::string_view uiName,
                         DataType type)
    : ParentNode(parentNode), uid(uid), UIName(uiName), type(type) {}

void InputSocket::halfUnlink() { linkedSocket = nullptr; }

bool InputSocket::isLinked() { return linkedSocket != nullptr; }

} // namespace Axum::NodeGraph
/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#ifndef _OUTPUTSOCKETUI_H
#define _OUTPUTSOCKETUI_H

#include "../../NodeGraph/OutputSocket.h"

namespace NodeGraph = Axum::NodeGraph;

namespace Axum {

namespace NodeGraph {
class OutputSocket;
}

namespace UI::Widget {

class OutputSocketUI {
public:
  NodeGraph::OutputSocket *Socket;
};

} // namespace UI::Widget
} // namespace Axum
#endif //_OUTPUTSOCKETUI_H

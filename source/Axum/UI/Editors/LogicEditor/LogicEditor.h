/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#ifndef _LOGIC_EDITOR_H
#define _LOGIC_EDITOR_H

#include "../Editor.h"

namespace Axum::UI {
namespace Editor {

class LogicEditor : public Editor {
public:
  LogicEditor();
  void draw() override;
};

} // namespace Editor
} // namespace Axum::UI
#endif //_LOGIC_EDITOR_H

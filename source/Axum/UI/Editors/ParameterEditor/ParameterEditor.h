/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#ifndef _PARAMETEREditor_H
#define _PARAMETEREditor_H

#include "../Editor.h"
#include "Parameter/Param.h"

namespace Axum::UI {
namespace Editor {

class ParameterEditor : public Editor {
public:
  UI::Widget::ParamUI mParamUI;
  ParameterEditor();

  /**
   * Displays @a param in UI.
   * @param *param Parameter to display.
   */
  static void BindParam(Parameter::Param *param);
};

} // namespace Editor
} // namespace Axum::UI
#endif //_PARAMETEREditor_H

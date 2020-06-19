/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#ifndef _PARAMETEREditor_H
#define _PARAMETEREditor_H

#include "../Editor.h"
#include "Parameter/Param.h"
#include "UI/Widgets/ParamUI.h"

namespace Axum::UI {
namespace Editor {

class ParameterEditor : public Editor {
public:
  UI::Widget::ParamUI mParamUI;
  ParameterEditor();

  /**
   * Builds the appropirate ui for the parameter collection.
   * @param *param
   */
  void BindParm(Parameter::Param *param);
};

} // namespace Editor
} // namespace Axum::UI
#endif //_PARAMETEREditor_H

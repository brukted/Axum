/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#ifndef _PARAMETER_EDITOR_H
#define _PARAMETER_EDITOR_H

#include "../Editor.h"
#include "Utils/Log/Log.h"
#include "Parameter/Param.h"
#include <list>
#include <vector>
#include "Utils/Translation/Translation.h"

namespace Axum::UI {
namespace Editor {

class ParameterEditor : public Editor {
private:
  static std::vector<Parameter::Param*> boundParameters;

public:
  ParameterEditor();

  void draw() override;

  /**
   * Displays @a param in UI.
   * @param *param Parameter to display.
   */
  static void BindParam(Parameter::Param *param);
  
  /**
   * Displays @a param in UI.
   * @param *param Parameter to display.
   */
  static void BindParams(std::vector<Parameter::Param *> params);

  /**
   * @brief Unbinds whatever parameter is bound.
   * 
   */
  static void Unbind();
};



} // namespace Editor
} // namespace Axum::UI
#endif //_PARAMETER_EDITOR_H

/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#ifndef _PARAMETER_EDITOR_H
#define _PARAMETER_EDITOR_H

#include "../Editor.h"
#include "Log.h"
#include "Parameter/Param.h"
#include <list>

namespace Axum::UI {
namespace Editor {

class ParameterEditor : public Editor {
private:
  static sigc::signal<void(Parameter::Param &)> OnBindParam;
  static sigc::signal<void(std::list<Parameter::Param *>)> OnBindParams;
  static sigc::signal<void()> OnUnbind;
  Gtk::Box box;
  void OnBindParameter(Parameter::Param &param);
  void OnBindParameters(std::list<Parameter::Param *> params);
  void OnUnbind_();

public:
  ParameterEditor();

  /**
   * Displays @a param in UI.
   * @param *param Parameter to display.
   */
  static void BindParam(Parameter::Param &param);
  
  /**
   * Displays @a param in UI.
   * @param *param Parameter to display.
   */
  static void BindParams(std::list<Parameter::Param *> params);

  /**
   * @brief Unbinds whatever parameter is bound.
   * 
   */
  static void Unbind();
};



} // namespace Editor
} // namespace Axum::UI
#endif //_PARAMETER_EDITOR_H

/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#include "ParameterEditor.h"

/**
 * ParameterEditor implementation
 */

namespace Axum::UI::Editor {
sigc::signal<void(Parameter::Param &)> ParameterEditor::OnBindParam;
sigc::signal<void(std::vector<Parameter::Param *>)> ParameterEditor::OnBindParams;
sigc::signal<void()> ParameterEditor::OnUnbind;

void ParameterEditor::OnBindParameter(Parameter::Param &param) {
  OnUnbind_();
  auto ParamUI = param.Draw();
  box.pack_end(*ParamUI);
  this->show_all();
}

void ParameterEditor::OnBindParameters(std::vector<Parameter::Param *> params) {
  OnUnbind_();
  auto ParamUIList = new Gtk::Box(Gtk::ORIENTATION_VERTICAL);
  for (auto param : params) {
    ParamUIList->add(*param->Draw());
  }
  box.pack_end(*ParamUIList);
  this->show_all();
}

void ParameterEditor::BindParam(Parameter::Param &param) {
  OnBindParam.emit(param);
}

void ParameterEditor::BindParams(std::vector<Parameter::Param *> params) {
  OnBindParams.emit(params);
}

void ParameterEditor::Unbind() { OnUnbind.emit(); }

void ParameterEditor::OnUnbind_() {
  auto widgets = box.get_children();
  for (auto widget : widgets) {
    box.remove(*widget);
    // Have to delete widget manually because gtk doesn't manage it if it
    // doesn't have parent widget
    delete widget;
  }
}

ParameterEditor::ParameterEditor()
    : Editor("Parameter Editor", "Parameter Editor") {
  space.add(box);
  OnBindParam.connect(sigc::mem_fun(*this, &OnBindParameter));
  OnBindParams.connect(sigc::mem_fun(*this, &OnBindParameters));
  OnUnbind.connect(sigc::mem_fun(*this, &OnUnbind_));
  this->show_all();
}
} // namespace Axum::UI::Editor
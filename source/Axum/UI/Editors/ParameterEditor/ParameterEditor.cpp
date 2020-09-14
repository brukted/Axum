/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#include "ParameterEditor.h"

/**
 * ParameterEditor implementation
 */

namespace Axum::UI::Editor {
std::vector<Parameter::Param *> ParameterEditor::boundParameters;

void ParameterEditor::BindParam(Parameter::Param *param) {
  Unbind();
  boundParameters.push_back(param);
}

void ParameterEditor::BindParams(std::vector<Parameter::Param *> params) {
  Unbind();
  boundParameters.insert(boundParameters.end(), params.begin(), params.end());
}

void ParameterEditor::Unbind() { boundParameters.clear(); }

ParameterEditor::ParameterEditor()
    : Editor("Parameter Editor", "Parameter Editor") {}

void ParameterEditor::draw() {
  ImGui::Begin(_("Parameter Editor"), 0);
  for (auto parameter : boundParameters) {
    parameter->draw();
  }
  ImGui::End();
}
} // namespace Axum::UI::Editor
/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#include "ParameterEditor.h"

/**
 * ParameterEditor implementation
 */

namespace Axum::UI::Editor {
ParameterEditor::ParameterEditor() {}

std::vector<ParameterEditor::ParameterGroup> ParameterEditor::boundParameters;

void ParameterEditor::BindParam(Parameter::Param *param) {
  Unbind();
  boundParameters.push_back(ParameterGroup(param->group, {param}));
}

void ParameterEditor::BindParams(std::vector<Parameter::Param *> params) {
  Unbind();
  for (auto *param : params) {
    bool b = false;
    for (auto &paramGroup : boundParameters) {
      if (std::get<0>(paramGroup) == param->group) {
        std::get<1>(paramGroup).push_back(param);
        b = true;
        break;
      }
    }
    if (!b) {
      boundParameters.push_back(ParameterGroup(param->group, {param}));
    }
  }
}

void ParameterEditor::Unbind() { boundParameters.clear(); }

void ParameterEditor::draw() {
  ImGui::Begin(_("Parameter Editor"), 0);
  for (auto paramGroup : boundParameters) {
    if (ImGui::TreeNode(std::get<0>(paramGroup).c_str())) {
      for (auto *param : std::get<1>(paramGroup)) {
        param->draw();
      }
      ImGui::TreePop();
    }
    // parameter->draw();
  }
  ImGui::End();
}
} // namespace Axum::UI::Editor
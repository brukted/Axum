/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#include "ParamCollection.h"

/**
 * ParamCollection implementation
 *
 * List of parameters.
 */

namespace Axum::Parameter {
ParamCollection::ParamCollection(std::string_view ID, std::string_view name,
                                 std::vector<Param *> params,
                                 std::string_view description, std::string_view group)
    : Param(ID, name, description,group) {
  for (auto *param : params) {
    this->params.emplace_back(param);
  }
}

Param &ParamCollection::findParameter(std::string_view ID) {
  for (auto &param : params) {
    if ((param->ID == ID))
      return *param.get();
  }
  AX_LOG_CORE_ERROR("Parameter collection ID : {} is requested a "
                    "non-existent parameter ID: {} .",
                    this->ID, ID)
  throw "Parameter doesn't exist";
}

void ParamCollection::AddParameter(Param *parameter) {
  params.emplace_back(parameter);
}

void ParamCollection::drawDisplay() {
  /*
  if (ImGui::CollapsingHeader(name.c_str())) {
    for (auto &parameter : params) {
      parameter->draw();
    }
  }*/
}
} // namespace Axum::Parameter
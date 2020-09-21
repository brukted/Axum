#include "ParameterGroup.h"

namespace Axum::Parameter {
ParameterGroup::ParameterGroup(std::vector<Param *> params,
                               std::string_view name,
                               std::string_view description)
    : params(params), Param("", name, description) {}

void ParameterGroup::drawDisplay() {
  for (auto *param : params) {
    assert((param != nullptr));
    param->draw();
  }
}

} // namespace Axum::Parameter
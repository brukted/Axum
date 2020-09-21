/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#include "FloatVectorParam.h"

/**
 * FloatVectorParam implementation
 */

namespace Axum::Parameter {
FloatVectorParam::FloatVectorParam(std::string_view ID, std::string_view name,
                                   std::string_view description, int size,
                                   std::vector<float> value, Type type,
                                   float uiMin, float uiMax, float hardMin,
                                   float hardMax)
    : Param(ID, name, description), size(size), type(type), hardMax(hardMax),
      hardMin(hardMin), uiMin(uiMin), uiMax(uiMax), value(value) {
  assert(value.size() == size);
}

std::vector<float> FloatVectorParam::getValue() const { return value; }

void FloatVectorParam::setValue(std::vector<float> value) {
  assert((value.size() == size));
  this->value = value;
}

void FloatVectorParam::drawDisplay() { return; }

} // namespace Axum::Parameter
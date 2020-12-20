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
                                   std::string_view description, std::string_view group, int size,
                                   std::vector<float> value, Type type,
                                   float uiMin, float uiMax, float hardMin,
                                   float hardMax)
    : Param(ID, name, description,group), size(size), type(type), hardMax(hardMax),
      hardMin(hardMin), uiMin(uiMin), uiMax(uiMax), value(value) {
  assert(value.size() == size);
}

std::vector<float> FloatVectorParam::getValue() const { return value; }

void FloatVectorParam::setValue(std::vector<float> _value) {
  assert((_value.size() == size));
  value = _value;
  valueChanged();
}

void FloatVectorParam::drawDisplay() { return; }

} // namespace Axum::Parameter
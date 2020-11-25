/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#include "IntegerVectorParam.h"

/**
 * Integer2Param implementation
 */

namespace Axum::Parameter {
IntegerVectorParam::IntegerVectorParam(std::string_view ID,
                                       std::string_view name,
                                       std::string_view description, int size,
                                       std::vector<int> value, int uiMin,
                                       int uiMax, int hardMin, int hardMax)
    : Param(ID, name, description), size(size), hardMax(hardMax),
      hardMin(hardMin), uiMin(uiMin), uiMax(uiMax), value(value) {
  assert((size == value.size()));
}

std::vector<int> IntegerVectorParam::getValue() const { return value; }

void IntegerVectorParam::setValue(std::vector<int> _value) {
  assert((_value.size() == size));
  value = _value;
  valueChanged();
}

void IntegerVectorParam::drawDisplay() { return; }

} // namespace Axum::Parameter
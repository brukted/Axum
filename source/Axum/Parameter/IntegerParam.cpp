/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#include "IntegerParam.h"

/**
 * IntegerParam implementation
 */

namespace Axum::Parameter {
void IntegerParam::drawDisplay() { return; }

IntegerParam::IntegerParam(std::string_view ID, int value,
                           std::string_view name, std::string_view description)
    : Param(ID, name, description), value(value) {}

int IntegerParam::getValue() const { return value; }

void IntegerParam::setValue(int value) { this->value = value; }

} // namespace Axum::Parameter
/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#include "Param.h"

/**
 * Param implementation
 *
 */

namespace Axum::Parameter {

Param::Param(std::string_view ID, std::string_view name,
             std::string_view description)
    : ID(ID), name(name), description(description) {
  // name should not be empty for proper ui event handling
  if (name == "")
    this->name = ID;
}

void Param::draw() {
  if (isEditMode)
    return drawEdit();
  else
    return drawDisplay();
}

void Param::drawDisplay() { return; }

void Param::drawEdit() { return; }

} // namespace Axum::Parameter
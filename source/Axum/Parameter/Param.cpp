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

Param::Param(std::string ID, const std::string &_name, std::string group = "")
    : ID(ID), name(_name), group(group) {}

Param::Param(std::string ID, const char *_name, std::string group = "")
    : ID(ID), name(_name), group(group) {}

void Param::draw() {
  if (isEditMode)
    return drawEdit();
  else
    return drawDisplay();
}

void Param::drawDisplay() { return; }

void Param::drawEdit() { return; }

} // namespace Axum::Parameter
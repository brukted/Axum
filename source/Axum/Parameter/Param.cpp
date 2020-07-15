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

Param::Param(unsigned int _uid) : uid(_uid) {}

Param::Param(unsigned int _uid, std::string &_name) : uid(_uid), name(_name) {}

Param::Param(unsigned int _uid, const char *_name) : uid(_uid), name(_name) {}

Param::Param(std::string &_name) : name(_name) {}

Param::Param(const char *_name) : name(_name) {}

void Param::DrawEdit(UI::Widget::ParamUI *ui) {}

void Param::DrawDisplay(UI::Widget::ParamUI *ui) {}

std::string &Param::getName() { return name; }

void Param::SetName(std::string &_name) { this->name = _name; }

void Param::SetName(const char *_name) { this->name.assign(_name); }

unsigned int Param::GetUID() { return uid; }

} // namespace Axum::Parameter
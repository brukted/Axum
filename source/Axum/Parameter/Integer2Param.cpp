/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#include "Integer2Param.h"

/**
 * Integer2Param implementation
 */

Integer2Param::Integer2Param(unsigned int _uid, std::string &_name, std::array<int, 2> _value) : value(_value), Param(_uid, _name) {}

Integer2Param::Integer2Param(unsigned int _uid, const char *_name, std::array<int, 2> _value) : value(_value), Param(_uid, _name) {}

std::array<int, 2> Integer2Param::GetValue() const
{
   return this->value;
}

void Integer2Param::SetValue(std::array<int, 2> value)
{
   this->value = value;
   this->OnValueChanged.emit();
}
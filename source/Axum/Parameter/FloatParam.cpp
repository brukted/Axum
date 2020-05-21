/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#include "FloatParam.h"

/**
 * FloatParam implementation
 */
FloatParam::FloatParam(unsigned int _uid, std::string &_name, float _value) : value(_value), Param(_uid, _name) {}

FloatParam::FloatParam(unsigned int _uid, const char *_name, float _value) : value(_value), Param(_uid, _name) {}

float FloatParam::GetValue() const
{
   return this->value;
}

void FloatParam::SetValue(float value)
{
   this->value = value;
}
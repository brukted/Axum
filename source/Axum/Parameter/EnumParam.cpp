/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#include "EnumParam.h"

/**
 * EnumParam implementation
 */

EnumParam::EnumParam(unsigned int _uid, std::string &_name, std::map<int, std::string> _enums, int _value) : enums(_enums), value(_value), Param(_name) {}

EnumParam::EnumParam(unsigned int _uid, const char *_name, std::map<int, std::string> _enums, int _value) : enums(_enums), value(_value), Param(_name) {}

int EnumParam::SetValue() const
{
	return this->value;
}

void EnumParam::SetValue(int key)
{
	this->value = key;
}

std::string &EnumParam::ToString(int key)
{
	return this->enums[key];
}
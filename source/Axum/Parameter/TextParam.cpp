/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#include "TextParam.h"

/**
 * TextParam implementation
 */

TextParam::TextParam(unsigned int _uid)
{
	this->uid = _uid;
}

std::string &TextParam::GetValue()
{
	return this->value;
}

void TextParam::SetValue(std::string &value)
{
	this->value = value;
}

void TextParam::setValue(const char *name)
{
	this->value.assign(name);
}

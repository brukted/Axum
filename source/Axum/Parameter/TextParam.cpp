/**
 * Project Material Lab
 * @author Bruk Tedla
 */


#include "TextParam.h"

/**
 * TextParam implementation
 */

std::string& TextParam::GetValue() {
	return this->value;
}

void TextParam::SetValue(std::string &value) {
	this->value = value;
}
/**
 * Project Material Lab
 * @author Bruk Tedla
 */


#include "FloatParam.h"

/**
 * FloatParam implementation
 */

 float FloatParam::GetValue() const {
    return this->value;
 }

 void FloatParam::SetValue(float value) {
    this->value = value;
 }
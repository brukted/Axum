/**
 * Project Material Lab
 * @author Bruk Tedla
 */


#include "EnumParam.h"

/**
 * EnumParam implementation
 */
EnumParam::EnumParam(std::map<int,std::string> enums){
    this->enums = std::move(enums);
}
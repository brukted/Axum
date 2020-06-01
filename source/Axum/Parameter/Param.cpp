/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#include "Param.h"

/**
 * Param implementation
 * 
 * GUI editable attribute of an object.Holds the data and method to show the attribute to the user.
 */

Param::Param(unsigned int _uid) : uid(_uid) {}

Param::Param(unsigned int _uid, std::string &_name) : uid(_uid), name(_name) {}

Param::Param(unsigned int _uid, const char *_name) : uid(_uid), name(_name) {}

Param::Param(std::string &_name) : name(_name) {}

Param::Param(const char *_name) : name(_name) {}

/**
 * Displays the data to the ui.
 * @return ParamUI
 */
ParamUI Param::GetEditUI()
{
    return (ParamUI());
}

/**
 * @return ParamUI
 */
ParamUI Param::GetDisplayUI()
{
    return ParamUI();
}

std::string &Param::getName()
{
    return name;
}

void Param::setName(std::string &_name)
{
    this->name = _name;
}

void Param::setName(const char *_name)
{
    this->name.assign(_name);
}

unsigned int Param::getUid()
{
    return uid;
}
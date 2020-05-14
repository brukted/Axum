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

void Param::setName(std::string &name)
{
    this->name = name;
}

void Param::setName(const char *name)
{
    this->name.assign(name);
}

unsigned int Param::getUid()
{
    return uid;
}
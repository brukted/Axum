/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#ifndef _OPERATOR_H
#define _OPERATOR_H

#include <string>

class Operator
{
public:
	std::string Name;
	std::string IdName;

	virtual void Excute();

	virtual void Undo();

	virtual void Redo();
};

#endif //_OPERATOR_H

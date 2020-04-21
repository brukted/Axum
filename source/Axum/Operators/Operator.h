/**
 * Project Material Lab
 * @author Bruk Tedla
 */


#ifndef _OPERATOR_H
#define _OPERATOR_H

class Operator {
public: 
	char16_t Name;
	char16_t IdName;
	
void Excute();
	
void Undo();
	
void Redo();
};

#endif //_OPERATOR_H

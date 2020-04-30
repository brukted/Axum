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
	
virtual void Excute();
	
virtual void Undo();
	
virtual void Redo();
};

#endif //_OPERATOR_H

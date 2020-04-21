/**
 * Project Material Lab
 * @author Bruk Tedla
 */


#ifndef _FUNCTIONNODE_H
#define _FUNCTIONNODE_H

#include<string>
#include "../Node.h"


class FunctionNode: public Node {
public: 
	
/**
 * Add your code here.
 * @param *SourceCode The compiled shader code will be returned to here.
 */
virtual void Compile(std::string &SourceCode) ;
};

#endif //_FUNCTIONNODE_H

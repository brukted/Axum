/**
 * Project Material Lab
 * @author Bruk Tedla
 */


#ifndef _NODELINKUI_H
#define _NODELINKUI_H

#include"../../NodeGraph/OutputSocket.h"
#include"../../NodeGraph/InputSocket.h"

class NodeLinkUI {
public: 
	OutputSocket *From;
	InputSocket *To;
};

#endif //_NODELINKUI_H

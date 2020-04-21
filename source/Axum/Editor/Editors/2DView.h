/**
 * Project Material Lab
 * @author Bruk Tedla
 */


#ifndef _2DVIEW_H
#define _2DVIEW_H

#include "../Editor.h"
#include "../../Resources/Bitmap.h"
#include "../../NodeGraph/InputSockets/MaterialInSocket.h"
#include "../../NodeGraph/OutputSockets/MaterialOutSocket.h"

class _2DView: public Editor {
public: 
	
/**
 * @param *socket
 */
void Display(MaterialOutSocket *socket);
	
/**
 * @param *socket
 */
void Display(MaterialInSocket *socket);
	
/**
 * @param *texture
 */
void Display(Bitmap *texture);
};

#endif //_2DVIEW_H

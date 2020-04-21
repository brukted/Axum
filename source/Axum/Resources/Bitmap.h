/**
 * Project Material Lab
 * @author Bruk Tedla
 */


#ifndef _BITMAP_H
#define _BITMAP_H

#include<vector>
#include "Resource.h"


class Bitmap: public Resource {
	enum Format {  };
public: 
	std::vector<unsigned char> Data;
	Format mFormat;
};

#endif //_BITMAP_H

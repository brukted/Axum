/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#ifndef _IMAGETEXTURE_H_
#define _IMAGETEXTURE_H_

#include <vector>
#include "Resource.h"

class ImageTexture : public Resource
{
	enum Format
	{
	};

public:
	std::vector<unsigned char> Data;
	Format mFormat;
};

#endif //_IMAGETEXTURE_H_

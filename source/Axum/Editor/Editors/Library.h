/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#ifndef _LIBRARY_H
#define _LIBRARY_H

#include <string>
#include "../Editor.h"

class Library : public Editor
{
	class ThumbnailBuilder
	{
	public:
		static void RebuildChache();

		/**
 	* @param path
	*/
	public:
		static void GetThumbnail(std::string path);
	};

public:
	ThumbnailBuilder mThumbnailBuilder;
};

#endif //_LIBRARY_H

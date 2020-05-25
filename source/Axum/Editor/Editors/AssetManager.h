/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#ifndef _ASSETMANAGER_H_
#define _ASSETMANAGER_H_

#include <string>
#include "../Editor.h"

class AssetManager : public Editor
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

#endif //_ASSETMANAGER_H_

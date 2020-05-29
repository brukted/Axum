/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#ifndef _PACKAGE_H
#define _PACKAGE_H

#include <vector>
#include "../NodeGraph/Graph.h"
#include "../Resources/Resource.h"
#include "boost/serialization/access.hpp"
#include "boost/serialization/base_object.hpp"
#include "boost/serialization/vector.hpp"
#include "boost/serialization/version.hpp"
#include "boost/serialization/split_member.hpp"
#include "boost/serialization/list.hpp"
#include "boost/archive/text_iarchive.hpp"
#include <fstream>
#include "pathUtils.h"

class Package : public Resource
{
	friend class boost::serialization::access;

public:
	std::list<Resource> Resources;

	/**
	 * @brief Get the Resource with the specified uid.
	 * 
	 * @param uid Unique identifier of the resource.
	 * @return Resource& reference to the resource by uid.
	 */
	Resource &GetResource(unsigned int uid);

private:
	template <class Archive>
	void save(Archive &ar, const unsigned int version) const
	{
		ar &boost::serialization::base_object<Resource>(*this);
		if (this->resourceType == ResourceType::Embedded)
			ar &Resources;
	}

	template <class Archive>
	void load(Archive &ar, const unsigned int version)
	{
		ar &boost::serialization::base_object<Resource>(*this);
		if (this->resourceType == ResourceType::Embedded)
		{
			ar &Resources;
		}
		else
		{
			/**
			 * @brief Path replaced internal dependency uri with proper path eg: AX://test.pkg -> "$resourcesPath"/packages/test.pkg
			 * 
			 */
			std::string formattedPath = mPath;
			std::size_t i = formattedPath.find("AX://");
			if (i != formattedPath.npos)
				formattedPath.replace(, 5, (PathUtils::resourcesPath + "/"));
			std::ifstream ifs(std::move(formattedPath));
			boost::archive::text_iarchive ia(ifs);
			ia >> *this;
		}
	}
	BOOST_SERIALIZATION_SPLIT_MEMBER()
};
BOOST_CLASS_VERSION(Package, 1)
#endif //_PACKAGE_H

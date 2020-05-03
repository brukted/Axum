/**
 * Project Material Lab
 * @author Bruk Tedla
 */


#ifndef _RESOURCE_H
#define _RESOURCE_H

#include<string>
#include"../UI/Widgets/ExplorerItemUI.h"
#include "boost/serialization/access.hpp"
#include "boost/serialization/split_member.hpp"
#include "boost/serialization/string.hpp"
#include "boost/serialization/version.hpp"
#include "boost/serialization/vector.hpp"

class Resource {
	enum ResourceType { Linked, Embedded };
	enum PathType { Relative, Absolute };
public: 
	std::string Name;
	ResourceType mType;
	/**
 * Path to the resource if it is linked type.
 */
	std::string mPath;
	unsigned int uid;
	PathType mPathType;
	
/**
 * Opens the resource in the appropirate editor.
 */
virtual void Open();
	
/**
 * Returns a UI to display the resource the UI is an instance odf ExplorerItemUI or child of it.
 */
ExplorerItemUI GetUI();
private:
template<class Archive>
void save(Archive & ar, const unsigned int version) const
{
	ar &Name;
	ar &mType;
	ar &mPath;
	ar &uid;
	ar &mPathType;
}

template<class Archive>
void load(Archive & ar, const unsigned int version)
{
	ar &Name;
	ar &mType;
	ar &mPath;
	ar &uid;
	ar &mPathType;
}
BOOST_SERIALIZATION_SPLIT_MEMBER()
};
BOOST_CLASS_VERSION(Resource,1)
#endif //_RESOURCE_H

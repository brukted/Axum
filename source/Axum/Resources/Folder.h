/**
 * Project Material Lab
 * @author Bruk Tedla
 */


#ifndef _FOLDER_H
#define _FOLDER_H

#include<vector>
#include "Resource.h"
#include "boost/serialization/access.hpp"
#include "boost/serialization/version.hpp"
#include "boost/serialization/vector.hpp"
#include "boost/serialization/split_free.hpp"
#include "boost/serialization/base_object.hpp"
class Folder: public Resource {
friend class boost::serialization::access;
public: 
	std::vector<Resource> mResources;
private: 
template<class Archive>
void save(Archive & ar, const unsigned int version) const
{
	ar &boost::serialization::base_object<Resource>(*this);
	ar &mResources;
}

template<class Archive>
void load(Archive & ar, const unsigned int version)
{
	ar &boost::serialization::base_object<Resource>(*this);
	ar &mResources;
}
BOOST_SERIALIZATION_SPLIT_MEMBER()
};
BOOST_CLASS_VERSION(Folder,1)

#endif //_FOLDER_H

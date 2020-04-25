/**
 * Project Material Lab
 * @author Bruk Tedla
 */


#ifndef _PACKAGE_H
#define _PACKAGE_H

#include<vector>
#include"../NodeGraph/Graph.h"
#include"../Resources/Resource.h"
#include "boost/serialization/access.hpp"
#include "boost/serialization/vector.hpp"
#include "boost/serialization/version.hpp"
#include "boost/serialization/split_member.hpp"
class Package {
friend class boost::serialization::access;
public: 
	std::vector<Resource> Resources;
	unsigned int uid;
/**
 * @param graph
 */
void AddGraph(Graph graph);
	
/**
 * @param UUID
 */
void DeleteGraph(unsigned int UUID);
	
/**
 * @param UUID
 */
Resource* GetResource(unsigned int UUID);
private: 
template<class Archive>
void save(Archive & ar, const unsigned int version) const
{
	ar &uid;
    ar &Resources;
}

template<class Archive>
void load(Archive & ar, const unsigned int version)
{
	ar &uid;
    ar &Resources;
}
BOOST_SERIALIZATION_SPLIT_MEMBER()
};
BOOST_CLASS_VERSION(Package,1)
#endif //_PACKAGE_H

/**
 * Project Material Lab
 * @author Bruk Tedla
 */


#ifndef _GRAPH_H
#define _GRAPH_H

#include <vector>
#include "../Resources/Resource.h"
#include "Node.h"
#include "boost/serialization/access.hpp"
#include "boost/serialization/base_object.hpp"
#include "boost/serialization/split_member.hpp"
#include "boost/serialization/version.hpp"
#include "boost/serialization/vector.hpp"

class Graph: public Resource {
friend class boost::serialization::access;
public:
	std::vector<Node> mNodes;
	unsigned int uid;
/**
 * @param Identifier
 */
Node& GetNode(unsigned int identifier);
public:
//Initializes data for live preview
virtual void SetupCache();

//Resets cache data
virtual void ClearCache();

//Deletes cache data
virtual void DeleteCache();
private: 
template<class Archive>
void save(Archive & ar, const unsigned int version) const
{
	ar &boost::serialization::base_object<Resource>(*this);
	ar &uid;
	ar &mNodes;
}

template<class Archive>
void load(Archive & ar, const unsigned int version)
{
	ar &boost::serialization::base_object<Resource>(*this);
	ar &uid;
	ar &mNodes;
}
BOOST_SERIALIZATION_SPLIT_MEMBER()
};
BOOST_CLASS_VERSION(Graph,1)
#endif //_GRAPH_H

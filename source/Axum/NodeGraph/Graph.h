/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#ifndef _GRAPH_H
#define _GRAPH_H

#include <vector>
#include <list>
#include <deque>
#include "../Resources/Resource.h"
#include "Node.h"
#include "boost/serialization/access.hpp"
#include "boost/serialization/base_object.hpp"
#include "boost/serialization/split_member.hpp"
#include "boost/serialization/version.hpp"
#include "boost/serialization/vector.hpp"

class Graph : public Resource
{
	friend class boost::serialization::access;

protected:
	std::list<Node> mNodes;
	unsigned int uid;

public:
	//Initializes data for live preview
	virtual void SetupCache();

	//Resets cache data
	virtual void ClearCache();

	//Deletes cache data
	virtual void DeleteCache();
	/**
 * @param Identifier
 */
	Node &GetNode(unsigned int identifier);

	std::list<Node>::iterator GetNodeIterator(unsigned int uid);

	void AddNode(Node n);

	void DeleteNode(unsigned int uid);

	/* 
	* @return node list in transversal order
	*/
	std::vector<Node *> transverse();

private:
	template <class Archive>
	void save(Archive &ar, const unsigned int version) const
	{
		ar &boost::serialization::base_object<Resource>(*this);
		ar &uid;
		ar &mNodes;
	}

	template <class Archive>
	void load(Archive &ar, const unsigned int version)
	{
		ar &boost::serialization::base_object<Resource>(*this);
		ar &uid;
		ar &mNodes;
	}
	BOOST_SERIALIZATION_SPLIT_MEMBER()
};
BOOST_CLASS_VERSION(Graph, 1)
#endif //_GRAPH_H

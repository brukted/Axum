/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#ifndef _GRAPH_H
#define _GRAPH_H

#include <vector>
#include <list>
#include <deque>
#include <memory>
#include "../Resources/Resource.h"
#include "Node.h"
#include "boost/serialization/access.hpp"
#include "boost/serialization/base_object.hpp"
#include "boost/serialization/split_member.hpp"
#include "boost/serialization/version.hpp"
#include "boost/serialization/vector.hpp"
#include "boost/serialization/list.hpp"
#include "Log.h"
#include "../Utils/Serialization/Connection.h"

class Graph : public Resource
{
	friend class boost::serialization::access;

protected:
	std::list<Node> mNodes;
	unsigned int uid;

public:
	Graph(unsigned int _uid);

	/**
 	* @param Identifier
 	*/
	Node &GetNode(unsigned int identifier);

	std::list<Node>::iterator GetNodeIterator(unsigned int uid);

	void AddNode(Node n);

	void DeleteNode(unsigned int uid);

	/**
	 * @brief Transverses the node graph into a sequence.
	 * 
	 * @return std::vector<Node *> the node graph transversed into sequence.
	 */
	std::vector<Node *> transverse();

private:
	template <class Archive>
	void save(Archive &ar, const unsigned int version) const
	{
		ar &boost::serialization::base_object<Resource>(*this);
		ar &uid;
		ar &mNodes;
		std::vector<Connection> connections;
		for (auto *node : mNodes)
		{
			for (auto *OutSock : node.mOutputSockets)
			{
				for (auto InSock : OutSock.LinkedSockets)
				{
					connections.push_back(Connection(node->GetUID(), OutSock->GetUID(), InSock->ParentNode->GetUID(), InSock->GetUID()));
				}
			}
		}
		ar &connections;
	}

	template <class Archive>
	void load(Archive &ar, const unsigned int version)
	{
		ar &boost::serialization::base_object<Resource>(*this);
		ar &uid;
		ar &mNodes;
		std::vector<Connection> connections;
		ar &connections;
		for (auto &con : connections)
		{
			auto destSoc = GetNode(con.ToNode()).GetInputSocket(con.ToSocket);
			GetNode(con.FromNode).GetOutputSocket(con.FromSocket).LinkTo(destSoc);
		}
	}
	BOOST_SERIALIZATION_SPLIT_MEMBER()
};
BOOST_CLASS_VERSION(Graph, 1)
#endif //_GRAPH_H

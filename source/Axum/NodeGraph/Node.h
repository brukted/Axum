/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#ifndef _NODE_H
#define _NODE_H

#include <string>
#include <vector>
#include "../Parameter/ParamCollection.h"
#include "../Utils/Serialization/GUIInfo.h"
#include "../UI/Widgets/NodeUI.h"
#include "OutputSocket.h"
#include "InputSocket.h"
#include "boost/serialization/access.hpp"
#include "boost/serialization/array.hpp"
#include "boost/serialization/split_member.hpp"
#include "boost/serialization/vector.hpp"
#include "boost/serialization/version.hpp"

class InputSocket;
class OutputSocket;
class NodeUI;
class Graph;

class Node
{
	friend class boost::serialization::access;

public:
	/**
 	* Name of the node to be displayed on the ui.
 	*/
	char16_t UIName[30];
	std::vector<InputSocket> mInputSockets;
	std::vector<OutputSocket> mOutputSockets;
	/**
	 * 
	**/
	ParamCollection mNodeParams;
	/**
	 * Contains the GUI information of the node
	**/
	GUIInfo mGUIInfo;
	//Pointer to parent graph
	Graph *parentGraph;

private:
	bool NeedUpdate = true;
	/**
* Unique identifer of the node in the graph
**/
	unsigned int uid;

public:
	/**
 * Invalidate makes the current cache invalid and all  nodes based upon it.
 */
	void Invalidate();

	/**
 * @param uid unique identifier of the socket
 */
	OutputSocket &GetOutputSocket(unsigned int uid);

	/**
 * @param uid
 */
	InputSocket &GetInputSocket(unsigned int uid);

	virtual NodeUI GetUI();

	//Initializes data for live preview
	virtual void SetupCache();

	//Resets cache data
	virtual void ClearCache();

	//Deletes cache data
	virtual void DeleteCache();

	//Excutes the node
	//Derived Nodes should implement this as it's empty
	virtual void Excute(ParamCollection &GraphParams) { return; };

	//Excute the node and nodes connected to it's output sockets
	virtual void ExcuteForward(ParamCollection &GraphParams);

	//Excute the node and nodes connected to it's input sockets
	virtual void ExcuteBackWard(ParamCollection &GraphParams);

private:
	template <class Archive>
	void save(Archive &ar, const unsigned int version) const
	{
		ar &uid;
		ar &mNodeParams;
		ar &mGUIInfo;
	}

	template <class Archive>
	void load(Archive &ar, const unsigned int version)
	{
		ar &uid;
		ar &mNodeParams;
		ar &mGUIInfo;
	}

	//Getter and setters
public:
	bool GetNeedUpdate() const
	{
		return NeedUpdate;
	}

	void SetNeedUpdate(bool NeedUpdate)
	{
		NeedUpdate = NeedUpdate;
	}

	bool GetUID() const
	{
		return uid;
	}

	BOOST_SERIALIZATION_SPLIT_MEMBER()
};
BOOST_CLASS_VERSION(Node, 1)
#endif //_NODE_H

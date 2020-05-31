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
	friend class Graph;

public:
	Node(unsigned int uid);
	bool isVisited = false;
	ParamCollection mNodeParams;
	/**
	 * Contains the GUI information of the node
	**/
	GUIInfo mGUIInfo();
	//Pointer to parent graph
	Graph *parentGraph = nullptr;

protected:
	Node();
	/**
 	* Name of the node to be displayed on the ui.
 	*/
	std::string UIName;
	std::vector<InputSocket> mInputSockets;
	std::vector<OutputSocket> mOutputSockets;
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

	std::vector<OutputSocket> &GetOutputSockets();

	std::vector<InputSocket> &GetInputSockets();

	virtual NodeUI GetUI();

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
	/**
	 * @brief Returns whether inputs are visited.
	 * 
	 * @return true All input providing nodes are visited. 
	 * @return false Some input providing nodes are not visited.
	 */
	bool isInputsVisited();
	/**
	 * @brief Returns whether the node relays on ther nodes output or not.
	 * 
	 * @return true The node can excute on it's ownself.
	 * @return false The node requires other nodes output.
	 */
	bool isStartNode();

	/**
	 * @brief Returns whether the node has output reqired by other nodes.
	 * 
	 * @return true The node has output sockets connected to other nodes.
	 * @return false The node has no output sockets or they are not connected to other nodes.
	 */
	bool isEndNode();

	//Getter and setters
public:
	bool GetNeedUpdate() const
	{
		return NeedUpdate;
	}

	void SetNeedUpdate(bool _NeedUpdate)
	{
		this->NeedUpdate = _NeedUpdate;
	}

	bool GetUID() const
	{
		return uid;
	}

	BOOST_SERIALIZATION_SPLIT_MEMBER()
};
BOOST_CLASS_VERSION(Node, 1)
#endif //_NODE_H

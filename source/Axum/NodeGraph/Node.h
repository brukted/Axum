/**
 * Project Material Lab
 * @author Bruk Tedla
 */


#ifndef _NODE_H
#define _NODE_H

#include<string>
#include<vector>
#include"../Parameter/ParamCollection.h"
#include"../Utils/Serialization/GUIInfo.h"
#include"../UI/Widgets/NodeUI.h"
#include"OutputSocket.h"
#include"InputSocket.h"
#include "boost/serialization/access.hpp"
#include "boost/serialization/array.hpp"
#include "boost/serialization/split_member.hpp"
#include "boost/serialization/vector.hpp"
#include "boost/serialization/version.hpp"

class InputSocket;
class OutputSocket;
class NodeUI;

class Node {
friend class boost::serialization::access;
public: 
	/**
 	* Name of the node to be displayed on the ui.
 	*/
	char16_t UIName[30];
	/**
	 * Unique identifer of the node in the graph
	**/
	unsigned int uid;
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
	
/**
 * Invalidate makes the current cache invalid and all  nodes based upon it.
 */
void Invalidate();
	
/**
 * @param uid unique identifier of the socket
 */
OutputSocket& GetOutputSocket(unsigned int uid);
	
/**
 * @param uid
 */
InputSocket& GetInputSocket(unsigned int uid);
	
virtual NodeUI GetUI();

//Initilizes data for live preview
virtual void SetupCache();

//Resets cache data
virtual void ClearCache();

//Deletes cache data
virtual void DeleteCache();

private: 
	bool NeedUpdate = true;
template<class Archive>
void save(Archive & ar, const unsigned int version) const
{
	ar &uid;
    ar &mNodeParams;
	ar &mGUIInfo;
}

template<class Archive>
void load(Archive & ar, const unsigned int version)
{
	ar &uid;
    ar &mNodeParams;
	ar &mGUIInfo;
}
BOOST_SERIALIZATION_SPLIT_MEMBER()
};
BOOST_CLASS_VERSION(Node,1)
#endif //_NODE_H

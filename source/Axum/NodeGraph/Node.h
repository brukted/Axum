/**
 * Project Material Lab
 * @author Bruk Tedla
 */


#ifndef _NODE_H
#define _NODE_H

#include<string>
#include<vector>
#include"NodeParams.h"
#include"../Utils/Serialization/GUIInfo.h"
#include"../UI/Widgets/NodeUI.h"
#include"OutputSocket.h"
#include"InputSocket.h"

class InputSocket;
class OutputSocket;
class NodeUI;

class Node {
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
	NodeParams mNodeParams;
	/**
	 * Contains the GUI information of the node
	**/
	GUIInfo mGUIInfo;
	
/**
 * Invalidate makes the current cache invalide and all  nodes based upon it.
 */
void Invalidate();
	
/**
 * @param uid unique identifier of the socket
 */
OutputSocket* GetOutputSocket(unsigned int uid);
	
/**
 * @param uid
 */
InputSocket* GetInputSocket(unsigned int uid);
	
virtual NodeUI GetUI();

private: 
	bool NeedUpdate = true;
};

#endif //_NODE_H

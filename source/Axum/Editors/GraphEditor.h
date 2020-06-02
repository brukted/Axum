/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#ifndef _GRAPHEDITOR_H
#define _GRAPHEDITOR_H

#include "../Editors/Editor.h"
#include "../../NodeGraph/Graph.h"

class GraphEditor : public Editor
{
public:
	/**
 * A pointer to the currently being edited node tree.
 */
	Graph *graph = nullptr;

	/**
 * @param *graph
 */
	void EditGraph(Graph *graph);
};

#endif //_GRAPHEDITOR_H

/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#ifndef _GRAPHEDITORUI_H
#define _GRAPHEDITORUI_H

#include "../EditorUI.h"
#include "../../NodeGraph/Graph.h"
#include "../Widgets/GraphUI.h"

class GraphEditorUI : public EditorUI
{
public:
	/**
 * Setups the appropirate node tree ui for the given tree and displays it.
 * @param *graph
 */
	void BindGraph(Graph *graph);

private:
	GraphUI graphUi;
};

#endif //_GRAPHEDITORUI_H

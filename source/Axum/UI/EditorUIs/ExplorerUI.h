/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#ifndef _EXPLORERUI_H
#define _EXPLORERUI_H

#include <vector>
#include "../EditorUI.h"
#include "../Widgets/ExplorerItemUI.h"

class ExplorerUI : public EditorUI
{
public:
	std::vector<ExplorerItemUI> Items;
};

#endif //_EXPLORERUI_H

/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#ifndef _EDITORMANAGER_H
#define _EDITORMANAGER_H

#include <vector>
#include "../Editors/Editor.h"
#include "../Editors/2DView.h"
#include "../Editors/3DView.h"
#include "../Editors/AssetManager.h"
#include "../Editors/LogicGraphEditor.h"
#include "../Editors/MaterialGraphEditor.h"
#include "../Editors/Outliner.h"
#include "../Editors/ParameterEditor.h"

class EditorManager
{
public:
	static EditorManager &getInstance()
	{
		static EditorManager instance;
		return instance;
	}

private:
	EditorManager(){};

public:
	EditorManager(EditorManager const &) = delete;
	void operator=(EditorManager const &) = delete;

	_2DView m2DView;

	_3DView m3DView;

	AssetManager mAssetManager;

	LogicGraphEditor mLogicEditor;

	MaterialGraphEditor mMaterialEditor;

	Outliner mOutliner;

	ParameterEditor mParameterEditor;

	void Startup();

	void Shutdown();
};

#endif //_EDITORMANAGER_H

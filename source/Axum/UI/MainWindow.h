/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#ifndef _MAINWINDOW_H
#define _MAINWINDOW_H

#include "Editors/Editor.h"
#include "Editors/Outliner/Outliner.h"
#include "Editors/ParameterEditor/ParameterEditor.h"
#include "Editors/TextureViewer/TextureViewer.h"
#include <vector>

namespace Axum::UI {
/**
 * @brief MainWindow provides a functionality to open a full fledged
 * window which supports docking. Main window is also the only window type that
 * can contain @a Editor.
 *
 */
class MainWindow {
protected:
  Editor::Outliner outliner;
  Editor::ParameterEditor paramEditor;
  Editor::TextureViewer textureViewer;
  void drawMenuBar();

public:
  MainWindow();
  void draw();
};

} // namespace Axum::UI
#endif //_MAINWINDOW_H

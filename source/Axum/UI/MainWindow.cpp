/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#include "MainWindow.h"

/**
 * MainWindow implementation
 */

namespace Axum::UI {
void MainWindow::drawMenuBar() {}

MainWindow::MainWindow() {}

void MainWindow::draw() {
  drawMenuBar();
  outliner.draw();
  paramEditor.draw();
  textureViewer.draw();
}

} // namespace Axum::UI
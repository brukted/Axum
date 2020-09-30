/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#ifndef _Editor_H
#define _Editor_H

#include <imgui.h>
#include <string>
#include "Utils/Translation/Translation.h"

namespace Axum {
namespace UI {
namespace Editor {

/**
 * @brief Editor Base class for all editors. Provides common functionalities for
 * editors such as docking and title bar.
 *
 */
class Editor {
public:
  Editor();
  /**
   * @brief Draws UI using dear imgui.Called every frame.
   *
   */
  virtual void draw();
};

} // namespace Editor
} // namespace UI
} // namespace Axum
#endif //_Editor_H

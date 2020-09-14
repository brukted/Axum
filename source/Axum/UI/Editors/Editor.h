/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#ifndef _Editor_H
#define _Editor_H

#include <imgui.h>
#include <string>

namespace Axum {
namespace UI {
namespace Editor {

/**
 * @brief Editor Base class for all editors. Provides common functionalities for
 * editors such as docking and title bar.
 *
 */
class Editor {
protected:
  std::string name;
  std::string longName;

public:
  Editor();

  Editor(std::string name, std::string longname);
  virtual void draw();
};

} // namespace Editor
} // namespace UI
} // namespace Axum
#endif //_Editor_H

/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#ifndef _Editor_H
#define _Editor_H

#include <gdlmm.h>
#include <gtkmm.h>
#include <string>

namespace Axum {
namespace UI {
namespace Editor {

/**
 * @brief Editor Base class for all editors. Provides common functionalities for
 * editors such as docking and title bar.
 *
 */
class Editor : public Gdl::DockItem {
protected:
  Gtk::Fixed space;

public:
  Editor();

  Editor(std::string name, std::string longname);

  /**
   * @brief Returns a reference to Gtk container where more UI can be added.
   */
  Gtk::Fixed &GetSpace();

  void SetIcon();
};

} // namespace Editor
} // namespace UI
} // namespace Axum
#endif //_Editor_H

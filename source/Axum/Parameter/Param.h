/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#ifndef _PARAM_H
#define _PARAM_H

#include "Log.h"
#include <boost/serialization/access.hpp>
#include <boost/serialization/array.hpp>
#include <boost/serialization/split_member.hpp>
#include <boost/serialization/string.hpp>
#include <boost/serialization/vector.hpp>
#include <boost/serialization/version.hpp>
#include <gtkmm-3.0/gtkmm.h>
#include <sigc++/sigc++.h>
#include <string>
#include <vector>

namespace Axum {
namespace Parameter {

class ProxyParam;

class Param {
  friend class boost::serialization::access;
  friend class ProxyParam;

protected:
  /**
   * @brief Construct a new Param object with uid is equal to 0.
   * Don't use if it's going to be added to Param Collection.
   *
   */
  Param(){};

public:
  /**
   * @brief Identifier of the parameter for programming and logging purpose.
   *
   */
  std::string ID;
  /**
   * @brief UI name of the parameter. This is not guaranteed to be always the
   * same as It is localized. Use ID instead.
   *
   */
  std::string name;
  std::string Group;
  bool IsEditMode = false;
  sigc::signal<void> OnValueChanged;

  Param(std::string ID, const std::string &_name, std::string group);

  Param(std::string ID, const char *_name, std::string group);

  /**
   * @brief Constructs a Gtk widget that can be used to display the param in UI.
   *
   * @return Gtk::Widget*
   */
  Gtk::Widget *Draw();

protected:
  virtual Gtk::Widget *DrawDisplay();
  virtual Gtk::Widget *DrawEdit();

private:
  template <class Archive>
  void save(Archive &ar, const unsigned int version) const {
    ar &ID &name &IsEditMode &Group;
  }

  template <class Archive> void load(Archive &ar, const unsigned int version) {
    ar &ID &name &IsEditMode &Group;
  }
  BOOST_SERIALIZATION_SPLIT_MEMBER()
};

} // namespace Parameter
} // namespace Axum
BOOST_CLASS_VERSION(Axum::Parameter::Param, 1)
#endif //_PARAM_H

/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#ifndef _AXUM_PARAMETER_PARAM_H
#define _AXUM_PARAMETER_PARAM_H

#include "Utils/Log/Log.h"
#include <boost/serialization/access.hpp>
#include <boost/serialization/array.hpp>
#include <boost/serialization/split_member.hpp>
#include <boost/serialization/string.hpp>
#include <boost/serialization/vector.hpp>
#include <boost/serialization/version.hpp>
#include <boost/signals2.hpp>
#include <imgui.h>
#include <string>
#include <string_view>
#include <vector>

namespace Axum {
namespace Parameter {

class ProxyParam;

class Param {
  friend class boost::serialization::access;
  friend class ProxyParam;

public:
  boost::signals2::signal<void()> valueChanged;
  Param(){};
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
  /**
   * @brief Description of the parameter to show as tool tip in ui.
   *
   */
  std::string description;
  bool isEditMode = false;

  Param(std::string_view ID, std::string_view name,
        std::string_view description);

  void draw();

protected:
  virtual void drawDisplay();
  virtual void drawEdit();

private:
  template <class Archive>
  void save(Archive &ar, const unsigned int /*version*/) const {
    ar &ID &name &isEditMode &description;
  }

  template <class Archive>
  void load(Archive &ar, const unsigned int /*version*/) {
    ar &ID &name &isEditMode &description;
  }
  BOOST_SERIALIZATION_SPLIT_MEMBER()
};

} // namespace Parameter
} // namespace Axum
BOOST_CLASS_VERSION(Axum::Parameter::Param, 1)
#endif //_AXUM_PARAMETER_PARAM_H

/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#ifndef _AXUM_PARAMETER_TEXT_PARAM_H
#define _AXUM_PARAMETER_TEXT_PARAM_H

#include "Param.h"
#include <boost/serialization/access.hpp>
#include <boost/serialization/split_member.hpp>
#include <boost/serialization/string.hpp>
#include <boost/serialization/version.hpp>
#include <imgui_stdlib.h>
#include <string>

namespace Axum {
namespace Parameter {

class TextParam : public Param {
  friend class boost::serialization::access;

private:
  std::string value;

public:
  TextParam(std::string_view ID, std::string_view value,
            std::string_view name = "", std::string_view description = "");

  std::string_view getValue();

  /**
   * @brief Set the value of the parameter.
   *
   * @param value New value.
   */
  void setValue(std::string_view value);

protected:
  virtual void drawDisplay() override;

private:
  template <class Archive>
  void save(Archive &ar, const unsigned int /*version*/) const {
    ar &boost::serialization::base_object<Param>(*this);
    ar &value;
  }

  template <class Archive> void load(Archive &ar, const unsigned int /*version*/) {
    ar &boost::serialization::base_object<Param>(*this);
    ar &value;
  }

  BOOST_SERIALIZATION_SPLIT_MEMBER()
};
} // namespace Parameter
} // namespace Axum
BOOST_CLASS_VERSION(Axum::Parameter::TextParam, 1)
#endif //_AXUM_PARAMETER_TEXT_PARAM_H

/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#ifndef _TEXTPARAM_H
#define _TEXTPARAM_H

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
  TextParam(std::string ID, std::string &_name, std::string &_value);

  TextParam(std::string ID, const char *_name, const char *_value);

  std::string &GetValue();

  /**
   * @brief Set the value of the parameter.
   *
   * @param _value New value.
   */
  void SetValue(std::string &_value);

  /**
   * @brief Set the value of the parameter.
   *
   * @param _value New value.
   */
  void SetValue(const char *_value);

protected:
  virtual void drawDisplay() override;

private:
  template <class Archive>
  void save(Archive &ar, const unsigned int version) const {
    ar &boost::serialization::base_object<Param>(*this);
    ar &value;
  }

  template <class Archive> void load(Archive &ar, const unsigned int version) {
    ar &boost::serialization::base_object<Param>(*this);
    ar &value;
  }

  BOOST_SERIALIZATION_SPLIT_MEMBER()
};
} // namespace Parameter
} // namespace Axum
BOOST_CLASS_VERSION(Axum::Parameter::TextParam, 1)
#endif //_TEXTPARAM_H

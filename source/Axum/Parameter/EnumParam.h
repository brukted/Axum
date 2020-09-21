/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#ifndef _AXUM_PARAMETER_ENUM_PARAM_H
#define _AXUM_PARAMETER_ENUM_PARAM_H

#include "Param.h"
#include "boost/serialization/access.hpp"
#include "boost/serialization/map.hpp"
#include "boost/serialization/split_member.hpp"
#include "boost/serialization/version.hpp"
#include <map>
#include <string>

namespace Axum {
namespace Parameter {

class EnumParam : public Param {
  friend class boost::serialization::access;

private:
  EnumParam(){};

  std::map<int, std::string> enums;

  int intValue;
  std::string strValue;

public:
  /**
   * @brief Construct a new Enum Param object
   *
   * @param ID ID of the parameter.
   * @param _name Name of the parameter.
   * @param _enums Map of possible values.
   * @param _value Default intValue for the parameter.
   */
  EnumParam(std::string_view ID, std::map<int, std::string> enums,
            int value, std::string_view name = "",
            std::string_view description = "");

  int getValue() const { return intValue; };

  void setValue(int const key);

  std::string &toString(int const key);

protected:
  virtual void drawDisplay() override;

private:
  template <class Archive>
  void save(Archive &ar, const unsigned int version) const {
    ar &boost::serialization::base_object<Param>(*this);
    ar &intValue;
  }

  template <class Archive> void load(Archive &ar, const unsigned int version) {
    ar &boost::serialization::base_object<Param>(*this);
    ar &intValue;
  }
  BOOST_SERIALIZATION_SPLIT_MEMBER()
};
} // namespace Parameter
} // namespace Axum
BOOST_CLASS_VERSION(Axum::Parameter::EnumParam, 1)
#endif //_AXUM_PARAMETER_ENUM_PARAM_H

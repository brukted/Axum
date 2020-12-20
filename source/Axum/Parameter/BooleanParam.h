/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#ifndef _AXUM_PARAMETER_BOOLEAN_PARAM_H
#define _AXUM_PARAMETER_BOOLEAN_PARAM_H

#include "Param.h"
#include "boost/serialization/access.hpp"
#include "boost/serialization/split_member.hpp"
#include "boost/serialization/version.hpp"

namespace Axum {
namespace Parameter {

class BooleanParam : public Param {
private:
  friend class boost::serialization::access;
  bool value;

public:
  BooleanParam(std::string_view ID, bool value = true, std::string_view name = "",
               std::string_view description = "", std::string_view group = "");

  bool getValue() const;

  void setValue(bool value);

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
BOOST_CLASS_VERSION(Axum::Parameter::BooleanParam, 1)
#endif //_AXUM_PARAMETER_BOOLEAN_PARAM_H

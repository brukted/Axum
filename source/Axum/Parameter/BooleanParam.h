/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#ifndef _BOOLEANPARAM_H
#define _BOOLEANPARAM_H

#include "Param.h"
#include "boost/serialization/access.hpp"
#include "boost/serialization/split_member.hpp"
#include "boost/serialization/version.hpp"

namespace Axum {
namespace Parameter {

class BooleanParam : public Param {
private:
  bool value;

public:
  BooleanParam(unsigned int _uid, std::string &_name, bool _value);

  BooleanParam(unsigned int _uid, const char *_name, bool _value);

  bool GetValue() const;

  void SetValue(bool _value);

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
BOOST_CLASS_VERSION(Axum::Parameter::BooleanParam, 1)
#endif //_BOOLEANPARAM_H

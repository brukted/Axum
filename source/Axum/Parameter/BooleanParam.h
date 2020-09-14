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
  friend class boost::serialization::access;
private:
  bool value;

public:
  BooleanParam(std::string ID, std::string &_name, bool _value);

  BooleanParam(std::string ID, const char *_name, bool _value);

  bool GetValue() const;

  void SetValue(bool _value);

protected:
  virtual void  drawDisplay() override;

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

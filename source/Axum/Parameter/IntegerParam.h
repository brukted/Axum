/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#ifndef _INTEGERPARAM_H
#define _INTEGERPARAM_H

#include "Param.h"
#include "boost/serialization/access.hpp"
#include "boost/serialization/split_member.hpp"
#include "boost/serialization/version.hpp"

namespace Axum {
namespace Parameter {

class IntegerParam : public Param {
  friend class boost::serialization::access;

private:
  int value;

public:
  IntegerParam(std::string ID, std::string &_name, int _value);

  IntegerParam(std::string ID, const char *_name, int _value);

  int GetValue() const;

  void SetValue(int _value);

  Gtk::Widget *DrawDisplay() override;

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
BOOST_CLASS_VERSION(Axum::Parameter::IntegerParam, 1)
#endif //_INTEGERPARAM_H

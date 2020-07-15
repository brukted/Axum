/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#ifndef _TEXTPARAM_H
#define _TEXTPARAM_H

#include "Param.h"
#include "boost/serialization/access.hpp"
#include "boost/serialization/split_member.hpp"
#include "boost/serialization/string.hpp"
#include "boost/serialization/version.hpp"
#include <string>

namespace Axum {
namespace Parameter {

class TextParam : public Param {
  friend class boost::serialization::access;

private:
  std::string value;

public:
  TextParam(unsigned int _uid, std::string &_name, std::string &_value);

  TextParam(unsigned int _uid, const char *_name, const char *_value);

  std::string &GetValue();

  void SetValue(std::string &_value);

  void SetValue(const char *_name);

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

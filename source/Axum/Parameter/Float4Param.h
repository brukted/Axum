/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#ifndef _FLOAT4PARAM_H
#define _FLOAT4PARAM_H

#include "Param.h"
#include "boost/serialization/access.hpp"
#include "boost/serialization/array.hpp"
#include "boost/serialization/split_member.hpp"
#include "boost/serialization/version.hpp"

namespace Axum {
namespace Parameter {

class Float4Param : public Param {
  friend class boost::serialization::access;

private:
  std::array<float, 4> value;

public:
  Float4Param(std::string ID, std::string &_name,
              std::array<float, 4> _value);

  Float4Param(std::string ID, const char *_name,
              std::array<float, 4> _value);

  std::array<float, 4> GetValue() const;

  void SetValue(std::array<float, 4> _value);

protected:
  virtual Gtk::Widget *DrawDisplay() override;

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
BOOST_CLASS_VERSION(Axum::Parameter::Float4Param, 1)
#endif //_FLOAT4PARAM_H

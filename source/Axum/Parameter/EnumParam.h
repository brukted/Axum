/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#ifndef _ENUMPARAM_H
#define _ENUMPARAM_H

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

  int value;

public:
  /**
   * @brief Construct a new Enum Param object
   *
   * @param ID ID of the parameter.
   * @param _name Name of the parameter.
   * @param _enums Map of possible values.
   * @param _value Default value for the parameter.
   */
  EnumParam(std::string ID, std::string _name,
            std::map<int, std::string> _enums, int _value = 0);

  ///int GetValue() const{ return value; };
  
  int GetValue() { return value; };

  void SetValue(int const key);

  std::string &ToString(int const key);

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
BOOST_CLASS_VERSION(Axum::Parameter::EnumParam, 1)
#endif //_ENUMPARAM_H

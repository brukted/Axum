/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#ifndef _PARAM_H
#define _PARAM_H

#include "Utils/Log/Log.h"
#include <boost/serialization/access.hpp>
#include <boost/serialization/array.hpp>
#include <boost/serialization/split_member.hpp>
#include <boost/serialization/string.hpp>
#include <boost/serialization/vector.hpp>
#include <boost/serialization/version.hpp>
#include <string>
#include <vector>
#include <imgui.h>

namespace Axum {
namespace Parameter {

class ProxyParam;

class Param {
  friend class boost::serialization::access;
  friend class ProxyParam;

protected:
  /**
   * @brief Construct a new Param object with uid is equal to 0.
   * Don't use if it's going to be added to Param Collection.
   *
   */
  Param(){};

public:
  /**
   * @brief Identifier of the parameter for programming and logging purpose.
   *
   */
  std::string ID;
  /**
   * @brief UI name of the parameter. This is not guaranteed to be always the
   * same as It is localized. Use ID instead.
   *
   */
  std::string name;
  std::string group;
  bool isEditMode = false;

  Param(std::string ID, const std::string &_name, std::string group);

  Param(std::string ID, const char *_name, std::string group);

  void draw();

protected:
  virtual void drawDisplay();
  virtual void drawEdit();

private:
  template <class Archive>
  void save(Archive &ar, const unsigned int version) const {
    ar &ID &name &isEditMode &group;
  }

  template <class Archive> void load(Archive &ar, const unsigned int version) {
    ar &ID &name &isEditMode &group;
  }
  BOOST_SERIALIZATION_SPLIT_MEMBER()
};

} // namespace Parameter
} // namespace Axum
BOOST_CLASS_VERSION(Axum::Parameter::Param, 1)
#endif //_PARAM_H

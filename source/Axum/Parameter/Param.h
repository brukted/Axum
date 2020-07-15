/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#ifndef _PARAM_H
#define _PARAM_H

#include "../UI/Widgets/ParamUI.h"
#include "boost/serialization/access.hpp"
#include "boost/serialization/split_member.hpp"
#include "boost/serialization/string.hpp"
#include "boost/serialization/vector.hpp"
#include "boost/serialization/version.hpp"
#include "sigc++/sigc++.h"
#include <string>
#include <vector>

namespace Axum {
namespace Parameter {

class Param {
  friend class boost::serialization::access;

protected:
  /**
   * @brief Construct a new Param object with uid is equal to 0.
   * Don't use if it's going to be added to Param Collection.
   *
   */
  Param(){};
  /**
   * @brief UI name of the parameter.
   *
   */
  std::string name;
  unsigned int uid;

public:
  sigc::signal<void> OnValueChanged;

  Param(unsigned int _uid);

  Param(unsigned int _uid, std::string &_name);

  Param(unsigned int _uid, const char *_name);

  Param(std::string &_name);

  Param(const char *_name);

  virtual void DrawEdit(UI::Widget::ParamUI *ui);

  virtual void DrawDisplay(UI::Widget::ParamUI *ui);

  std::string &getName();

  /**
   * @brief Set the UI name of the parameter.
   *
   */
  void SetName(std::string &_name);

  /**
   * @brief Set the UI name of the parameter.
   *
   */
  void SetName(const char *_name);

  unsigned int GetUID();

private:
  template <class Archive>
  void save(Archive &ar, const unsigned int version) const {
    ar &uid;
    ar &name;
  }

  template <class Archive> void load(Archive &ar, const unsigned int version) {
    ar &uid;
    ar &name;
  }
  BOOST_SERIALIZATION_SPLIT_MEMBER()
};

} // namespace Parameter
} // namespace Axum
BOOST_CLASS_VERSION(Axum::Parameter::Param, 1)
#endif //_PARAM_H

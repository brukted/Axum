/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#ifndef _PARAMCOLLECTION_H
#define _PARAMCOLLECTION_H

#include "Log.h"
#include "Param.h"
#include <boost/serialization/access.hpp>
#include <boost/serialization/list.hpp>
#include <boost/serialization/split_member.hpp>
#include <boost/serialization/vector.hpp>
#include <boost/serialization/version.hpp>
#include <list>
#include <stdarg.h>

namespace Axum {
namespace Parameter {

class ParamCollection : public Param {
  friend class boost::serialization::access;

protected:
  ParamCollection(){};

public:
  std::list<Param> Params;
  ParamCollection(std::string ID, const char *_name,
                  std::list<Param> params = {});

  ParamCollection(std::string ID, std::string &_name,
                  std::list<Param> params = {});

  /**
   *@brief Finds a parameter.
   *
   * @param ID ID of the parameter.
   * @return Param& Reference to the parameter if found.
   *
   */
  Param &FindParameter(std::string &ID);

  /**
   *@brief Finds a parameter.
   *
   * @param ID ID of the parameter.
   * @return Param& Reference to the parameter if found.
   *
   */
  Param &FindParameter(const char *ID);

  /**
   *@brief Finds a parameter and cast it to T type. Note: static cast is used to
   *cast.
   *
   * @param ID ID of the parameter.
   * @return T& Reference to the parameter if found.
   *
   */
  template <typename T> T &FindParameter(std::string &ID) {
    return static_cast<T>(FindParameter(ID));
  }

  /**
   *@brief Dynamically add parameter to the collection
   *
   * @param parameter
   */
  void AddParameter(Param parameter);

protected:
  virtual Gtk::Widget *DrawDisplay() override;

private:
  template <class Archive>
  void save(Archive &ar, const unsigned int version) const {
    ar &boost::serialization::base_object<Param>(*this);
    ar &Params;
  }

  template <class Archive> void load(Archive &ar, const unsigned int version) {
    ar &boost::serialization::base_object<Param>(*this);
    ar &Params;
  }
  BOOST_SERIALIZATION_SPLIT_MEMBER()
};
} // namespace Parameter
} // namespace Axum
BOOST_CLASS_VERSION(Axum::Parameter::ParamCollection, 1)
#endif //_PARAMCOLLECTION_H

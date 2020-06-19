/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#ifndef _PARAMCOLLECTION_H
#define _PARAMCOLLECTION_H

#include "Log.h"
#include "Param.h"
#include "boost/serialization/access.hpp"
#include "boost/serialization/split_member.hpp"
#include "boost/serialization/vector.hpp"
#include "boost/serialization/version.hpp"
#include <vector>

namespace Axum {
namespace Parameter {

class ParamCollection : public Param {
  friend class boost::serialization::access;

protected:
  std::vector<Param *> Params;
  unsigned int lastUid = 0;

public:
  /**
   * @brief Construct a new Param Collection object
   *  use only for root parameter
   *
   */
  ParamCollection(){};

  ParamCollection(unsigned int _uid, const char *_name);

  ParamCollection(unsigned int _uid, std::string &_name);

  /**
   *
   *
   * @param _uid unique identifer of the parameter
   * @return a pointer to a sub parameter
   *
   */
  Param &GetParameter(unsigned int _uid);

  Param &GetParameter(std::string &_name);

  Param &GetParameter(const char *_name);
  /**
   * @param parameter
   */
  void AddParameter(Param *parameter);

  unsigned int GenerateUid();

private:
  template <class Archive>
  void save(Archive &ar, const unsigned int version) const {
    ar &boost::serialization::base_object<Param>(*this);
    ar &Params;
    ar &lastUid;
  }

  template <class Archive> void load(Archive &ar, const unsigned int version) {
    ar &boost::serialization::base_object<Param>(*this);
    ar &Params;
    ar &lastUid;
  }
  BOOST_SERIALIZATION_SPLIT_MEMBER()
};
} // namespace Parameter
} // namespace Axum
BOOST_CLASS_VERSION(Axum::Parameter::ParamCollection, 1)
#endif //_PARAMCOLLECTION_H

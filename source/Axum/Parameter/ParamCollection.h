/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#ifndef _AXUM_PARAMETER_PARAM_COLLECTION_H
#define _AXUM_PARAMETER_PARAM_COLLECTION_H

#include "Param.h"
#include "Utils/Log/Log.h"
#include <boost/serialization/access.hpp>
#include <boost/serialization/list.hpp>
#include <boost/serialization/split_member.hpp>
#include <boost/serialization/unique_ptr.hpp>
#include <boost/serialization/vector.hpp>
#include <boost/serialization/version.hpp>
#include <boost/serialization/shared_ptr.hpp>
#include <list>
#include <memory>

namespace Axum {
namespace Parameter {

class ParamCollection : public Param {
private:
  friend class boost::serialization::access;

public:
  ParamCollection(){};
  std::vector<std::shared_ptr<Param>> params;

  /**
   * @brief Construct a new Param Collection object
   *
   * @param ID Identifier of the parameter for logging.
   * @param name Ui name of the parameter
   * @param params Parameters contained in this collection.
   * @param description Ui tooltip for the parameter.
   *
   * @warning The life time of the parameters contained is managed by this
   * parameter.Use proxy param if you want to use  the collection as grouping.
   */
  ParamCollection(std::string_view ID, std::string_view name = "",
                  std::vector<Param *> params = {},
                  std::string_view description = "", std::string_view group = "");

  /**
   *@brief Finds a parameter.
   *
   * @param ID ID of the parameter.
   * @return Param& Reference to the parameter if found.
   *
   */
  Param &findParameter(std::string_view ID);

  /**
   *@brief Finds a parameter and cast it to T type. Note: static cast is used to
   *cast.
   *
   * @param ID ID of the parameter.
   * @return T& Reference to the parameter if found.
   *
   */
  template <typename T> T &findParameter(std::string_view ID) {
    return static_cast<T>(findParameter(ID));
  }

  /**
   *@brief Dynamically add parameter to the collection
   *
   * @param parameter
   */
  void AddParameter(Param *parameter);

protected:
  virtual void drawDisplay() override;

private:
  template <class Archive>
  void save(Archive &ar, const unsigned int version) const {
    ar &boost::serialization::base_object<Param>(*this);
    ar &params &lastUid;
  }

  template <class Archive> void load(Archive &ar, const unsigned int version) {
    ar &boost::serialization::base_object<Param>(*this);
    ar &params &lastUid;
  }
  BOOST_SERIALIZATION_SPLIT_MEMBER()
};
} // namespace Parameter
} // namespace Axum
BOOST_CLASS_VERSION(Axum::Parameter::ParamCollection, 1)
#endif //_AXUM_PARAMETER_PARAM_COLLECTION_H

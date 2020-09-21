/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#ifndef _AXUM_PARAMTER_INTEGER_VECTOR_PARAM_H
#define _AXUM_PARAMTER_INTEGER_VECTOR_PARAM_H

#include "Param.h"
#include <boost/serialization/access.hpp>
#include <boost/serialization/array.hpp>
#include <boost/serialization/split_member.hpp>
#include <boost/serialization/version.hpp>
#include <limits>
#include <vector>

namespace Axum {
namespace Parameter {

class IntegerVectorParam : public Param {
private:
  friend class boost::serialization::access;
  int size;
  int hardMax;
  int hardMin;
  int uiMin;
  int uiMax;
  std::vector<int> value;

public:
  /**
   * @brief Construct a new Integer Vector Param object
   *
   * @param ID Identifier of the parameter for logging.
   * @param name  Ui name of the parameter.
   * @param description Ui tooltip the parameter.
   * @param size Size of the vector.
   * @param value Default value.
   * @param uiMin Ui minimum limit of the value.
   * @param uiMax Ui maximum limit of the value.
   * @param hardMin The absolute minimum limit.
   * @param hardMax The absolute maximum limit.
   */
  IntegerVectorParam(std::string_view ID, std::string_view name = "",
                     std::string_view description = "", int size = 1,
                     std::vector<int> value = {0}, int uiMin = INT_MIN,
                     int uiMax = INT_MAX, int hardMin = INT_MIN,
                     int hardMax = INT_MAX);

  std::vector<int> getValue() const;
  void setValue(std::vector<int> value);

protected:
  virtual void drawDisplay() override;

private:
  template <class Archive>
  void save(Archive &ar, const unsigned int version) const {
    ar &boost::serialization::base_object<Param>(*this);
    ar &value &size &hardMax &hardMin &uiMax &uiMin;
  }

  template <class Archive> void load(Archive &ar, const unsigned int version) {
    ar &boost::serialization::base_object<Param>(*this);
    ar &value &size &hardMax &hardMin &uiMax &uiMin;
  }
  BOOST_SERIALIZATION_SPLIT_MEMBER()
};
} // namespace Parameter
} // namespace Axum
BOOST_CLASS_VERSION(Axum::Parameter::IntegerVectorParam, 1)
#endif //_AXUM_PARAMTER_INTEGER_VECTOR_PARAM_H

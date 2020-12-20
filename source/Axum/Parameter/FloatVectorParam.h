/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#ifndef _AXUM_PARAMETER_FLOAT_VECTOR_PARAM_H
#define _AXUM_PARAMETER_FLOAT_VECTOR_PARAM_H

#include "Param.h"
#include "boost/serialization/access.hpp"
#include "boost/serialization/split_member.hpp"
#include "boost/serialization/vector.hpp"
#include "boost/serialization/version.hpp"
#include <limits>
#include <vector>

namespace Axum {
namespace Parameter {

class FloatVectorParam : public Param {
public:
  enum class Type { COLOR, ROTATION, NONE };

private:
  friend class boost::serialization::access;
  int size;
  Type type;
  float hardMax;
  float hardMin;
  float uiMin;
  float uiMax;
  std::vector<float> value;

public:
  /**
   * @brief Construct a new Float Vector Param object
   *
   * @param ID Identifier of the parameter for logging.
   * @param name  Ui name of the parameter.
   * @param description Ui tooltip the parameter.
   * @param size Size of the vector.
   * @param value Default value.
   * @param type Type of ui to use for representing the parameter.
   * @param uiMin Ui minimum limit of the value.
   * @param uiMax Ui maximum limit of the value.
   * @param hardMin The absolute minimum limit.
   * @param hardMax The absolute maximum limit.
   */
  FloatVectorParam(std::string_view ID, std::string_view name = "",
                   std::string_view description = "", std::string_view group = "", int size = 1,
                   std::vector<float> value = {0}, Type type = Type::NONE,
                   float uiMin = -FLT_MAX, float uiMax = FLT_MAX,
                   float hardMin = -FLT_MAX, float hardMax = FLT_MAX);

  std::vector<float> getValue() const;
  void setValue(std::vector<float> value);

protected:
  virtual void drawDisplay() override;

private:
  template <class Archive>
  void save(Archive &ar, const unsigned int version) const {
    ar &boost::serialization::base_object<Param>(*this);
    ar &value &size &type &hardMax &hardMin &uiMax &uiMin;
  }

  template <class Archive> void load(Archive &ar, const unsigned int version) {
    ar &boost::serialization::base_object<Param>(*this);
    ar &value &size &type &hardMax &hardMin &uiMax &uiMin;
  }
  BOOST_SERIALIZATION_SPLIT_MEMBER()
};
} // namespace Parameter
} // namespace Axum
BOOST_CLASS_VERSION(Axum::Parameter::FloatVectorParam, 1)
#endif //_AXUM_PARAMETER_FLOAT_VECTOR_PARAM_H

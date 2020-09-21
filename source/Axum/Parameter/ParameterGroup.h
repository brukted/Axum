#ifndef _AXUM_PARAMTER_PARAMETER_GROUP_H__
#define _AXUM_PARAMTER_PARAMETER_GROUP_H__

#include "Param.h"
#include <assert.h>
#include <string_view>
#include <vector>


namespace Axum::Parameter {

/**
 * @brief ParameterGroup provides a  simple way to  organize parameters in ui.
 * Parameter group doesn't mannage it's childerens lifetime.
 *
 */
class ParameterGroup : public Param {
private:
  std::vector<Param *> params;

public:
  ParameterGroup(std::vector<Param *> params, std::string_view name,
                 std::string_view description = "");

protected:
  virtual void drawDisplay() override;
  virtual void drawEdit() override{};
};

} // namespace Axum::Parameter
#endif // _AXUM_PARAMTER_PARAMETER_GROUP_H__
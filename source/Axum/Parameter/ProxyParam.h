#ifndef __PROXYPARAM_H__
#define __PROXYPARAM_H__

#include "Param.h"

namespace Axum {
namespace Parameter {

/**
 * @brief A parameter that provides access to another parameter.
 *
 */
class ProxyParam : public Param {
private:
  Param *parameter;

public:
  ProxyParam(std::string ID, Param *_parameter);

  /**
   * @brief Get the underlying parameter.
   *
   * @return Param& a reference to the underlying parameter.
   */
  Param &GetParam();

protected:
  virtual void  drawEdit() override;

  virtual void  drawDisplay() override;
};
} // namespace Parameter
} // namespace Axum
#endif // __PROXYPARAM_H__
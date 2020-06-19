#ifndef __PROXYPARAM_H__
#define __PROXYPARAM_H__

#include "Param.h"

namespace Axum {
namespace Parameter {

/**
 * @brief A parameter that provides access to another parameter
 *
 */
class ProxyParam : public Param {
private:
  Param *parameter;

public:
  ProxyParam(unsigned int _uid, Param *_parameter);

  virtual void DrawEdit(UI::Widget::ParamUI *ui) override;

  virtual void DrawDisplay(UI::Widget::ParamUI *ui) override;

  /**
   * @brief Get the underlying parameter
   *
   * @return Param& a reference to the underlying object
   */
  Param &GetParam();
};
} // namespace Parameter
} // namespace Axum
#endif // __PROXYPARAM_H__
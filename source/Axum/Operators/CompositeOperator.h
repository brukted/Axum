/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#ifndef __COMPOSITEOPERATOR_H__
#define __COMPOSITEOPERATOR_H__

#include "Operator.h"
#include <vector>

namespace Axum::Operator {

/**
 * @brief CompositeOperator provides a capability to contain multiple operators
 * in a single operator.It also undoes and redoes operatations in the correct
 * order.
 *
 */
class CompositeOperator : public Operator {
protected:
  /**
   * @brief Collection of operators contained in this operator. The order
   * in which the this operator excutes is dependent on the order they appear in
   * @a operators, the first being executed first and undone last.
   *
   */
  std::vector<Operator> operators;

public:
  virtual void Execute() noexcept override;
  virtual void Undo() noexcept override;
  virtual void Redo() noexcept override;
};
} // namespace Axum::Operator
#endif // __COMPOSITEOPERATOR_H__
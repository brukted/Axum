/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#include "CompositeOperator.h"

namespace Axum::Operator {

void CompositeOperator::Execute() noexcept {
  for (size_t i = 0; i < this->operators.size(); i++) {
    operators[i].Execute();
  }
}
void CompositeOperator::Undo() noexcept {
  for (int i = this->operators.size() - 1; i >= 0; i--) {
    operators[i].Undo();
  }
}
void CompositeOperator::Redo() noexcept { Execute(); }

} // namespace Axum::Operator

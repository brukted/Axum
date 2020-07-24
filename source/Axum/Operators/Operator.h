/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#ifndef _OPERATOR_H
#define _OPERATOR_H

#include <string>

namespace Axum::Operator {

/**
 * @brief Operator holds fields and methods required to do an undoable
 * operatation. Operations that are needed to be undoable should be derived from
 * @a Operator, override Execute (),Undo() and Redo() and register in
 * @a UndoManager to execute.
 *
 */
class Operator {
public:
  std::string UIName;
  std::string Name;

  /**
   * @brief Excutes the operation contained in. Only for use in undo manager.
   *
   */
  virtual void Execute() noexcept;

  /**
   * @brief Undoes the operation contained in. Only for use in undo manager.
   *
   */
  virtual void Undo() noexcept;

  /**
   * @brief Redoes the operation contained in. Only for use in undo manager.
   *
   */
  virtual void Redo() noexcept;
};
} // namespace Axum::Operator
#endif //_OPERATOR_H

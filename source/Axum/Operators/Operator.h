/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#ifndef _OPERATOR_H
#define _OPERATOR_H

#include <string>

namespace Axum::Operator{

/**
 * @brief Operator holds fields and methods required to do an undoable
 * operatation. Operations that are needed to be undoable should be derived from
 * @a Operator, override Execute (),Undo() and Redo() and register in
 * @a UndoManager after execution.
 *
 */
class Operator {
public:
  std::string UIName;
  std::string Name;

  /**
   * @brief Excutes the operation contained in.
   *
   */
  virtual void Execute();

  /**
   * @brief Undoes the operation contained in.
   *
   */
  virtual void Undo();

  /**
   * @brief Redoes the operation contained in and registers this operator in
   * UndoManager.
   *
   */
  virtual void Redo();
};
}
#endif //_OPERATOR_H

/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#ifndef _UNDOMANAGER_H
#define _UNDOMANAGER_H

#include "Operators/Operator.h"
#include "PreferenceManager.h"
#include "boost/circular_buffer.hpp"

namespace Axum::Manager {

// a special iterator for RecentOpreations
typedef boost::circular_buffer<Operator>::iterator uiterator;
class UndoManager {
public:
  static UndoManager &getInstance() {
    static UndoManager instance;
    return instance;
  }

private:
  UndoManager(){};
  /**
   * Circular Array to contain recent actions.
   */
  boost::circular_buffer<Operator> RecentOperations;
  /**
   * Position of the last operation.
   */
  uiterator nextUndo;
  /*
   *true if the first operation is not undone and false if it is undone
   */
  bool canUndoFurther = false;

public:
  UndoManager(UndoManager const &) = delete;
  void operator=(UndoManager const &) = delete;
  /**
   * @param mOperator
   */
  void AddOperation(Operator mOperator);

  void Undo();

  void Redo();

  void Startup();

  void Shutdown();
};

} // namespace Axum::Manager

/**
 * @brief Shortcut to the instance of UndoManager.
 * 
 */
#define Undo_Manager Axum::Manager::UndoManager::getInstance() 
#endif //_UNDOMANAGER_H

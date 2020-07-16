/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#include "UndoManager.h"


/**
 * UndoManager implementation
 */

namespace Axum::Manager {

void UndoManager::AddOperation(Operator::Operator mOperator) {
  if (RecentOperations.size() == 0) {
    // append the operator at the end of the list
    RecentOperations.push_back(mOperator);
    nextUndo = RecentOperations.begin();
    canUndoFurther = true;
    return;
  }
  // check if there are no redo operation
  if (nextUndo == RecentOperations.end()) {
    // append the operator at the end of the list
    RecentOperations.push_back(mOperator);
    // check if the list is not full
    if (++nextUndo != RecentOperations.begin()) {
      // the list is not full yet so increment the iterator
      ++nextUndo;
    }
  }
  // there are redo operations at the front of the next undo
  else {
    // removes any redoable operations
    for (uiterator i = RecentOperations.end(); i > nextUndo; i--) {
      RecentOperations.pop_back();
    }
    // appends the operator at the end of the list
    RecentOperations.push_back(mOperator);
    // increments the iterator
    ++nextUndo;
  }
  RecentOperations.back().Execute();
  // now there is undoable operation
  canUndoFurther = true;
}

void UndoManager::Undo() {
  // checks if next undo is the first operation
  if (nextUndo == RecentOperations.begin()) {
    // nextundo is the first operation so check if we have not undone it already
    if (canUndoFurther) {
      // we haven't undone it so undo
      (*nextUndo).Undo();
      // set canundo false so we don't undo it any more
      canUndoFurther = false;
    }
  }
  // nextUndo is not the first operation so there are precedding operations
  else {
    // undoes the operation
    (*nextUndo).Undo();
    // decrements the iterator
    --nextUndo;
  }
}

void UndoManager::Redo() {
  // checks if there are redoable opreations
  if (nextUndo != RecentOperations.end()) {
    // increments nextUndo so it is now the next redoable operation
    ++nextUndo;
    // redos
    (*nextUndo).Redo();
  }
}

void UndoManager::Startup() {
  int undoSteps = Preference_Manager.getPreference<int>(
      "system.undo_steps", 50);
  RecentOperations = boost::circular_buffer<Operator::Operator>(undoSteps);
}

void UndoManager::Shutdown() {}

} // namespace Axum::Manager
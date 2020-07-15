/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#include "UndoManager.h"


/**
 * UndoManager implementation
 */

namespace Axum::Manager {

/**
 * @param mOperator
 */
void UndoManager::AddOperation(Operator::Operator mOperator) {
  if (this->RecentOperations.size() == 0) {
    // append the operator at the end of the list
    this->RecentOperations.push_back(mOperator);
    this->nextUndo = this->RecentOperations.begin();
    this->canUndoFurther = true;
    return;
  }
  // check if there are no redo operation
  if (this->nextUndo == this->RecentOperations.end()) {
    // append the operator at the end of the list
    this->RecentOperations.push_back(mOperator);
    // check if the list is not full
    if (++this->nextUndo != this->RecentOperations.begin()) {
      // the list is not full yet so increment the iterator
      ++this->nextUndo;
    }
  }
  // there are redo operations at the front of the next undo
  else {
    // remove any redoable operations
    for (uiterator i = this->RecentOperations.end(); i > this->nextUndo; i--) {
      this->RecentOperations.pop_back();
    }
    // append the operator at the end of the list
    this->RecentOperations.push_back(mOperator);
    // increment the iterator
    ++this->nextUndo;
  }
  // now there is undoable operation
  this->canUndoFurther = true;
}

void UndoManager::Undo() {
  // check if next undo is the first operation
  if (this->nextUndo == this->RecentOperations.begin()) {
    // nextundo is the first operation so check if we have not undone it already
    if (this->canUndoFurther) {
      // we haven't undone it so undo
      (*this->nextUndo).Undo();
      // set canundo false so we don't undo it any more
      this->canUndoFurther = false;
    }
  }
  // nextUndo is not the first operation so there are precedding operations
  else {
    // undo the operation
    (*this->nextUndo).Undo();
    // decrement the iterator
    --this->nextUndo;
  }
}

void UndoManager::Redo() {
  // check if there are redoable opreations
  if (this->nextUndo != this->RecentOperations.end()) {
    // increment nextUndo so it is now the next redoable operation
    ++this->nextUndo;
    // redo
    (*this->nextUndo).Redo();
  }
}

void UndoManager::Startup() {
  int undoSteps = PreferenceManager::getInstance().getPreference<int>(
      "system.undo_steps", 50);
  this->RecentOperations = boost::circular_buffer<Operator::Operator>(undoSteps);
}

void UndoManager::Shutdown() {}

} // namespace Axum::Manager
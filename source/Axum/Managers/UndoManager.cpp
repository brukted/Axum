/**
 * Project Material Lab
 * @author Bruk Tedla
 */


#include "UndoManager.h"

/**
 * UndoManager implementation
 */


/**
 * @param mOperator
 */
void UndoManager::AddOperation(Operator mOperator) {
     //check if there are no redo operation
     if (this->nextUndo == this->RecentOperations.end())
     {
         //append the opreator at the end of the list
         this->RecentOperations.push_back(mOperator);
         //check if the list is not full
         if(++this->nextUndo != this->RecentOperations.begin()){
              //the list is not full yet so increment the itreator
              ++this->nextUndo;
         }
     }
     //there are redo operations at the front of the next undo
     else
     {
         //remove any redoable operations
         for (uiterator i = this->RecentOperations.end(); i > this->nextUndo; i--)
         {
             this->RecentOperations.pop_back();
         }
         //append the opreator at the end of the list
         this->RecentOperations.push_back(mOperator);
         //increment the itreator
         ++this->nextUndo;
     }
     //now there is undoable operation
     this->canUndoFurther = true;
}

void UndoManager::Undo() {
    //check if next undo is the first opreation
    if(this->nextUndo == this->RecentOperations.begin()){
        //nextundo is the first operation so check if we have not undone it already
        if (this->canUndoFurther)
        {
            //we haven't undone it so undo 
            (*this->nextUndo).Undo();
            //set canundo false so we don't undo it any more
            this->canUndoFurther = false;
        }
    }
    //nextUndo is not the first operation so there are precedding operations 
    else{
        //undo the operation
        (*this->nextUndo).Undo();
        //decrement the itreator
        --this->nextUndo;
        
    }
}

void UndoManager::Redo() {
    //check if there are redoable opreations
    if(this->nextUndo != this->RecentOperations.end()){
        //incerement nextUndo so it is now the next redoable opreation
        ++this->nextUndo;
        //redo
        (*this->nextUndo).Redo();
    }
}


void UndoManager::Startup(){
    int undoSteps = (MApplication::context)->PrefMan.getPreference<int>("system.undo_steps",50);
    this->RecentOperations = boost::circular_buffer<Operator> (undoSteps);
}

void UndoManager::Shutdown(){
    
}
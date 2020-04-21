/**
 * Project Material Lab
 * @author Bruk Tedla
 */


#ifndef _UNDOMANAGER_H
#define _UNDOMANAGER_H

#include"boost/circular_buffer.hpp"
#include"../Operators/Operator.h"


class UndoManager {
private: 
	/**
	 * Circular Array to contain recent actions.
 	*/
	boost::circular_buffer<Operator> RecentOperations;
	/**
 	* Position of the last operation.
 	*/
	int Position;
	/**
 	* @param mOperator
 	*/
	void AddOperation(Operator mOperator);
	
	void Undo();
	
	void Redo();
	
	void Repeat();
public:
	void Startup();

	void Shutdown();

};

#endif //_UNDOMANAGER_H

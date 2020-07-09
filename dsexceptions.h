/**************************************************************
 * File:    dsexceptions.h
 * Project: CMSC 341 - Project 3 - Word Freq Splay Tree
 * Author : Rooklyn Kline
 * Date   : 16-July-2020
 * Section: Lecture-02
 * E-mail: rkline2@umbc.edu
 *
 * dsexceptions Class definitions.
 *
 *************************************************************/

#ifndef DS_EXCEPTIONS_H
#define DS_EXCEPTIONS_H

#include <stdexcept>
#include <string>
using namespace std;

class UnderflowException : public out_of_range {
public:
	/**********************************************************************
	 * Name: UnderflowException (Constructors)
	 * PreCondition: String containing error description 
	 * or containing no parameters.
	 *
	 * PostCondition:  Error object
	 *********************************************************************/
	UnderflowException() : out_of_range("Value out of range") {}
	UnderflowException(const string& what) : out_of_range(what) {}
};

class IllegalArgumentException : public invalid_argument {
public:
	/**********************************************************************
	 * Name: IllegalArgumentException (Constructors)
	 * PreCondition: String containing error description
	 * or containing no parameters.
	 *
	 * PostCondition:  Error object
	 *********************************************************************/
	IllegalArgumentException() : invalid_argument("Invalid argument") {}
	IllegalArgumentException(const string& what) : invalid_argument(what) {}
};

class ArrayIndexOutOfBoundsException : public out_of_range {
public:
	/**********************************************************************
	 * Name: ArrayIndexOutOfBoundsException (Constructors)
	 * PreCondition: String containing error description
	 * or containing no parameters.
	 *
	 * PostCondition:  Error object
	 *********************************************************************/
	ArrayIndexOutOfBoundsException() : out_of_range("Current value out of range") {}
	ArrayIndexOutOfBoundsException(const string& what) : out_of_range(what) {}
};

class IteratorOutOfBoundsException : public out_of_range {
public:
	/**********************************************************************
	 * Name: IteratorOutOfBoundsException (Constructors)
	 * PreCondition: String containing error description
	 * or containing no parameters.
	 *
	 * PostCondition:  Error object
	 *********************************************************************/
	IteratorOutOfBoundsException() : out_of_range("Iterator out of range") {}
	IteratorOutOfBoundsException(const string& what) : out_of_range(what) {}
};

class IteratorMismatchException : public invalid_argument {
public:
	/**********************************************************************
	 * Name: IteratorMismatchException (Constructors)
	 * PreCondition: String containing error description
	 * or containing no parameters.
	 *
	 * PostCondition:  Error object
	 *********************************************************************/
	IteratorMismatchException() : invalid_argument("Iterator value not valid") {}
	IteratorMismatchException(const string& what) : invalid_argument(what) {}
};

class IteratorUninitializedException : public invalid_argument {
public:
	/**********************************************************************
	 * Name: IteratorUninitializedException (Constructors)
	 * PreCondition: String containing error description
	 * or containing no parameters.
	 *
	 * PostCondition:  Error object
	 *********************************************************************/
	IteratorUninitializedException() : invalid_argument("Iterator not initialized") {}
	IteratorUninitializedException(const string& what) : invalid_argument(what) {}
};

#endif


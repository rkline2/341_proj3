#ifndef DS_EXCEPTIONS_H
#define DS_EXCEPTIONS_H

#include <stdexcept>
#include <string>
using namespace std;

class UnderflowException : public out_of_range {
public:
	UnderflowException() : out_of_range("Value out of range") {}
	UnderflowException(const string& what) : out_of_range(what) {}
};

class IllegalArgumentException : public invalid_argument {
public:
	IllegalArgumentException() : invalid_argument("Invalid argument") {}
	IllegalArgumentException(const string& what) : invalid_argument(what) {}
};

class ArrayIndexOutOfBoundsException : public out_of_range {
public:
	ArrayIndexOutOfBoundsException() : out_of_range("Current value out of range") {}
	ArrayIndexOutOfBoundsException(const string& what) : out_of_range(what) {}
};

class IteratorOutOfBoundsException : public out_of_range {
public:
	IteratorOutOfBoundsException() : out_of_range("Iterator out of range") {}
	IteratorOutOfBoundsException(const string& what) : out_of_range(what) {}
};

class IteratorMismatchException : public invalid_argument {
public:
	IteratorMismatchException() : invalid_argument("Iterator value not valid") {}
	IteratorMismatchException(const string& what) : invalid_argument(what) {}
};

class IteratorUninitializedException : public invalid_argument {
public:
	IteratorUninitializedException() : invalid_argument("Iterator not initialized") {}
	IteratorUninitializedException(const string& what) : invalid_argument(what) {}
};

#endif


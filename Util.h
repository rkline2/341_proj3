/**************************************************************
 * File:    Util.h
 * Project: CMSC 341 - Project 3 - Word Frequency
 * Author : Rooklyn Kline
 * Date   : 16-July-2020
 * Section: Lecture-02
 * E-mail: rkline2@umbc.edu
 *
 * Util Class definition.
 *
 * This class provides some support functions to other classes.
 *
 * Lower() - Returns a string in lower case.
 * Strip() - Removes all nonalpha characters except ' and -
 * FileExisits() - Verifes a file exists.
 *
 *************************************************************/
#ifndef UTIL_H
#define UTIL_H

#include <string>
#include <fstream>
#include "SplayTree.h"


const string EMPTY_STR = "", WORD_SP = " ";												//<-|
const char APOST = '\'', QUOTE = '"', DASH = '-', DELIM = ' ';							//  | Filtration conditions  
const int ASCII_MIN_CHAR = -1, ASCII_MAX_CHAR = 255, MIN_UPPER = 65, MAX_UPPER = 90;	//  | and cases
const int MAX_ESCAPE_SEQ = 33, DEL_ESCAPE_SEQ = 127;									//<-|

class Util {

public:
	/**********************************************************************
	 * Name: Lower (Static)
	 * PreCondition: String.
	 *
	 * PostCondition:  Lower case version of string.
	 *********************************************************************/
	static std::string Lower(std::string inString);


	/**********************************************************************
	 * Name: Strip (Static)
	 * PreCondition: String.
	 *
	 * PostCondition:  Returns string of just alpha characters.
	 *********************************************************************/
	static std::string Strip(std::string inString);


	/**********************************************************************
	 * Name: FileExisits (Static)
	 * PreCondition: Name of file to check for.
	 *
	 * PostCondition:  Bool True if the file is available.
	 *********************************************************************/
	static bool FileExists(const char* filename);

};


#endif

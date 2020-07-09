/**************************************************************
 * File:    MyExceptions.h
 * Project: CMSC 341 - Project 3 - Word Freq Splay Tree
 * Author : Rooklyn Kline
 * Date   : 16-July-2020
 * Section: Lecture-02
 * E-mail: rkline2@umbc.edu
 *
 * MyExceptions Class definition.
 *
 *************************************************************/
#ifndef MYEXCEPTIONS_H
#define MYEXCEPTIONS_H
#include <string>

class Exceptions {
public:
    /**********************************************************************
     * Name: MyExceptions (Constructor)
     * PreCondition: String containing error description.
     *
     * PostCondition:  Error object
     *********************************************************************/
    Exceptions(std::string message) : m_message(message) {}

    /**********************************************************************
     * Name: GetMessage
     * PreCondition: None.
     *
     * PostCondition:  Returns error message.
     *********************************************************************/
    const std::string GetMessage() { return m_message; }

private:

    std::string m_message; //Error message.
};

#endif

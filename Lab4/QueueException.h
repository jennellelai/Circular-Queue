//Modified from Carrano, Data Abstraction & Problem Solving with C++, Fifth Edition,
// Pearson Education, 2007, page 348.

#ifndef _QUEUE_EXCEPTION
#define _QUEUE_EXCEPTION

#include <stdexcept>
#include <string>

using namespace std;



/*
 
 The QueueException class throws exceptions for an array-based queue that contains <ItemType> items.
 
 
 
 @author Jennelle Lai
 @class QueueException.h
 @date December 1, 2015
 @lab 4: Circular Queue
 @instructor Abensohn
 
 
 
 QueueException(const string& message = "");
 Precondition: An ArrayQueue is declared
 Postcondition: Throws an exception with a string
 
 */



class QueueException : public logic_error
{
public:
    QueueException(const string& message = "")
    : logic_error(message.c_str())
    {}
};

#endif

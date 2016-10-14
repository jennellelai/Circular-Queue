//Modified from the following:
//Created by Frank M. Carrano and Tim Henry.
//Copyright (c) 2013 __Pearson Education__. All rights reserved.

/** @file QueueInterface.h */

#ifndef _QUEUE_INTERFACE
#define _QUEUE_INTERFACE



/*
 
 The QueueInterface class represents an array-based queue that contains <ItemType> items.
 
 
 
 @author Jennelle Lai
 @class QueueInterface.h
 @date December 1, 2015
 @lab 4: Circular Queue
 @instructor Abensohn
 
 
 
 bool isEmpty() const = 0;
 Precondition: An ArrayQueue is declared
 Postcondition: Returns true if the queue is empty; otherwise false if the queue is not empty
 
 void enqueue(const ItemType& newEntry) = 0;
 Precondition: An ArrayQueue is declared and newEntry is an initialized
 Postcondition: Adds newEntry into the queue if the queue is not full, otherwise throws exception if the queue is full
 
 void dequeue() = 0;
 Precondition: An ArrayQueue is declared
 Postcondition: Removes the first item in the queue if the queue is not empty; otherwise throws exception if the queue is empty
 
 ItemType peekFront() const = 0;
 Precondition: An ArrayQueue is declared
 Postcondition: Returns the first item in the queue if the queue is not empty; otherwise throws exception if the queue is empty

 */



template<class ItemType>
class QueueInterface
{
public:
    /** Sees whether this Queue is empty.
     @return true if the Queue is empty, or false if not. */
    virtual bool isEmpty() const = 0;
    
    /** Adds a new entry to the back of this Queue.
     @post newEntry is at the back of the Queue
     @param newEntry The object is to be added as a new entry.
     @throw QueueException if Queue is full. */
    virtual void enqueue(const ItemType& newEntry) = 0;
    
    /** Removes the front of this Queue.
     @post The front of the Queue is removed.
     @throw QueueException if Queue is initially empty. */
    virtual void dequeue() = 0;
    
    /** Returns a copy of the front of this Queue.
     @post A copy of the front of the Queue is returned, and the Queue is unchanged.
     @return A copy of the front of the Queue.
     @throw QueueException if Queue is initially empty. */
    virtual ItemType peekFront() const = 0;
};

#endif

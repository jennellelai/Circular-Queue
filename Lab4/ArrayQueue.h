//Modified from the following:
//Created by Frank M. Carrano and Tim Henry.
//Copyright (c) 2013 __Pearson Education__. All rights reserved.


/** ADT Queue: Array-based implementation.
 Listing 7-1
 @file ArrayQueue.h */

#ifndef _ARRAY_QUEUE
#define _ARRAY_QUEUE

#include "QueueInterface.h"
#include "QueueException.h"



/*
 
 The ArrayQueue class represents an array-based queue that contains <ItemType> items.
 
 
 
 @author Jennelle Lai
 @class ArrayQueue.h
 @date December 1, 2015
 @lab 4: Circular Queue
 @instructor Abensohn
 
 
 
 ArrayQueue();
 Precondition: An ArrayQueue is declared
 Postcondition: front is initialized to 0, back is initialized to MAX_QUEUE - 1, and isFull is initialized to false
 
 bool isEmpty() const;
 Precondition: An ArrayQueue is declared
 Postcondition: Returns true if the queue is empty; otherwise false if the queue is not empty
 
 void enqueue(const ItemType& newEntry);
 Precondition: An ArrayQueue is declared and newEntry is an initialized
 Postcondition: Adds newEntry into the queue if the queue is not full, otherwise throws exception if the queue is full
 
 void dequeue();
 Precondition: An ArrayQueue is declared
 Postcondition: Removes the first item in the queue if the queue is not empty; otherwise throws exception if the queue is empty
 
 ItemType peekFront() const;
 Precondition: An ArrayQueue is declared
 Postcondition: Returns the first item in the queue if the queue is not empty; otherwise throws exception if the queue is empty
 
 void display();
 Precondition: An ArrayQueue is declared
 Postcondition: Prints out all of the items in the queue
 
 */



const int MAX_QUEUE = 4;

template<class ItemType>
class ArrayQueue : public QueueInterface<ItemType>
{
private:
    ItemType items[MAX_QUEUE]; //Array of Queue items
    int front; //Index to front of Queue
    int back; //Index to back of Queue
    bool isFull; //Flag to indicate whether or not the queue is full
    
public:
    ArrayQueue();
    //Copy constructor and destructor are supplied by the compiler
    
    /** Sees whether this Queue is empty.
     @return true if the Queue is empty, or false if not. */
    bool isEmpty() const;
    
    /** Adds a new entry to the back of this Queue.
     @post newEntry is at the back of the Queue
     @param newEntry The object is to be added as a new entry.
     @throw QueueException if Queue is full. */
    void enqueue(const ItemType& newEntry);
    
    /** Removes the front of this Queue.
     @post The front of the Queue is removed.
     @throw QueueException if Queue is initially empty. */
    void dequeue();
    
    /** Returns a copy of the front of this Queue.
     @post A copy of the front of the Queue is returned, and the Queue is unchanged.
     @return A copy of the front of the Queue.
     @throw QueueException if Queue is initially empty. */
    ItemType peekFront() const;
    
    /** Displays the items of this Queue.
     @post Items of the Queue are printed out. */
    void display();
};

#include "ArrayQueue.cpp"
#endif

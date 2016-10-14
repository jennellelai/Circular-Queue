//Modified from the following:
//Created by Frank M. Carrano and Tim Henry.
//Copyright (c) 2013 __Pearson Education__. All rights reserved.

/** Listing 7-1
 @file ArrayQueue.cpp */
#include "ArrayQueue.h"



/**
 
 The ArrayQueue class represents a an array-based queue that contains <ItemType> items.
 
 
 
 @author Jennelle Lai
 @class ArrayQueue.cpp
 @date December 1, 2015
 @lab 4: Circular Array
 @instructor Abensohn
 
 
 */










/**
 This ArrayQueue() constructor initializes front to 0, back to MAX_QUEUE - 1, and isFull to false
 
 @param none
 @pre An ArrayQueue is declared
 @post front is initialized to 0, back is initialized to MAX_QUEUE - 1, and isFull is initialized to false
 */

template<class ItemType>
ArrayQueue<ItemType>::ArrayQueue() : front(0), back(MAX_QUEUE - 1), isFull(false)
{
}








/**
 This isEmpty() function returns true if the queue is empty; otherwise returns false if the queue is not empty
 
 @param none
 @pre An ArrayQueue is declared
 @return true if the queue is empty; otherwise false if the queue is not empty
 */

template<class ItemType>
bool ArrayQueue<ItemType>::isEmpty() const
{
    return (back + 1) % MAX_QUEUE == front && !isFull;
}








/** 
 This enqueue() function adds newEntry to the back of this Queue.
 
 @post newEntry is at the back of the Queue
 @param newEntry The object is to be added as a new entry.
 @throw QueueException if Queue is full. 
 */

template<class ItemType>
void ArrayQueue<ItemType>::enqueue(const ItemType& newEntry)
{
    if(isFull)
        throw QueueException("QueueException: Queue full on enqueue");
    else
    {
        back = (back + 1) % MAX_QUEUE;
        items[back] = newEntry;
        
        if ((back + 1) % MAX_QUEUE == front)
        {
            isFull = true;
        }
        else
        {
            isFull = false;
        }
        
    }
}








/** 
 This dequeue() function removes the front of this Queue.
 
 @post The front of the Queue is removed.
 @throw QueueException if Queue is initially empty.
 */

template<class ItemType>
void ArrayQueue<ItemType>::dequeue()
{
    if(isEmpty())
        throw QueueException("QueueException: Queue empty on dequeue");
    else
    {
        front = (front+1) % MAX_QUEUE;
        isFull = false;
    }
}








/** 
 This peekFront() function returns a copy of the front of this Queue.
 
 @post A copy of the front of the Queue is returned, and the Queue is unchanged.
 @return A copy of the front of the Queue.
 @throw QueueException if Queue is initially empty.
 */

template<class ItemType>
ItemType ArrayQueue<ItemType>::peekFront() const
{
    if(isEmpty())
        throw QueueException("QueueException: Queue empty on peekFront");
    else
        return items[front];
}







/**
 This display() function displays the items of this Queue.
 
 @post Items of the Queue are printed out.
 */

template<class ItemType>
void ArrayQueue<ItemType>::display()
{
    cout << "Queue contents: ";
    
    int index;
    
    if((back + 1) % MAX_QUEUE == front && !isFull)
    {
        cout << "Empty" << endl;
    }
    else if (front > back && front - back >= 1)
    {
        for(index = front; index <= MAX_QUEUE - 1; index++)
        {
            cout << items[index] << " ";
        }
        
        for(index = 0; index <= back; index++)
        {
            cout << items[index] << " ";
        }
    }
    else if(front > back)
    {
        for(index = 0; index <= back; index++)
        {
            cout << items[index] << " ";
        }
        
        for(index = front; index <= MAX_QUEUE - 1; index++)
        {
            cout << items[index] << " ";
        }
    }
    else
    {
        for(index = front; index <= back; index++)
        {
            cout << items[index] << " ";
        }
    }
    
    cout << endl;
}
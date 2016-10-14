//Modified from the following:
//Created by Frank M. Carrano and Tim Henry.
//Copyright (c) 2013 __Pearson Education__. All rights reserved.

/** Listing 7-1
 @file ArrayQueue.cpp */
#include "ArrayQueue.h"


template<class ItemType>
ArrayQueue<ItemType>::ArrayQueue() : front(0), back(MAX_QUEUE - 1), isFull(false)
{
}

template<class ItemType>
bool ArrayQueue<ItemType>::isEmpty() const
{
//    if (isFull)
//    {
//        return false;
//    }
    
    return ((front + back) == MAX_QUEUE - 1) && !isFull;
}

/** @throw QueueException if Queue is full. */
template<class ItemType>
void ArrayQueue<ItemType>::enqueue(const ItemType& newEntry)
{
    if(isFull)
        throw QueueException("QueueException: Queue full on enqueue");
    else
    {
        back = (back + 1) % MAX_QUEUE;
        items[back] = newEntry;
        
        if (front != back && (((front % (MAX_QUEUE - 1)) - (back % (MAX_QUEUE - 1)) == 0 || (front % (MAX_QUEUE - 1)) - (back % (MAX_QUEUE - 1)) == 1)) && (((front + back) == MAX_QUEUE - 1) || ((front + back) == 1) || ((front + back) > MAX_QUEUE)))
        {
            isFull = true;
        }
        else
        {
            isFull = false;
        }
    }
}

/** @throw QueueException if Queue is initially empty. */
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

/** @throw QueueException if Queue is empty. */
template<class ItemType>
ItemType ArrayQueue<ItemType>::peekFront() const
{
    if(isEmpty())
        throw QueueException("QueueException: Queue empty on peekFront");
    else
        return items[front];
}

template<class ItemType>
void ArrayQueue<ItemType>::display()
{
    cout << endl << "front: " << front << "back: " << back << endl;
    
    int frontIndex;
    
    cout << "Queue contents: ";
    
    if (isEmpty()) {
        cout << " " << endl;
    }
    else if (front == back)
    {
        cout << items[front];
    }
    else {
        frontIndex = front;
        
        do
        {
            cout << items[frontIndex] << " ";
            frontIndex = (frontIndex + 1) % MAX_QUEUE;
        } while(frontIndex != back);
        
        cout << items[back];
    }
    
    cout << endl;
}
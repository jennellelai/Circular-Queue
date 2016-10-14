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
    return (!isFull && (((back - front) == 3) || ((back - front) == -3)));
}

/** @throw QueueException if Queue is full. */
template<class ItemType>
void ArrayQueue<ItemType>::enqueue(const ItemType& newEntry)
{
    
    if (isFull == true)
    {
        throw QueueException("QueueException: Queue full on enqueue");
    }
    else
    {
        if (front == back && !isEmpty())
        {
            isFull = true;
        }
        else
        {
            back = (back + 1) % MAX_QUEUE;
            items[back] = newEntry;
        }
    }
}

/** @throw QueueException if Queue is initially empty. */
template<class ItemType>
void ArrayQueue<ItemType>::dequeue()
{
    if(isEmpty())
    {
        throw QueueException("QueueException: Queue empty on dequeue");
    }
    else
    {
        front = (front+1) % MAX_QUEUE;
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
    cout << "Queue contents: ";
    
    for (int i = front; i < back; i++)
    {
        cout << items[i] << " ";
    }
    
    cout << endl;
}
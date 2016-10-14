//Modified from the following:
//Created by Frank M. Carrano and Tim Henry.
//Copyright (c) 2013 __Pearson Education__. All rights reserved.

/** Listing 7-1
 @file ArrayQueue.cpp */
#include "ArrayQueue.h"


template<class ItemType>
ArrayQueue<ItemType>::ArrayQueue() : front(0), back(MAX_QUEUE - 1), count(0)
{
}

template<class ItemType>
bool ArrayQueue<ItemType>::isEmpty() const
{
    return count == 0;
}

/** @throw QueueException if Queue is full. */
template<class ItemType>
void ArrayQueue<ItemType>::enqueue(const ItemType& newEntry)
{
    if(count >= MAX_QUEUE)
        throw QueueException("QueueException: Queue full on enqueue");
    else
    {
        back = (back + 1) % MAX_QUEUE;
        items[back] = newEntry;
        count++;
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
        count--;
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
    
    int i;
    cout << "front : " << front << "   back : " << back << endl;
    
    if (isEmpty()) {
        cout << " " << endl;
        return;
    }
    else if (front == back)
    {
        cout << items[front];
    }
    else {
        i = front;
        do {
            cout << items[i] << " ";
            i = (i + 1) % MAX_QUEUE;
        } while(i != back);
        
        cout << items[back];
    }
    
    cout << endl;
}
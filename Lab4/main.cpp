#include <iostream>
#include "QueueInterface.h"
#include "QueueException.h"
#include "ArrayQueue.h"
using namespace std;



/**
 
 This program creates an array-based queue called intQueue, which stores integers. The user is asked to select three choices, 1) Add item to queue, 2) Remove item from queue, or 3) Exit program. If the user chooses 1, then they are asked to enter an integer to store into the queue. If the queue is not full, then the item is stored in the end of the queue; otherwise if it is full, then the user is prompted that it is unable to add the integer into the queue. Likewise, if the user chooses 2, the first integer that was first entered in relative to all the other integers in the queue is removed first only- if the queue is not empty; otherwise if it is empty, then the user is prompted that it is unable to remove any integers. Lastly, if the user chooses 3, then the program exits.
 
 @author Jennelle Lai
 @class main program
 @date December 1, 2015
 @lab 4: Circular Queue
 @instructor Abensohn
 
 */



int main()
{
    bool keepAsking = true; //Bool: If it is true, ask user the menu prompt; otherwise, don't ask
    int selectionInput, itemInput; //selectionInput: stores the user's menu selection input
                                   //itemInput: stores the user's item input into the queue
    ArrayQueue<int> intQueue = *new ArrayQueue<int>; //Queue that stores integer datatypes
    
    do
    {
        cout << "1) Add item to queue" << endl << "2) Remove item from queue" << endl << "3) Exit program" << endl << "Enter your selection (1-3): ";
        cin >> selectionInput;
        
        if (selectionInput == 1)
        {
            cout << "Enter item to insert: ";
            cin >> itemInput;
            try
            {
                intQueue.enqueue(itemInput); //Add itemInput into intQueue
                intQueue.display(); //Display all items in intQueue
            }
            catch (QueueException e)
            {
                cout << "Unable to insert into full queue" << endl;
            }
            
            cout << endl;
        }
        else if (selectionInput == 2)
        {
            try
            {
                intQueue.dequeue(); //Remove an item from intQueue
                intQueue.display(); //Display all items in intQueue
            }
            catch (QueueException e)
            {
                cout << "Unable to remove item from empty queue" << endl;
            }
            
            cout << endl;
        }
        
        else if (selectionInput == 3)
        {
            keepAsking = false; //Don't ask menu prompt anymore
        }
        else
        {
            cout << "Please input a valid number from 1-3." << endl;
        }
    } while (keepAsking);
}
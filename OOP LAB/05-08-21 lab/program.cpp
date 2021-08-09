/* Question : 1. Write a C++ program to implement a queue or Circular queue ADT as a header file using class. Create a class
for a queue with the following operations, enqueue, dequeue, display, peek, isFull, and isEmpty functions. Declare
the enqueue and dequeue member functions inside the queue class and write their definitions outside the queue class
using scope resolution operator. Define the remaining functions inside the queue class. The data members(variables 
declared inside the function) should use "Private" access specifier and member functions (function declared and defined 
withing the scope of a class) should use "Public" access specifier. Assume the queue stores integers and can store a 
maximum of  5 integers. Note: Should use cin and cout for getting and displaying values. Import the created queue header 
file into a "printer.cpp" file. The printer.cpp has the following menus,
1. Add to Print Queue
2. Current Job
3. Execute a Job
4. Display Jobs
5. Exit
Option 1 gets an integer job ID and stores it into the queue. 2 prints the job ID that will be executed next. 3 removes 
the currently executed job ID from the queue and prints  a message that The job <<Insert job ID>> has been completed. 4 
Displays all the jobs pending in the queue pool. 5 quits from the program. Any other option should prompt the user to 
enter a valid option.
Thus program is done by CS20B1044 Avinash R Changrani */

// Menu Driven Program for Queue
#include "queue.hpp"
#include <iostream>
using namespace std;

int main(){
    Queue Q1;
    int choice, id, temp;
    while(1){
        cout<<"\nMenu : \n 1)Add to Print Queue \n 2)Current Job \n 3)Execute a Job \n 4)Display Jobs \n 5)Exit";
        cout<<"\nPlease Enter your choice: ";
        cin>>choice;
        switch(choice){
            // To get the job ID and add it to the queue (except -1 as it's used for telling if queue is empty)
            case 1:
                cout<<"Please Enter a job ID to add to the queue: ";
                cin>>id;
                Q1.enqueue(id);
                break;
            // To get the job ID that will be exceuted next and print it
            case 2:
                if (Q1.peek() == -1)
                    cout<<"\nNo job ID in the Queue! Queue is Empty!\n";
                else 
                    cout<<"\nThe job ID to be executed next is " << Q1.peek();   
                break;
            // To remove the job ID and print that it has been executed         
            case 3:
                id = Q1.dequeue();
                if (id == - 1)
                    cout <<"\nNo job ID in the Queue! Queue is Empty!";
                else 
                    cout <<"\nThe job ID "<< id << " has been executed";
                break;
            // To display all the pending jobs in the Queue pool   
            case 4:
                Q1.display();
                break;
            // To exit the program    
            case 5:
                exit(0);
            default:   
                cout<<"\nWrong choice, Please try again!\n"; 
        }
    }
    return 0;
}
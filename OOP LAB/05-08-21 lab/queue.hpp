// Program to implement Queue
// This Program is done by CS20B1044 Avinash R Changrani
#include<iostream>
#define SIZE 5
using namespace std;

// Class definition for Circular queue ADT
class Queue {
    private:
        int front, rear;
        int arr[SIZE]; // As Limit of Queue is 5
    public:
        Queue(){
            front = rear = -1;
        }
        // Function to check whether the Queue is Empty or not
        bool isEmpty(){ 
            return (front == -1);
        }
        // Function to check whether the Queue is Full or not
        bool isFull(){ 
            return (((rear + 1) % SIZE) == front);
        }
        void enqueue(int);
        int dequeue();
        int peek();
        void display(){
            if (isEmpty()){
                cout << "No job IDs in the Queue! Queue is Empty!" << endl;
                return;
            }
            else{
                cout << "\nJob IDs in Queue are : ";
                for (int i = front; i != rear;i = ((i + 1) % SIZE)){
                    cout<< arr[i] << " ";
                }
                cout<< arr[rear] << " ";    
            }
        }
};

// Function to add a element to the Circular Queue
void Queue::enqueue(int ID){
    // When the Queue is Full
    if (isFull()){
        cout << "Queue is Full! All job IDs are yet to be executed!" << endl;
        return;
    }
    else {
        rear = (rear + 1) % SIZE;
        arr[rear] = ID;
        if (isEmpty())
            front = rear;
    }
}

// Function to delete a element from the Queue
int Queue::dequeue(){
    if (isEmpty()){
        return -1;
    }
    else {
        int temp = arr[front];
        if (front == rear)
            front = rear = -1;
        else 
            front = (front + 1) % SIZE;
        return temp;
    }            
}

// Function to get the front element of the queue
int Queue::peek(){
        return (arr[front]);
}
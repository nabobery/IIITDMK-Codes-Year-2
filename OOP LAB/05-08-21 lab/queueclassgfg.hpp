// Program to implement Queue
// This Program is done by CS20B1044 Avinash R Changrani
#include<iostream>
#define SIZE 5
using namespace std;

// Class definition for Circular queue ADT
class Queue 
{
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
            return ((front == 0 && rear == SIZE-1) || (rear == (front-1)%(SIZE-1)));
        }
        void enqueue(int);
        int dequeue();
        int peek();
        void display(){
            if (isEmpty()){
                cout << "Queue is Empty" << endl;
                return;
            }
            cout << "\nJob IDs(elements) in Circular Queue are : ";
            if (rear >= front){
                for (int i = front; i <= rear; i++)
                    cout<< arr[i] << " ";
            }
            else{
                for (int i = front; i < SIZE; i++)
                    cout<< arr[i] << " ";
                for (int i = 0; i <= rear; i++)
                    cout<< arr[i] << " ";
            }
        }
};

// Function to add a element to the Circular Queue
void Queue::enqueue(int num){
    // When the Queue is Full
    if (isFull()){
        cout << "Queue is Full" << endl;
        return;
    }
    // When the first element is being added to the Queue
    else if (front == -1){
        front = rear = 0;
        arr[rear] = num;
    }
    // When the last element is being added to the Queue 
    else if (rear == SIZE-1 && front != 0){
        rear = 0;
        arr[rear] = num;
    }
    else {
        rear++;
        arr[rear] = num;
    }
}

// Function to delete a element from the Queue
int Queue::dequeue(){
    if (isEmpty()){
        return -1;
    }
    int temp = arr[front];
    arr[front] = -1;
    // If there was only one element in the queue before dequeue
    if (front == rear){
        front = -1;
        rear = -1;
    }
    // If the last element is being dequeued
    else if (front == SIZE - 1)
        front = 0;
    else 
        front++;
    return temp;    
}

// Function to get the front element of the queue
int Queue::peek(){
        return (arr[front]);
}
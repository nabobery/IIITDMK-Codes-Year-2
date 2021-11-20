#include <iostream>
using namespace std;

template <class T> class Stack {
    // Pubic access modifier
public:
    // Empty constructor
    Stack();
 
    // Method 1
    // To add element to stack which can be any type
    // using stack push() operation
    void push(T k);
 
    // Method 2
    // To remove top element from stack
    // using pop() operation
    T pop();
 
    // Method 3
    // To print top element in stack
    // using peek() method
    T topElement();
 
    // Method 4
    // To check whether stack is full
    // using isFull() method
    bool isFull();
 
    // Method 5
    // To check whether stack is empty
    // using isEmpty() method
    bool isEmpty();
 
private:
    // Taking data member top
    int top;
 
    // Initialising stack(array) of given size
    T st[SIZE];
};

// Method 6
// To initialise top to
// -1(default constructor)
template <class T> Stack<T>::Stack() { top = -1; }
 
// Method 7
// To add element element k to stack
template <class T> void Stack<T>::push(T k)
{
 
    // Checking whether stack is completely filled
    if (isFull()) {
        // Display message when no elements can be pushed
        // into it
        cout << "Stack is full\n";
    }
 
    // Inserted element
    cout << "Inserted element " << k << endl;
 
    // Incrementing the top by unity as element
    // is to be inserted
    top = top + 1;
 
    // Now, adding element to stack
    st[top] = k;
}
 
// Method 8
// To check if the stack is empty
template <class T> bool Stack<T>::isEmpty()
{
    if (top == -1)
        return 1;
    else
        return 0;
}
 
// Utility methods
 
// Method 9
// To check if the stack is full or not
template <class T> bool Stack<T>::isFull()
{
    // Till top in inside the stack
    if (top == (SIZE - 1))
        return 1;
    else
 
        // As top can not exceeds th size
        return 0;
}
 
// Method 10
template <class T> T Stack<T>::pop()
{
    // Initialising a variable to store popped element
    T popped_element = st[top];
 
    // Decreasing the top as
    // element is getting out from the stack
    top--;
 
    // Returning the element/s that is/are popped
    return popped_element;
}
 
// Method 11
template <class T> T Stack<T>::topElement()
{
    // Initialising a variable to store top element
    T top_element = st[top];
 
    // Returning the top element
    return top_element;
}

int main() {
    return 0;
}
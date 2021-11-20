// This program is done by CS20B1044 Avinash R Changrani
#include <iostream>
using namespace std;

// A class template for Stack
template <class T> class Stack {
    private :
        int top, size;
        T *stk;
    public:
        // Intialising Stack with size and top
        Stack(int Size){
            top = -1;
            size = Size;
            stk = new T[size];
        }
        // A function to know whether the stack is empty or not
        bool isFull(){
            return(top == size - 1);
        }
        // A function to know whether the stack is Full or not
        bool isEmpty(){
            return(top == -1);
        }
        // A function to push data onto the stack
        void push(T data){
            if(isFull()){
                cout<<"Stack is Full!! \n";
                return;
            }
            top = top + 1;
            stk[top] = data;
            cout << data << " is pushed into the stack\n";
        }
        // A function to pop data off the stack
        T pop(){
            if(isEmpty()){
                cout<<"Stack is Empty!!\n";
            }
            else {
                T element = stk[top];
                top--;
                cout<<"The element: "<< element <<" has been popped from the stack \n";
                return element;
            }
        }
        // A function to display elements of the stack
        void display(){
            if(isEmpty()){
                cout<<"Stack is Empty!!\n";
                return;
            }
            else {
                for(int i=0; i <= top; i++){
                    cout<< stk[i] << " ";
                }
                cout<< "\n";
            }
        }
};

// Menu Driven Program in main
int main() {
    int size1, size2, choice, option, element;
    char ch;
    cout<< "Please enter the size of the integer stack: ";
    cin >> size1;
    Stack <int> integerStack(size1);
    cout<< "Please enter the size of the character stack: ";
    cin >> size2;
    Stack <char> characterStack(size2);
    while(1){
        cout<<"Menu : \n 1)Push(Int or Char) \n 2)Pop (Int or Char) \n 3)Display(Int or Char) \n 4)Exit";
        cout<<"\nPlease Enter your choice: ";
        cin>>choice;
        if (choice == 1){
            cout<<"Enter 1 for pushing to the integer stack and 2 for the character stack: ";
            cin >> option;
            if(option == 1){
                cout<<"Please enter the element you want to push to the integer stack: ";
                cin >> element;
                integerStack.push(element);
            }
            else if(option == 2){
                cout<<"Please enter the element you want to push to the character stack: ";
                cin >> ch;
                characterStack.push(ch);
            }
            else {
                cout <<"Wrong choice, Please try again!\n";
            }
        }
        else if (choice == 2){
            cout<<"Enter 1 for popping to the integer stack and 2 for the character stack: ";
            cin >> option;
            if (option == 1){
                integerStack.pop();
            }    
            else if (option == 2){
                characterStack.pop();
            }
            else {
                cout <<"Wrong choice, Please try again!\n";
            }
        }
        else if (choice == 3){
            cout<<"Enter 1 for displaying the integer stack and 2 for the character stack: ";
            cin >> option;
            if (option == 1){
                cout<<"The integer stack is(from bottom to top): \n";
                integerStack.display();
            }
            else if (option == 2){
                cout<<"The character stack is(from bottom to top): \n";
                characterStack.display();
            }
            else {
                cout <<"Wrong choice, Please try again!\n";
            }
        }
        else if (choice == 4){
            exit(0);
        }
        else {
            cout <<"Wrong choice, Please try again!\n";
        }
    }
    return 0;
}

// CS20B1044 Avinash R Changrani
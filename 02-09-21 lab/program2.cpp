/* Write a C++ program using classes to implement a single linked list. The data members are private and member functions 
are public. Overload the insert and delete functions. If the insert function passes only the head pointer and the number 
to be inserted, then, insert at the end of the list. If the insert function passes head pointer, number to be inserted, 
and position to insert the element, overload the insert function and insert the number at the specified position. 
Similarly, overload the delete function. If the delete function passes only the head pointer, then, delete the element 
at the end of the list and return the deleted element.  If the delete function passes the head pointer, and position to 
delete the element, overload the delete function. Display function prints all the elements in the list. Maintain proper 
boundary conditions.
This program is done by CS20B1044 Avinash R Changrani */
#include<iostream>
using namespace std;

// A class that is used to represent a node
class node{
    public:
        int data;
        node *next; 
};

// A class that contains all linked list related functions
class linkedList{
    private:
        node *head = NULL;
        // A function that checks whether the linked list is empty or not
        bool isEmpty(node *head){
            return (head==NULL);
        }
    public:
        // A function that creates a new node
        node *newNode(int num){
            node* newnode = new node();
            newnode->data = num;
            newnode->next = NULL;
            return newnode;
        }

        // A function that inserts a node at the end of the linked list
        void insert(int num){
            node *new_node = newNode(num);
            node *ptr = head;
            if (head == NULL){
                head = new_node;
                return;
            }
            while (ptr->next != NULL){
                ptr = ptr->next;
            }
            ptr->next = new_node; 
        }

        // A function that inserts a node in the linked list at a specific position using function overloading
        void insert(int num, int position){
            node *new_node = newNode(num);
            node *ptr = head;
            node *prev = NULL;
            int counter = 1;
            if(isEmpty(head) && position != 1){
                cout<<"Please enter a valid position to insert\n";
                return;
            }
            if (position == 1){
                new_node->next = head;
                head = new_node;
                return;
            }
            for (int i = 1; i < position && ptr != NULL; i++){
                prev = ptr;
                ptr = ptr->next;
                counter++;
                if (ptr == NULL){
                    break;
                }
            }
            if (ptr == NULL && (counter) != position){
                cout<<"Please enter a valid position to insert\n";
                return;
            }
            new_node->next = ptr;
            prev->next = new_node;
            
        }

        // A function that deletes a node at the end of the linked list
        void deleteNode(){
            if(isEmpty(head)){
                cout<<"List is empty!!\n";
                return;
            }
            if(head->next == NULL){
                delete head;
                head = NULL;
                return;
            }
            node *ptr = head;
            while(ptr->next->next != NULL){
                ptr = ptr->next;
            }
            delete(ptr->next);
            ptr->next = NULL;

        }

        // A function that deletes a node in the linked list at a specific position using function overloading
        void deleteNode(int position){
            if (isEmpty(head)){
                cout<<"List is empty!!\n";
                return;
            }
            node *ptr = head;
            if (position == 1){
                head = ptr->next;
                delete ptr;
                return;
            }
            for(int i = 2; ptr != NULL && i < position; i++)
                ptr = ptr->next;    
            if (ptr == NULL || ptr->next == NULL){
                cout<<"Please enter a valid position\n";
                return;
            }
            node *temp = ptr->next->next;   
            delete ptr->next;
            ptr->next = temp;
        }

        // A function to display elements of the linked list
        void display(){
            if (isEmpty(head)){
                cout<<"The Linked List is empty!"<<endl;
            }
            else{
                node *ptr = head;
                while (ptr != NULL){
                    cout << ptr->data;
                    if (ptr->next != NULL){
                        cout << "->";
                    }
                    ptr = ptr->next;
                }
                cout<<"\n";
            }
        }        
};

int main(){
    linkedList L;
    int choice,element,position;
    while(1){
        cout<<"Menu : \n 1)Insert element into the linked list \n 2)Insert element into the linked list at the specified position \n 3)Delete element from the linked list \n 4)Delete element from the linked list at the specified position \n 5)Display elements of the linked list \n 6)Exit";
        cout<<"\nPlease Enter your choice: ";
        cin>>choice;
        switch(choice){
            case 1:
                cout<<"Please enter the element(integer) you want to insert: ";
                cin >> element; 
                L.insert(element);
                break;
            case 2:
                cout<<"Please enter the element(integer) you want to insert: ";
                cin >> element;
                cout<<"Please enter the position where you want to insert the element to: ";
                cin >> position;
                L.insert(element,position);
                break;  
            case 3:
                L.deleteNode();
                break;    
            case 4:
                cout<<"Please enter the position from which you want to delete the node: ";
                cin >> position;
                L.deleteNode(position);
                break;
            case 5:
                L.display();
                break; 
            case 6:
                exit(0);        
            default :
                cout<<"Wrong choice, Please try again!\n";                
        }
    }
    return 0;
}
// This program is done by CS20B1044 Avinash R Changrani
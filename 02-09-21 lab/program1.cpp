/* Write a C++ program using classes to implement a single linked list. The data members are private and member functions are public. Note: No need for a separate header file. Given two sorted lists, merge them so as to produce a combined sorted list (without using extra space). The data members and the member function isEmpty() are private and the other member functions are public. The list stores integer data. Overload the + operator to merge the two sorted linked lists. The merged list also should be in sorted order.
Examples: 
Input : head1: 5->7->9
        head2: 4->6->8 
Output : 4->5->6->7->8->9
Explanation: The output list is in sorted order.
Input : head1: 1->3->5->7
        head2: 2->4
Output : 1->2->3->4->5->7
Explanation: The output list is in sorted order.
The options for the list are
Insert
Display
Merge (Overload + operator to do this task)
Exit
This program is done by CS20B1044 Avinash R Changrani */
#include <iostream>
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
        // A function that inserts a node in a sorted way
        node *insert(node *new_node){
            node *ptr;
            if (head == NULL || ((head->data) >= (new_node->data))){
                new_node->next = head;
                head = new_node;

            }
            else{
                ptr = head;
                while (ptr->next != NULL && ptr->next->data < new_node->data) {
                    ptr = ptr->next;
                }
                new_node->next = ptr->next;
                ptr->next = new_node;
            }
            
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
        // A function to merge one linked list with another using operator overloading
        linkedList operator+(linkedList &l2){
            node *temp;
            node *ptr = l2.head;
            while (ptr != NULL){
                temp = ptr->next;
                l2.head = ptr->next;
                node *new_node = this->newNode(ptr->data);
                this->insert(new_node);
                delete ptr;
                ptr = temp;
            }
            return(*this);
        };
        
};

int main(){
    linkedList L1, L2;
    int choice,list_choice,element,position;
    node *temp;
    while(1){
        cout<<"Menu : \n 1)Insert element into the linked list \n 2)Display elements of the linked lists \n 3)Merge elements of the two linked lists \n 4)Exit";
        cout<<"\nPlease Enter your choice: ";
        cin>>choice;
        switch(choice){
            case 1:
                cout<<"Please enter the element(integer) you want to insert: ";
                cin >> element; 
                cout<<"Please enter which list (1 or 2) you want to insert the node to: ";
                cin >> list_choice;
                switch(list_choice){
                    case 1:
                        temp = L1.newNode(element);
                        L1.insert(temp);
                        break;
                    case 2:
                        temp = L2.newNode(element);
                        L2.insert(temp);
                        break;
                    default:
                        cout<<"Wrong choice, Please try again!"<<endl;
                }
                break;
            case 2:
                cout<<"Please enter which list (1 or 2) you want the program to display: ";
                cin >> list_choice;
                switch(list_choice){
                    case 1:
                        L1.display();
                        break;
                    case 2:
                        L2.display();
                        break;
                    default:
                        cout<<"Wrong choice, Please try again!"<<endl;
                }
                break;  
            case 3:
                L1 = L1 + L2;
                cout<<"The resultant linked list after merging two linked lists is: \n";
                L1.display();
                break;    
            case 4:
                exit(0);      
            default :
                cout<<"Wrong choice, Please try again!\n";                
        }
    }
    return 0;
}
// This program is done by CS20B1044 Avinash R Changrani
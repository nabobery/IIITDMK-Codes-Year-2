/* Given two sorted lists, merge them so as to produce a combined sorted list (without using extra space). The data 
members and the member function isEmpty() are private and the other member functions are public. The list stores integer 
data. Use new and delete keywords to dynamically allocate and deallocate memory whenever needed.
Hint: use objects as function arguments and return type from a function or call an object by reference.
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
Delete
Display
Merge
Exit
When 1. Insert option is selected, request the user at which linked list should you insert the new element in the sorted 
order in the corresponding list.
When 2. Delete option is selected, request the user at which linked list should you delete at what position and delete the 
node present in the corresponding list.
When 3. Display option is selected, request the user which linked list should you display and print the elements in the 
corresponding list.
When 4. Merge option is selected, you can merge the contents of list2 to list1 or create a list 3 and merge the 
contents of list1 and list2 in the sorted order.
When 5. Exit option is selected, stop the program.
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
        // A functio that creates a new node
        node *newNode(int num){
            node* newnode = new node();
            newnode->data = num;
            newnode->next = NULL;
            return newnode;
        }
        // A function that inserts a node in a sorted way
        node *insert(node *new_node){
            node *ptr;
            // If list is empty or head needs to be changed
            if (head == NULL || ((head->data) >= (new_node->data))){
                new_node->next = head;
                head = new_node;

            }
            // traversing the list and adding the node to a place where it's less than the some other node
            else{
                ptr = head;
                while (ptr->next != NULL && ptr->next->data < new_node->data) {
                    ptr = ptr->next;
                }
                new_node->next = ptr->next;
                ptr->next = new_node;
            }
            
        }
        // A function to delete the node from  a given position
        void deleteNode(int position){
            // If list is empty and no nodes to delete 
            if (head == NULL){
                cout<<"List is empty!!\n";
                return;
            }
            node *ptr = head;
            // If the head node of the linked list to be deleted
            if (position == 1){
                head = ptr->next;
                delete ptr;
                return;
            }
            // Traversing the linked list to find the node before the node at the position that is to be deleted
            for(int i = 2; ptr != NULL && i < position; i++)
                ptr = ptr->next;
            // If the position is more than the number of nodes in the linked list    
            if (ptr == NULL || ptr->next == NULL){
                cout<<"Please enter a valid position\n";
                return;
            }
            // We store the pointer to next of the node to be deleted
            node *temp = ptr->next->next;   
            delete ptr->next; // delete the node
            ptr->next = temp; // then link the previous to next of the node deleted
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
        // A function to merge one linked list with another
        void merge(linkedList &l2){
            node *temp;
            node *ptr = l2.head;
            while (ptr != NULL){
                temp = ptr->next;
                node *new_node = this->newNode(ptr->data);
                this->insert(new_node); 
                l2.deleteNode(1);
                ptr = temp;
            }
        }
        
};

int main(){
    linkedList L1, L2;
    int choice,list_choice,element,position;
    node *temp;
    while(1){
        cout<<"Menu : \n 1)Insert element into the linked list \n 2)Delete elements from the linked list \n 3)Display elements of the linked lists \n 4)Merge elements of the two linked lists \n 5)Exit";
        cout<<"\nPlease Enter your choice: ";
        cin>>choice;
        switch(choice){
            // For inserting elements into the linked list
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
            // For deleting the elements from the linked list at a given position  
            case 2:
                cout<<"Please enter which list's (1 or 2) node you want to delete: ";
                cin >> list_choice;
                // position starts from 1
                cout<<"Please enter from which position of the list you want to delete the node from: "; 
                cin >> position;
                switch(list_choice){
                    case 1:
                        L1.deleteNode(position);
                        break;
                    case 2:
                        L2.deleteNode(position);
                        break;
                    default:
                        cout<<"Wrong choice, Please try again!"<<endl;
                }
                break;
            // For displaying content of the linked list
            case 3:
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
            // For merging the two linked lists and printing out the resultant list   
            case 4:
                L1.merge(L2);
                cout<<"The resultant linked list after merging two linked lists is: \n";
                L1.display();
                break;
            // For exiting the while loop    
            case 5:
                exit(0);  
            // For options not in the menu    
            default :
                cout<<"Wrong choice, Please try again!\n";                
        }
    }
    return 0;
}
// This program is done by CS20B1044 Avinash R Changrani
#include <iostream>
using namespace std;

class node{
    public:
        int data;
        node *next;
    /*Node(int num){
        data = num;
        next = NULL;
    }*/   
    /*~node(){
        cout<<"Destructor is called"<<endl;
    }*/ 
};

class linkedList{
    private:
        node *head = NULL;
        bool isEmpty(node *head){
            return (head==NULL);
        }
    public:
        node *newNode(int num){
            node* newnode = new node();
            newnode->data = num;
            newnode->next = NULL;
            return newnode;
        }
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
        void deleteNode(int position){
            // If list is empty and no nodes to delete 
            if (head == NULL){
                cout<<"List is empty \n";
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
            }
        }
        void merge(linkedList &l2){
            node *temp;
            node *ptr = l2.head;
            //cout << this->head->data <<endl;
            //cout << ptr->data <<endl;
            while (ptr != NULL){
                temp = ptr->next;
                node *new_node = this->newNode(ptr->data); // l1
                this->insert(new_node); // l1
                l2.deleteNode(1);
                // delete ptr;
                ptr = temp;
            }
        }
        ~linkedList(){
            cout<<"Destructor is called \n";
            node *ptr = head;
            node *temp;
            while (ptr != NULL){
                temp = ptr->next;
                delete ptr;
                ptr = temp;
            }
        }  
};

int main(){
    linkedList L1, L2;
    int choice,list_choice,element, position;
    node *temp;
    int flag = 1;
    while(flag){
        cout<<"\nMenu : \n 1)Insert element into the linked list \n 2)Delete elements from the linked list \n 3)Display elements of the linked lists \n 4)Merge elements of the two linked lists \n 5)Exit";
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
            case 4:
                L1.merge(L2);
                cout<<"The resultant linked list after merging two linked lists is: \n";
                L1.display();
                break;
            case 5:
                flag = 0;
                break;
                // exit(0);  
            // For options not in the menu    
            default :
                cout<<"Wrong choice, Please try again!\n";                
        }
    }
    return 0;
}
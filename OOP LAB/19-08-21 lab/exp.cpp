#include <iostream>
using namespace std;

class linkedList{
    private:
        int data;
        linkedList *next;
    public:
    linkedList *insert(int num, linkedList *head){
        if (head == NULL){
            head = new linkedList();
            head->data = num;
        }
        
    }
};

int main(){
    int choice;
    while(1){
        cout<<"\nMenu : \n 1)Insert element into the linked list \n 2)Delete elements from the linked list \n 3)Display elements of the linked lists \n 4)Merge elements of the two linked lists \n 5)Exit";
        cout<<"\nPlease Enter your choice: ";
        cin>>choice;
        switch(choice){
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                exit(0);  
            // For options not in the menu    
            default :
                cout<<"Wrong choice, Please try again!";                
        }
    }
    return 0;
}
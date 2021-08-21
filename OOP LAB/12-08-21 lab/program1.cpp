// This program is done by CS20B1044 Avinash R Changrani

// Menu Driven Program for report card
#include "reportcard.hpp"
#include <iostream>
#include <string>
using namespace std;

int main(){
    int choice, rollno;
    string name;
    int marks[5];
    // stu1, stu2, stu3 initialized using default constructor(without parameters)
    reportCard stu1, stu2, stu3;
    // stu4 and stu5 initialized using parameterized constructor
    reportCard stu4("Temp1", 4);
    reportCard stu5("Temp2", 5);
    while(1){
        cout<<"\nMenu : \n 1)Create Student report card record \n 2)Display all students report cards \n 3)Exit";
        cout<<"\nPlease Enter your choice: ";
        cin>>choice;
        switch(choice){
            // For creating students report card record
            case 1 : 
                cout<<"Please enter the name of Student 1 :";
                getline(cin >> ws, name);
                cout<<"Please enter the roll number of Student 1 : ";
                cin >> rollno;
                for (int i = 0; i< 5; i++){
                    cout << "Please enter the Marks of Student 1 in Subject " << i + 1 << ": " ;
                    cin >> marks[i];
                }
                stu1.createCard(name, rollno, marks);
                cout<<"Please enter the name of Student 2 : ";
                getline(cin >> ws, name);
                cout<<"Please enter the roll number of Student 2 : ";
                cin >> rollno;
                for (int i = 0; i< 5; i++){
                    cout << "Please enter the Marks of Student 2 in Subject " << i + 1 << ": " ;
                    cin >> marks[i];
                }
                stu2.createCard(name, rollno, marks);
                cout<<"Please enter the name of Student 3 : ";
                getline(cin >> ws, name);
                cout<<"Please enter the roll number of Student 3 : ";
                cin >> rollno;
                for (int i = 0; i< 5; i++){
                    cout << "Please enter the Marks of Student 3 in Subject " << i + 1 << ": " ;
                    cin >> marks[i];
                }
                stu3.createCard(name, rollno, marks);
                cout<<"Please enter the name of Student 4 : ";
                getline(cin >> ws, name);
                cout<<"Please enter the roll number of Student 4 : ";
                cin >> rollno;
                for (int i = 0; i< 5; i++){
                    cout << "Please enter the Marks of Student 4 in Subject " << i + 1 << ": " ;
                    cin >> marks[i];
                }
                stu4.createCard(name, rollno, marks);
                cout<<"Please enter the name of Student 5 : ";
                getline(cin >> ws, name);
                cout<<"Please enter the roll number of Student 5 : ";
                cin >> rollno;
                for (int i = 0; i< 5; i++){
                    cout << "Please enter the Marks of Student 5 in Subject " << i + 1 << ": " ;
                    cin >> marks[i];
                }
                stu5.createCard(name, rollno, marks);
                break;
            // For displaying students report card report    
            case 2 : 
                stu1.displayCard();
                stu2.displayCard();
                stu3.displayCard();
                stu4.displayCard();
                stu5.displayCard();
                break;
            // For exiting the menu (while loop)    
            case 3 : 
                exit(0);
            // For options not in the menu    
            default :
                cout<<"Wrong choice, Please try again!";         
        }
    }
    return 0;
}

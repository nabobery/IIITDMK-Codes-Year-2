#include <iostream>
#include <string>
using namespace std;
 
int main()
{
    string str;
 
    cout << "Please enter your name: \n";
    getline(cin, str);
    cout << "Hello, " << str
         << " welcome to GfG !\n";
 
    return 0;
}

/*----------------------------------------------------------------
cout<<"\nPlease Enter your choice: ";
        cin>>choice;
        switch(choice){
            case 1 : 
                cout<<"\nPlease enter the name of Student 1 :";
                getline(cin >> ws, name);
                cout<<"Please enter the roll number of Student 1 : ";
                cin >> rollno;
                for (int i = 0; i< 5; i++){
                    cout << "\nPlease enter the Marks of Student 1 in Subject " << i + 1 << ": " ;
                    cin >> marks[i];
                }
                stu1.createCard(name, rollno, marks);

cin.ignore(numeric_limits<streamsize>::max(),'\n');
*/

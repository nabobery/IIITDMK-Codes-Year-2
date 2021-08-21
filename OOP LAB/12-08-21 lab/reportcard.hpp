/* Question : Write a C++ header program(abstraction) to create a Student Report Card System( use classes - encapsulation). Note: 
All the data members are declared private (secure data members) and member functions are defined under public.

a) Create student report card record: This feature creates a new student record containing his marks. For this, the 
information to be provided are the name and roll no. of the student, and the marks obtained by him/her in 5 subjects 
Any five subjects.

b) Display all student’s report card records: The void displayAll() function, in this student report card system project in 
C++ has been used for this feature. It basically shows the progress report of all the students added to the file. This 
feature displays the roll no. and name of all the students, the marks obtained by them in 5 subjects – 5 subject marks 
along with the percentage and grade of each student.

c) Declare a constructor that initializes the data members’ value to 0.

d) Declare a parameterized constructor that takes a name and roll number as parameters and assigns all other marks to 0.

Now, write a C++ Menu driven program to utilize the student report card system. Get details for 5 students. Let the 5 
objects be stu1, stu2, stu3, stu4, and stu5. Let stu1, stu2, and stu3 be initialized by default constructors and stu4 and 
stu5 be initialized by parameterized constructors.  Maintain proper boundary conditions, follow coding best practices, 
declare and define functions following coding practices.
This program is done by CS20B1044 Avinash R Changrani */
// Header file to implement report card
#include <iostream>
using namespace std;

// Class definition for the report card
class reportCard {
    private:
    int roll_no;
    int marks[5];
    string name;
    public:
    // A constructor that initializes the data members value to 0 for 3 students
    reportCard(){
        name = "";
        roll_no = 0;
        for (int i = 0; i < 5; i++) {
            marks[i] = 0;
        }
    }
    // A function for boundary conditions for roll_no
    bool boundaryCondition1(int rollno){
        return (rollno > 0);
    }

    // A fucntion to check the boundary conditions for marks (0 i min and 100 is Max)
    bool boundaryCondition2(int marks[]){
        int flag = 0;
        for (int i = 0; i < 5; i++) {
            if (marks[i] >= 0 && marks[i] <= 100)
                continue;
            else
                flag++;       
        }
        if (flag == 0) 
            return true;
        else
            return false;     
        
    }

    /* A parameterized constructor that takes a name and roll number as parameters and assigns all other 
    marks to 0 for 2 students */
    reportCard(string Name, int Roll_no){
        roll_no = Roll_no;
        name = Name;
        for (int i = 0; i < 5; i++) {
            marks[i] = 0;
        }
    }
    // A function for creating a report card for a student
    void createCard(string Name, int Roll_no, int Marks[]){
        name = Name;
        roll_no = Roll_no;
        for (int i = 0; i < 5; i++) {
            marks[i] = Marks[i];
        }    
    }

    // A function for displaying rport card of a student
    void displayCard(){
        if (boundaryCondition1(roll_no) && boundaryCondition2(marks)){
            cout << "----Report Card----\n";
            cout << "Name of Student : " << name << endl;
            cout << "Roll number of Student : " << roll_no << endl;
            for (int i = 0; i < 5; i++) {
                cout << "Marks of Student in Subject " << i + 1 << " is " << marks[i] << endl;
            }
        }
        else
            cout <<"You've entered some wrong data for the Student "<< name <<".Please try again!\n";    
    }

};





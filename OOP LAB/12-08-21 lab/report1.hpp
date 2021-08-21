/* Question : Write a C++ header program(abstraction) to create a Student Report Card System( use classes - encapsulation). Note: 
All the data members are declared private (secure data members) and member functions are defined under public.

a) Create student report card record: This feature creates a new student record containing his marks. For this, the 
information to be provided are the name and roll no. of the student, and the marks obtained by him/her in 5 subjects 
Any five subjects.

b) Display all student’s report card records: The void displayAll() function, in this student report card system project in 
C++ has been used for this feature. It basically shows the progress report of all the students added to the file. This 
feature displays the roll no. and name of all the students, the marks obtained by them in 5 subjects – 5 subject marks 
along with the percentage and grade of each student.

c) Display specific student’s report card record: This feature is the same as the one explained above, except it shows 
the progress report and relevant data related to a particular student (Name, roll No).

d) Modify student’s report card record: In the student report card system, this feature is used to edit the report card 
record of a particular student. For this, the name and roll no. of the student are sought. Upon successful modification, 
the program displays the message “Record Updated”. If no record of the student is found, it displays the message “Record 
not found”.

e) Delete student record: This feature deletes the report card record of a particular student; Pass a student object and 
change all values to 0 (Name to the empty string ‘\0’).

f) Declare a constructor that initializes the data members’ value to 0.

g) Declare a parameterized constructor that takes a name and roll number as parameters and assigns all other marks to 0.

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
    int marks;
    string name, roll_no;
    public:

    reportCard(string name, string roll_no){
        
    }

};





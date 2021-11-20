/*
9.1 Consider 4 classes person, student, research_student, and TA. ‘person’ is the base class for student and 
research_student classes. TA inherits from student and research_student class. In every base class, all the data members 
have protected access and member functions have public access. All derived classes derive in protected mode. It has a 
parameterized constructor for the initialization of its data members.

The person class has name and roll_number as data members. It has a display member function with no arguments that display 
the name and roll_number of a person. It has a parameterized constructor for the initialization of its data members.

The student class has course1, course2, and course3 data members. The derived roll_number data member is of string datatype. 
It also has a display member function with no arguments that display the name, roll_number, and courses credited by the 
student. It has a parameterized constructor for the initialization of its data members.

The research_student class has course1 and research_area data members.  The derived roll_number data member is of integer 
data type. It also has a display member function with no arguments that display the name, roll_number, course1, and 
research_area by the research student. It has a parameterized constructor for the initialization of its data members.

The TA class has course_assigned and role data members. It also has a display member function with no arguments that 
display the name, roll_number, course_assigned, and role. ‘role’ can be either student or research student. Make sure 
‘role’ should not be interchanged between student and research student. Course_assigned should not be the same as course1, 
course2, and course3 for a student and Course_assigned should not be the same as course1 for a research_student.  It has 
two parameterized constructors for the initialization of data members belonging to student and research_student data 
members respectively.

Identify and use the virtual, and template keywords wherever necessary. A person’s detail is stored in a singly-linked list. 
For simplicity, create list objects for the TA class alone. Maintain proper boundary conditions and follow coding best 
practices.

Write a menu-driven program with the following menus:

Set Person Details
Display 
Person
Student
Research Student
Teaching Assistant
Exit

9.2 Program to implement Bubble Sort using the template in C++ (function template). Write the program with menus.

9.3 Implement stack for int, char using templates in C++ (class template). Write the program with appropriate menus.

*/
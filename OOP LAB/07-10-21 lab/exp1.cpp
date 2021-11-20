#include <iostream>
#include <cstdlib>
using namespace std;

template <class T> class person {
    protected:
        string name;
        //template <typename T> 
        T roll_no;
    public:
        person(){}
        person(string Name, T rollNumber){
            name = Name;
            roll_no = rollNumber;
        }
        void Display(){
            //cout << "\x1B[37m----------Person Details------------\033[0m\n";
            cout<<"Name: "<< name << " Roll Number: "<< roll_no << "\n";
        }

};

/*template <class T> class student : protected virtual person <T> {
    protected:
        string course1, course2, course3;
    public:
        student(string Name, string rollNumber, string course_1, string course_2, string course_3): person(Name, rollNumber){
            // person(Name, rollNumber);
            course1 = course_1;
            course2 = course_2;
            course3 = course_3;
        }
        void Display(){
            cout << "\x1B[31m----------Student Details------------\033[0m\n";
            cout<<"Name: " << name << " Roll Number: " << roll_no << "\n";

        }
};*/

class student : virtual protected person <string> {
    protected:
        string course1, course2, course3;
    public:
        student(){}
        student(string Name, string rollNumber, string course_1, string course_2, string course_3): person<string>(Name, rollNumber){
            course1 = course_1;
            course2 = course_2;
            course3 = course_3;
        }
        void Display(){
            cout << "\x1B[31m----------Student Details------------\033[0m\n";
            cout<<"Name: " << name << " Roll Number: " << roll_no << "\n";
            cout<<"Course1: "<< course1 << " Course2: " << course2 << " Course3: "<< course3<< "\n";
        }

};

/* template<class T> class research_student : protected virtual person <T>{
    protected:

    public:
        research_student(string Name, int rollNumber, string course_1, string research_area): person(Name, rollNumber){

        }
};*/

class research_student : virtual protected person <int>{
    protected:
        string course1, research_area;
    public:
        research_student() {}
        research_student(string Name, int rollNumber, string course_1, string researchArea): person<int>(Name, rollNumber){
            course1 = course_1;
            research_area = researchArea;
        }
        void Display(){
            cout << "\x1B[32m----------Research Student Details------------\033[0m\n";
            cout<<"Name: " << name << " Roll Number: " << roll_no << "\n";
            cout<<"Course1: " << course1 << " Research Area: " << research_area << "\n";
        }
};

class TA : protected student, protected research_student {
    protected:
        string course_assigned, role;
    public:
        TA *next;
        TA() {}
        TA(string Name, string rollNumber, string course_1, string course_2, string course_3, string courseAssigned, string Role) : student(Name, rollNumber, course_1, course_2, course_3), person<string>(Name, rollNumber), person<int>(Name, 0), research_student (Name, 0, course_1,research_area){
            role = Role;
            if(course_assigned != course_1 && course_assigned != course_2 && course_assigned != course_3){
                course_assigned = courseAssigned;
            }
            else {
                course_assigned = " ";
                cout<<"Please try again!! Course Assigned can't be same as the courses the TA is studying \n";
            }
        }
        TA(string Name, int rollNumber, string course_1, string researchArea, string courseAssigned, string Role) : research_student(Name, rollNumber, course_1,researchArea), person<int>(Name, rollNumber), person<string>(Name, " "), student(Name, " ", course_1, " ", " "){
            role = Role;
            if(course_assigned != course_1){
                course_assigned = courseAssigned;
            }
            else {
                course_assigned = " ";
                cout<<"Please try again!! Course Assigned can't be same as the courses the TA is studying \n";
            }
        }
        void Display(){
            char choice;
            cout<<"Menu : \n a)Person \n b)Student  \n c)Research Student \n d)Teaching Assistant";
            cout<<"\nPlease Enter your choice: (lower case only)";
            cin >> choice;
            if (choice == 'a'){
                if(role == "student"){
                    cout << "\x1B[37m----------Person Details------------\033[0m\n";
                    person<string>::Display();
                }
                else if(role == "research student"){
                    cout << "\x1B[37m----------Person Details------------\033[0m\n";
                    person<int>::Display();
                }     
            }
            else if (choice == 'b'){
                student::Display();
            }
            else if (choice == 'c'){
                research_student::Display();
            }
            else if (choice == 'd'){
                cout << "\x1B[34m----------Teaching Assistant Details------------\033[0m\n";
                if(role == "student"){
                    person<string>::Display();
                }
                else if(role == "research student"){
                    person<int>::Display();
                }
                cout<<"Course Assigned: "<< course_assigned << " Role: "<< role <<"\n";
            }
            else {
                cout <<"Wrong choice, Please try again!\n";
            }

        }
        TA* addTA(string Role){
            if (Role == "student"){
                string Name, rollNumber, course_1, course_2, course_3, courseAssigned;
                cout<<"Please enter the name of the TA: ";
                getline(cin >> ws, Name);
                cout<<"Please enter the roll number of the TA: ";
                cin >> rollNumber;
                cout<<"Please enter the name of Course1: ";
                getline(cin >> ws, course_1);
                cout<<"Please enter the name of Course2: ";
                getline(cin >> ws, course_2);
                cout<<"Please enter the name of Course3: ";
                getline(cin >> ws, course_3);
                cout<<"Please enter the name of the Course Assigned to the TA: ";
                getline(cin >> ws, courseAssigned);
                *this = TA(Name, rollNumber, course_1, course_2, course_3, courseAssigned, Role);
                return this;
            }
            else if(Role == "research student"){
                int rollNumber;
                string Name, course_1, research_area, courseAssigned, researchArea;
                cout<<"Please enter the name of the TA: ";
                getline(cin >> ws, Name);
                cout<<"Please enter the roll number of the TA: ";
                cin >> rollNumber;
                cout<<"Please enter the name of Course1: ";
                getline(cin >> ws, course_1);
                cout<<"Please enter the Research Area of the TA: ";
                cin >> researchArea;
                cout<<"Please enter the name of the Course Assigned to the TA: ";
                getline(cin >> ws, courseAssigned);
                *this = TA(Name, rollNumber, course_1, researchArea, courseAssigned, Role);
                return this;
            }
            else {
                cout <<"Wrong choice, Please try again!\n";
            } 
        }
        TA* getDetails(TA *head, string Name){
            TA* ptr = new TA();
            if(head == NULL){
                cout << "List of Teaching assistants is Empty! Please try again" << endl;
                return NULL;
            }
            else {
                ptr = head;
                while(ptr != NULL){
                    if(ptr->person<string>::name == Name){
                        return ptr;
                    }
                    else if(ptr->person<string>::name != Name && ptr->next == NULL){
                        cout<<"No such Name of a Teaching Assistant exists! Please try again"<< endl;
                        return NULL;
                    }
                    ptr = ptr->next;
                }
            }

        }
};

int main(){
    int choice;
    TA *ta_head = NULL;
    TA temp1;
    string role, name;
    while(1){
        cout<<"Menu : \n 1)Set TA Details \n 2)Display  \n 3)Exit";
        cout<<"\nPlease Enter your choice: ";
        cin>>choice;
        if (choice == 1){
            cout << "Please enter the role of the TA: (student or research student)  (lowercase only):";
            getline(cin >> ws, role);
            TA *temp = new TA();
            if(ta_head == NULL){
                temp->addTA(role);
                temp->next = NULL;
                ta_head = temp;
                ta_head->next = NULL;
            }
            else {
                TA *ptr = ta_head;
                while(ptr->next != NULL){
                    ptr = ptr->next;
                }
                temp->addTA(role);
                temp->next = NULL;
                ptr->next = temp;
            }
        }
        else if (choice == 2){
            cout<<"Please enter the name of the TA you wish to display details: ";
            getline(cin >> ws, name);
            if(temp1.getDetails(ta_head, name) != NULL){
                TA *temp = temp1.getDetails(ta_head, name);
                temp->Display();
            }
            else{
                cout<<"Please enter a valid Name (for the TA)!!\n";
            }
        }
        else if (choice == 3){
            exit(0);
        }
        else {
            cout <<"Wrong choice, Please try again!\n";
        }
    }
    return 0;
}
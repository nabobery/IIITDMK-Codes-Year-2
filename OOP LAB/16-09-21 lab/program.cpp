// This program is done by CS20B1044 Avinash R Changrani

#include <iostream>
#include <string>
using namespace std;

class Employee {
    protected:
        int employee_id;
        string employee_name;
};

class Contract : protected Employee {
    protected:
        double pay_per_hour;
    public:
        void setPay(double pay){
            if(pay >= 0.0){
                pay_per_hour = pay;
            }
            else {
                cout << "Please enter valid pay!! Hourly Pay has been set to 0\n";
                pay_per_hour = 0.0;
            }
        }
        double getPay(){
            return pay_per_hour;
        }

};

class Salaried : protected Employee {
    protected:
        double monthlyPay;
    public:
        void setPay(double pay){
            if(pay >= 0.0){
                monthlyPay = pay;
            }
            else {
                cout << "Please enter valid pay!! Monthly Pay has been set to 0\n";
                monthlyPay = 0.0;
            }
        }
        double getPay(){
            return monthlyPay;
        } 
};

class Manager : private Salaried {
    public:
        void setDetails(int Id , string Name, double pay){
            employee_id = Id;
            employee_name = Name;
            if(pay >= 0.0){
                monthlyPay = pay;
            }
            else {
                cout << "Please enter valid pay!! Monthly Pay has been set to 0\n";
                monthlyPay = 0.0;
            }
        }
        void getDetails(){
            cout<<"Position: Manager"<<" EmployeeID: "<<employee_id<<" Name: "<<employee_name<<" Salary(Monthly Pay): "<<monthlyPay<<"\n";
        }
        void calculateSalary(){
            int months;
            cout<<"Please the the number of months the Manager has worked for: ";
            cin >> months;
            cout<<"The Total Salary of the Manager is "<<(monthlyPay * months)<<"\n";
        }
        void setSalary(double pay){
            monthlyPay = pay;
        }
        int getEmployeeid(){
            return employee_id;
        }
        double getPay(){
            return monthlyPay;
        }
        string getEmployeename(){
            return employee_name;
        }

};

class Intern : private Contract {
    public:
        void setDetails(int Id , string Name, double pay){
            employee_id = Id;
            employee_name = Name;
            if(pay >= 0.0){
                pay_per_hour = pay;
            }
            else {
                cout << "Please enter valid pay!! Hourly Pay has been set to 0\n";
                pay_per_hour = 0.0;
            }
        }
        void getDetails(){
            cout<<"Position: Intern"<<" EmployeeID: "<<employee_id<<" Name: "<<employee_name<<" Salary(Hourly Pay): "<<pay_per_hour << "\n";
        }
        double calculateSalary(){
            int hours;
            cout<<"Please the the number of hours the Intern has worked for: ";
            cin >> hours;
            cout<<"The Total Salary of the Intern is "<<(pay_per_hour * hours)<<"\n";
        }
        void setSalary(double pay){
            pay_per_hour = pay;
        }
        int getEmployeeid(){
            return employee_id;
        }
        double getPay(){
            return pay_per_hour;
        }
        string getEmployeename(){
            return employee_name;
        }
};

int main(){
    int choice, size1, size2, option, preference, position, counter1 = 0, counter2 = 0;
    cout<<"Please enter the maximum number of Records you wish to create for Manager Position: ";
    cin >> size1;
    cout<<"Please enter the maximum number of Records you wish to create for Intern Position: ";
    cin >> size2;
    Manager manager_arr[size1];
    Intern intern_arr[size2];
    int id;
    double pay;
    string name;
    while(1){
        cout<<"Menu : \n 1)Create Employee Record (Manager or Intern) \n 2)Update Employee Details (Manager or Intern) \n 3)Print Employee Details (Manager or Intern) \n 4)Update Pay (Manager or Intern) \n 5)Calculate Salary (Manager or Intern) \n 6)Exit";
        cout<<"\nPlease Enter your choice: ";
        cin>>choice;
        switch(choice){
            case 1: 
                cout<<"Please Enter 1 for Manager and 2 for Intern: ";
                cin >> option;
                if(option == 1){
                    if(counter1 <  size1){
                        cout<<"Please Enter the name of the Manager: ";
                        getline(cin >> ws, name);
                        cout<<"Please Enter the Employee ID of the Manager: ";
                        cin >> id;
                        cout<<"Please Enter the Monthly Pay of the Manager: ";
                        cin >> pay;
                        manager_arr[counter1].setDetails(id, name, pay);
                        counter1++;
                    }
                    else {
                        cout<<"The records for the Manager Position is completely filled as it has reached it's maximum size \n";
                    }
                    
                }
                else if(option == 2){
                    if(counter2 < size2){
                        cout<<"Please Enter the name of the Intern: ";
                        getline(cin >> ws, name);
                        cout<<"Please Enter the Employee ID of the Intern: ";
                        cin >> id;
                        cout<<"Please Enter the Hourly Pay of the Intern: ";
                        cin >> pay;
                        intern_arr[counter2].setDetails(id, name, pay);
                        counter2++;
                    }
                    else {
                        cout<<"The records for the Intern Position is completely filled as it has reached it's maximum size \n";
                    }   
                }
                else{
                    cout<<"Wrong choice, Please try again!\n";
                }
                break;
            case 2: 
                cout<<"Please Enter 1 for Manager and 2 for Intern: ";
                cin >> option;
                if(option == 1){
                    cout<<"Please Enter the Employee ID of the Manager: ";
                    cin >> id;
                    position = -1;
                    for(int i = 0; i < counter1; i++){
                        if(manager_arr[i].getEmployeeid() == id){
                            position = i;
                            break;
                        }
                    }
                    if(position != -1){
                        cout<<"Please enter 1 for changing ID of Manager, 2 for changing name of Manager and 3 for changing Salary of Manager: ";
                        cin >> preference;
                        if(preference == 1){
                            cout<<"Please Enter the Updated Employee ID of the Manager: ";
                            cin >> id;
                            name = manager_arr[position].getEmployeename();
                            pay = manager_arr[position].getPay();
                            manager_arr[position].setDetails(id, name, pay);
                        }
                        else if(preference == 2){
                            cout<<"Please Enter the Updated name of the Manager: ";
                            getline(cin >> ws, name);
                            id = manager_arr[position].getEmployeeid();
                            pay = manager_arr[position].getPay();
                            manager_arr[position].setDetails(id, name, pay);
                        }
                        else if(preference == 3){
                            cout<<"Please Enter the updated salary of the Manager: ";
                            cin >> pay;
                            manager_arr[position].setSalary(pay);
                        }
                        else{
                            cout<<"Wrong choice, Please try again!\n";
                        }
                    }
                    else {
                        cout<<"Employee ID not found in the records. Please try again! \n";
                    }
                }
                else if(option == 2){
                    cout<<"Please Enter the Employee ID of the Intern: ";
                    cin >> id;
                    position = -1;
                    for(int i = 0; i < counter2; i++){
                        if(intern_arr[i].getEmployeeid() == id){
                            position = i;
                            break;
                        }
                    }
                    if(position != -1){
                        cout<<"Please enter 1 for changing ID of Intern, 2 for changing name of Intern and 3 for changing Salary of Intern: ";
                        cin >> preference;
                        if(preference == 1){
                            cout<<"Please Enter the Updated Employee ID of the Intern: ";
                            cin >> id;
                            name = intern_arr[position].getEmployeename();
                            pay = intern_arr[position].getPay();
                            intern_arr[position].setDetails(id, name, pay);
                        }
                        else if(preference == 2){
                            cout<<"Please Enter the Updated name of the Intern: ";
                            getline(cin >> ws, name);
                            id = intern_arr[position].getEmployeeid();
                            pay = intern_arr[position].getPay();
                            intern_arr[position].setDetails(id, name, pay);
                        }
                        else if(preference == 3){
                            cout<<"Please Enter the updated Hourly Pay of the Intern: ";
                            cin >> pay;
                            intern_arr[position].setSalary(pay);
                        }
                        else{
                            cout<<"Wrong choice, Please try again!\n";
                        }
                    }
                    else {
                        cout<<"Employee ID not found in the records. Please try again! \n";
                    }    
                }
                else{
                    cout<<"Wrong choice, Please try again!\n";
                }
                break;
            case 3: 
                cout<<"Please Enter 1 for Manager and 2 for Intern: ";
                cin >> option;
                if(option == 1){
                    cout<<"Please Enter the Employee ID of the Manager: ";
                    cin >> id;
                    position = -1;
                    for(int i = 0; i < counter1; i++){
                        if(manager_arr[i].getEmployeeid() == id){
                            position = i;
                            break;
                        }
                    }
                    if(position != -1){
                        manager_arr[position].getDetails();
                    }
                    else {
                        cout<<"Employee ID not found in the records. Please try again! \n";
                    }
                }
                else if(option == 2){
                    cout<<"Please Enter the Employee ID of the Intern: ";
                    cin >> id;
                    position = -1;
                    for(int i = 0; i < counter2; i++){
                        if(intern_arr[i].getEmployeeid() == id){
                            position = i;
                            break;
                        }
                    }
                    if(position != -1){
                        intern_arr[position].getDetails();
                    }
                    else {
                        cout<<"Employee ID not found in the records. Please try again! \n";
                    }
                }
                else{
                    cout<<"Wrong choice, Please try again!\n";
                }
                break;
            case 4: 
                cout<<"Please Enter 1 for Manager and 2 for Intern: ";
                cin >> option;
                if(option == 1){
                    cout<<"Please Enter the Employee ID of the Manager: ";
                    cin >> id;
                    position = -1;
                    for(int i = 0; i < counter1; i++){
                        if(manager_arr[i].getEmployeeid() == id){
                            position = i;
                            break;
                        }
                    }
                    if(position != -1){
                        cout<<"Please Enter the updated salary of the Manager: ";
                        cin >> pay;
                        manager_arr[position].setSalary(pay);
                    }
                    else {
                        cout<<"Employee ID not found in the records. Please try again! \n";
                    }
                }
                else if(option == 2){
                    cout<<"Please Enter the Employee ID of the Intern: ";
                    cin >> id;
                    position = -1;
                    for(int i = 0; i < counter2; i++){
                        if(intern_arr[i].getEmployeeid() == id){
                            position = i;
                            break;
                        }
                    }
                    if(position != -1){
                        cout<<"Please Enter the updated salary of the Intern: ";
                        cin >> pay;
                        intern_arr[position].setSalary(pay);
                    }
                    else {
                        cout<<"Employee ID not found in the records. Please try again!";
                    }
                }
                else{
                    cout<<"Wrong choice, Please try again!\n";
                }
                break;
            case 5: 
                cout<<"Please Enter 1 for Manager and 2 for Intern: ";
                cin >> option;
                if(option == 1){
                    cout<<"Please Enter the Employee ID of the Manager: ";
                    cin >> id;
                    position = -1;
                    for(int i = 0; i < counter1; i++){
                        if(manager_arr[i].getEmployeeid() == id){
                            position = i;
                            break;
                        }
                    }
                    if(position != -1){
                        manager_arr[position].calculateSalary();
                    }
                    else {
                        cout<<"Employee ID not found in the records. Please try again! \n";
                    }
                }
                else if(option == 2){
                    cout<<"Please Enter the Employee ID of the Intern: ";
                    cin >> id;
                    position = -1;
                    for(int i = 0; i < counter2; i++){
                        if(intern_arr[i].getEmployeeid() == id){
                            position = i;
                            break;
                        }
                    }
                    if(position != -1){
                        intern_arr[position].calculateSalary();
                    }
                    else {
                        cout<<"Employee ID not found in the records. Please try again! \n";
                    }
                }
                else{
                    cout<<"Wrong choice, Please try again!\n";
                }
                break;                
            case 6:
                exit(0);      
            default :
                cout<<"Wrong choice, Please try again!\n";
        }
    }
    return 0;
}
// CS20B1044 Avinash R Changrani
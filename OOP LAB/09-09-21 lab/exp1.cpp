/* Create an inheritance hierarchy that a bank might use to represent customers' bank accounts. All customers at this 
bank can deposit (i.e., credit) money into their accounts and withdraw (i.e., debit) money from their accounts. More 
specific types of accounts also exist. Savings accounts, for instance, earn interest on the money they hold. 
Checking accounts, on the other hand, charge a fee per transaction (i.e., credit or debit). Create an inheritance 
hierarchy containing base class Account and derived classes SavingsAccount and CheckingAccount that inherit from class 
Account. Base class Account should include one data member of type double to represent the account balance and one data 
member of type int that represents the account number. The account number should be unique and must be provided by the user. 
The class should provide a constructor that receives an initial balance and uses it to initialize the data member. The 
constructor should validate the initial balance to ensure that it’s greater than or equal to 0.0. If not, the balance 
should be set to 0.0 and the constructor should display an error message, indicating that the initial balance was invalid. 
The class should have necessary member functions. Member function credit should add an amount to the current balance. 
Member function debit should withdraw money from the Account and ensure that the debit amount does not exceed the Account’s 
balance. If it does, the balance should be left unchanged and the function should print the message "Debit amount exceeded 
account balance." Member function getBalance should return the current balance. Member function creates an account number 
and it should be a unique account number for each user. 

Derived class SavingsAccount should inherit the functionality of an Account, but also include a data member of type double 
indicating the interest rate (percentage) assigned to the Account. SavingsAccount ’s constructor should receive the initial 
balance, as well as an initial value for the SavingsAccount ’s interest rate. SavingsAccount should provide a public member 
function calculateInterest that returns a double indicating the amount of interest earned by an account. Member function 
calculateInterest should determine this amount by multiplying the interest rate by the account balance. 
[Note: SavingsAccount should inherit member functions credit and debit as is without redefining them.]

Derived class CheckingAccount should inherit from base class Account and include an additional data member of type double 
that represents the fee charged per transaction. CheckingAccount’s constructor should receive the initial balance, as 
well as a parameter indicating a fee amount. Class CheckingAccount should redefine member functions credit and debit so 
that they subtract the fee from the account balance whenever either transaction is performed successfully. CheckingAccount 
’s versions of these functions should invoke the base-class Account version to perform the updates to an account balance. 
CheckingAccount ’s debit function should charge a fee only if money is actually withdrawn (i.e., the debit amount does 
not exceed the account balance). [Hint: Define Account’s debit function so that it returns a bool indicating whether money 
was withdrawn. Then use the return value to determine whether a fee should be charged.] 

The data about the customers are stored in a separate singly linked list for SavingsAccount and CheckingAccount fashion. 
Use public inheritance for both derived classes. Maintain proper boundary conditions.

After defining the classes in this hierarchy, write a menu-driven program with the following options, 

1. Open Account (Savings or Checking Account)
2. Credit (Savings or Checking Account)
3. Debit (Savings or Checking Account)
4. Change/Update Interest rate (Savings Account)
5. Calculate Interest (Savings Account - Print)
6. Calculate and Update Interest (Savings Account - Credit)
7. Change/Update Fee Amount (Checking Account)
8. Print Checking Fee (Checking Account)
9. Transact and Update (Checking Account - Debit)
10. Exit
*/

#include<iostream>
using namespace std;

class Account{
    public:
        int account_no;
        double balance;
        Account(){
            account_no = 0;
            balance = 0;
        }
        Account (int accountNumber, double bal){
            account_no = accountNumber;
            if(bal >= 0.0){
                balance = bal;
            }
            else {
                cout << "Please enter a valid Account Balance!! Balance of current account has been set to 0 \n";
                balance = 0.0;
            }
        }
        void creditAmount(double amount){
            if(amount >= 0.0){
                balance += amount;
                cout<<"The Balance in the account after crediting " << amount << " is " << balance << endl;
            }
            else {
                cout << "Please enter a valid amount to credit(Non-negative) to the account\n";
            }
        }
        bool debitAmount(double amount){
            if(balance - amount >= 0.0){
                balance -= amount;
                cout<<"The Balance in the account after debiting " << amount << " is " << balance << endl;
                return true;
            }
            else {
                cout << "Debit amount exceeded account balance. Please enter valid amount to debit\n";
                return false;
            }
        }
        double getBalance(){
            return balance;
        }
};

class savingsAccount : public Account {
    public:
        double interest_rate;
        savingsAccount *next;
        savingsAccount(): Account(){
            interest_rate = 0;
        }
        savingsAccount(int accountnumber, double bal, double interestRate): Account (accountnumber,bal){
            if(interestRate >= 0.0){
                interest_rate = interestRate;
            }
            else {
                cout << "Please enter a valid Interest rate!! Interest rate has been set to 0\n";
                interest_rate = 0.0;
            }
        }
        /*savingsAccount(int accountnumber, double bal, double interestRate){
            account_no = accountnumber;
            if(bal >= 0.0){
                balance = bal;
            }
            else {
                cout << "Please enter a valid Account Balance!! \n";
                balance = 0.0;
            }
            if(interestRate >= 0.0){
                interest_rate = interestRate;
            }
            else {
                cout << "Please enter a valid Interest rate!!\n";
                interest_rate = 0.0;
            }
        }*/
        double calculateInterest(){
            return((interest_rate * balance)/100);
        }
        void setInterest(double interestRate){
            if(interestRate >= 0.0){
                interest_rate = interestRate;
            }
            else {
                cout << "Please enter a valid Interest rate!! Interest rate has been set to 0\n";
                interest_rate = 0.0;
            }
        }
        void addAccount(savingsAccount *head, int accountnumber, double bal, double interestRate){
            savingsAccount* ptr = new savingsAccount();
            savingsAccount obj(accountnumber, bal, interestRate);
            if(head == NULL){
                head = &obj;
                head->next = NULL;
                return;
            }
            else {
                ptr = head;
                while(ptr->next != NULL){
                    ptr = ptr->next;
                }
                ptr->next = &obj;
                ptr->next->next = NULL;
                return;
            }
        }
        savingsAccount* getAccount(savingsAccount *head, int account_no){
            savingsAccount* ptr = new savingsAccount();
            if(head == NULL){
                cout << "List of Accounts is Empty! Please try again" << endl;
                return NULL;
            }
            else {
                ptr = head;
                while(ptr != NULL){
                    if(ptr->account_no == account_no){
                        return ptr;
                    }
                    else if(ptr->account_no != account_no && ptr->next == NULL){
                        cout<<"No such account number exists! Please try again"<< endl;
                        return NULL;
                    }
                    ptr = ptr->next;
                }
            }

        }
            
};

class checkingAccount : public Account {
    public:
        double fee;
        checkingAccount *next;
        checkingAccount(): Account(){
            fee = 0;
        }
        checkingAccount (int accountnumber, double bal, double Fee): Account (accountnumber,bal){
            if(Fee >= 0.0){
                fee = Fee;
            }
            else {
                cout << "Please enter a valid fee amount!! Transaction fee has been set to 0\n";
                fee = 0.0;
            }
        }
        void setFee(double Fee){
            if(Fee >= 0.0){
                fee = Fee;
            }
            else {
                cout << "Please enter a valid fee amount!! Transaction fee has been set to 0\n";
                fee = 0.0;
            }
        }
        double getFee(){
            return fee;
        }
        void creditAmount(double amount){
            Account::creditAmount(amount);
            Account::debitAmount(fee);
        }
        void debitAmount(double amount){
            if(Account::debitAmount(amount)){
                Account::debitAmount(fee);
            }
        }
        void addAccount(checkingAccount *head, int accountnumber, double bal, double Fee){
            checkingAccount* ptr = new checkingAccount();
            checkingAccount obj(accountnumber, bal, Fee);
            if(head == NULL){
                head = &obj;
                head->next = NULL;
                return;
            }
            else {
                ptr = head;
                while(ptr->next != NULL){
                    ptr = ptr->next;
                }
                ptr->next = &obj;
                ptr->next->next = NULL;
                return;
            }
        }
        checkingAccount* getAccount(checkingAccount *head, int account_no){
            checkingAccount* ptr = new checkingAccount();
            if(head == NULL){
                cout << "List of Accounts is Empty! Please try again" << endl;
                return NULL;
            }
            else {
                ptr = head;
                while(ptr != NULL){
                    if(ptr->account_no == account_no){
                        return ptr;
                    }
                    else if(ptr->account_no != account_no && ptr->next == NULL){
                        cout<<"No such account number exists! Please try again"<< endl;
                        return NULL;
                    }
                    ptr = ptr->next;
                }
            }

        }

};

int main(){
    int choice, account_choice, account_no;
    double balance, amount, interest_rate, fee, interest_amount;
    savingsAccount *savings_head = NULL;
    checkingAccount *checking_head = NULL;
    savingsAccount temp1;
    checkingAccount temp2;
    while(1){
        cout<<"Menu : \n 1)Open Account \n 2)Credit to an account \n 3)Debit to an account \n 4)Change/Update Interest rate \n 5)Calculate Interest \n 6)Calculate and Update Interest \n 7)Change/Update Fee Amount \n 8)Print Checking Fee \n 9)Transact and Update  \n 10)Exit";
        cout<<"\nPlease Enter your choice: ";
        cin>>choice;
        switch(choice){
            case 1:
                cout<<"Please enter which account you wish to Open (1 for Savings and 2 for Checking):";
                cin >> account_choice;
                switch(account_choice){
                    case 1:
                        cout<<"Please enter the account number of the Savings Account: ";
                        cin >> account_no;
                        cout<<"Please enter the Balance of the Savings Account: ";
                        cin >> balance;
                        cout<<"Please enter the interest rate of the Savings Account(in percentage): ";
                        cin >> interest_rate;
                        temp1.addAccount(savings_head, account_no, balance, interest_rate);
                        break;
                    case 2:
                        cout<<"Please enter the account number of the Checking Account: ";
                        cin >> account_no;
                        cout<<"Please enter the Balance of the Checking Account: ";
                        cin >> balance;
                        cout<<"Please enter the transaction fee of the Checking Account: ";
                        cin >> fee;
                        temp2.addAccount(checking_head, account_no, balance, fee);
                        break;
                    default:
                        cout<<"Wrong choice, Please try again!"<<endl;
                }
                break;
            case 2:  
                cout<<"Please enter which account you wish to credit the amount to (1 for Savings and 2 for Checking):";
                cin >> account_choice;
                switch(account_choice){
                    case 1:
                        cout<<"Please enter the account number of the account you wish to credit to: ";
                        cin >> account_no;
                        if(temp1.getAccount(savings_head, account_no) != NULL){
                            savingsAccount *temp = temp1.getAccount(savings_head, account_no);
                            temp1 = *temp;
                            cout <<"Please enter the amount you wish to credit: ";
                            cin >> amount;
                            temp1.creditAmount(amount);
                        }
                        else {
                            cout<<"Please enter a valid account number to credit the amount \n";
                        } 
                        break;
                    case 2:
                        cout<<"Please enter the account number of the account you wish to credit to: ";
                        cin >> account_no;
                        if(temp2.getAccount(checking_head, account_no) != NULL){
                            checkingAccount *temp = temp2.getAccount(checking_head, account_no);
                            temp2 = *temp;
                            cout <<"Please enter the amount you wish to credit: ";
                            cin >> amount;
                            temp2.creditAmount(amount);
                        }
                        else {
                            cout<<"Please enter a valid account number to credit the amount \n";
                        } 
                        break;
                    default:
                        cout<<"Wrong choice, Please try again!"<<endl;
                }      
                break;  
            case 3:   
                cout<<"Please enter which account you wish to debit the amount to (1 for Savings and 2 for Checking):";
                cin >> account_choice;
                switch(account_choice){
                    case 1:
                        cout<<"Please enter the account number of the account you wish to debit to: ";
                        cin >> account_no;
                        if(temp1.getAccount(savings_head, account_no) != NULL){
                            savingsAccount *temp = temp1.getAccount(savings_head, account_no);
                            temp1 = *temp;
                            cout <<"Please enter the amount you wish to debit: ";
                            cin >> amount;
                            temp1.debitAmount(amount);
                        }
                        else {
                            cout<<"Please enter a valid account number to debit the amount \n";
                        } 
                        break;
                    case 2:
                        cout<<"Please enter the account number of the account you wish to debit to: ";
                        cin >> account_no;
                        if(temp2.getAccount(checking_head, account_no) != NULL){
                            checkingAccount *temp = temp2.getAccount(checking_head, account_no);
                            temp2 = *temp;
                            cout <<"Please enter the amount you wish to debit: ";
                            cin >> amount;
                            temp2.debitAmount(amount);
                        }
                        else {
                            cout<<"Please enter a valid account number to debit the amount \n";
                        }
                        break;
                    default:
                        cout<<"Wrong choice, Please try again!"<<endl;
                }         
                break;
            case 4:
                cout<<"Please enter the account number of the Savings account you wish to update interest rate of: ";
                cin >> account_no;
                if(temp1.getAccount(savings_head, account_no) != NULL){
                    savingsAccount *temp = temp1.getAccount(savings_head, account_no);
                    temp1 = *temp;
                    cout <<"Please enter the new Interest Rate for Updating: ";
                    cin >> interest_rate;
                    temp1.setInterest(interest_rate);
                }
                else {
                    cout<<"Please enter a valid account number to Update the Interest Rate \n";
                }
                break;
            case 5:
                cout<<"Please enter the account number of the Savings account you wish to calculate interest rate of: ";
                cin >> account_no;
                if(temp1.getAccount(savings_head, account_no) != NULL){
                    savingsAccount *temp = temp1.getAccount(savings_head, account_no);
                    temp1 = *temp;
                    interest_amount = temp1.calculateInterest();
                    cout<<"The interest calculated for the account "<<account_no<<" is "<<interest_amount<< endl;
                }
                else {
                    cout<<"Please enter a valid account number to Calculate Interest \n";
                }
                break;
            case 6:
                cout<<"Please enter the account number of the Savings account you wish to calculate and update interest rate of: ";
                cin >> account_no;
                if(temp1.getAccount(savings_head, account_no) != NULL){
                    savingsAccount *temp = temp1.getAccount(savings_head, account_no);
                    temp1 = *temp;
                    interest_amount = temp1.calculateInterest();
                    temp1.creditAmount(interest_amount);
                }
                else {
                    cout<<"Please enter a valid account number to Calculate and Update Interest \n";
                }
                break;
            case 7:
                cout<<"Please enter the account number of the Checking account you wish to update transaction fee of: ";
                cin >> account_no;
                if(temp2.getAccount(checking_head, account_no) != NULL){
                    checkingAccount *temp = temp2.getAccount(checking_head, account_no);
                    temp2 = *temp;
                    cout <<"Please enter the new Transaction fee for Updating: ";
                    cin >> fee;
                    temp2.setFee(fee);
                }
                else {
                    cout<<"Please enter a valid account number to Update the Transaction fee \n";
                }
                break;
            case 8:
                cout<<"Please enter the account number of the Checking account you wish to know the transaction fee of: ";
                cin >> account_no;
                if(temp2.getAccount(checking_head, account_no) != NULL){
                    checkingAccount *temp = temp2.getAccount(checking_head, account_no);
                    temp2 = *temp;
                    fee = temp2.getFee();
                    cout<<"The transaction fee of the current Checking Account is " <<fee <<endl;
                }
                else {
                    cout<<"Please enter a valid account number to know the Transaction fee \n";
                }
                break;              
            case 9:
                cout<<"Please enter the account number of the account you wish to debit to: ";
                cin >> account_no;
                if(temp2.getAccount(checking_head, account_no) != NULL){
                    checkingAccount *temp = temp2.getAccount(checking_head, account_no);
                    temp2 = *temp;
                    cout <<"Please enter the amount you wish to debit: ";
                    cin >> amount;
                    temp2.debitAmount(amount);
                }
                else {
                    cout<<"Please enter a valid account number to debit the amount \n";
                }    
                break;
            case 10:
                exit(0);      
            default :
                cout<<"Wrong choice, Please try again!\n";                
        }
    }
    return 0;
}
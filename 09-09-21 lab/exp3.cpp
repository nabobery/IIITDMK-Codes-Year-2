#include<iostream>
using namespace std;

class Account{
    public:
        int account_no;
        double balance;
        Account(){}
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
        savingsAccount(): Account(){}
        savingsAccount(int accountnumber, double bal, double interestRate): Account (accountnumber,bal){
            if(interestRate >= 0.0 && interestRate <= 100){
                interest_rate = interestRate;
            }
            else {
                cout << "Please enter a valid Interest rate!! Interest rate has been set to 0\n";
                interest_rate = 0.0;
            }
        }
        double calculateInterest(){
            return((interest_rate * balance)/100);
        }
        void setInterest(double interestRate){
            if(interestRate >= 0.0 && interestRate <= 100){
                interest_rate = interestRate;
            }
            else {
                cout << "Please enter a valid Interest rate!! Interest rate has been set to 0\n";
                interest_rate = 0.0;
            }
        }
        savingsAccount* addAccount(){
            /*int account_number;
            double bal, interestRate;
            cout<<"Please enter the account number of the Savings Account: ";
            cin >> account_number;
            cout<<"Please enter the Balance of the Savings Account: ";
            cin >> bal;
            cout<<"Please enter the interest rate of the Savings Account(in percentage): ";
            cin >> interestRate;
            savingsAccount obj = savingsAccount(account_number, bal, interestRate);
            savingsAccount *temp = &obj;
            return temp;*/
            cout<<"Please enter the account number of the Savings Account: ";
            cin >> this->account_no;
            cout<<"Please enter the Balance of the Savings Account: ";
            cin >> this->balance;
            cout<<"Please enter the interest rate of the Savings Account(in percentage): ";
            cin >> this->interest_rate;
            return this;
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
                    cout<<ptr->account_no <<endl;
                    cout<<ptr->balance <<endl;
                    cout<<ptr->interest_rate <<endl;
                    ptr = ptr->next;
                }
            }

        }
            
};

class checkingAccount : public Account {
    public:
        double fee;
        checkingAccount *next;
        checkingAccount(): Account(){}
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
                        cout<<"A \n";
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
                if(account_choice == 1){
                    /*cout<<"Please enter the account number of the Savings Account: ";
                    cin >> account_no;
                    cout<<"Please enter the Balance of the Savings Account: ";
                    cin >> balance;
                    cout<<"Please enter the interest rate of the Savings Account(in percentage): ";
                    cin >> interest_rate;
                    savingsAccount obj = savingsAccount(account_no, balance, interest_rate);
                    savingsAccount *temp = &obj;*/
                    savingsAccount *temp = new savingsAccount;
                    if(savings_head == NULL){
                        temp->addAccount();
                        temp->next = NULL;
                        savings_head = temp;
                        cout<<savings_head->account_no <<endl;
                        cout<<savings_head->balance <<endl;
                        cout<<savings_head->interest_rate <<endl;
                        savings_head->next = NULL;
                        //cout<<"A \n";
                        break;
                    }
                    else {
                        savingsAccount* ptr = savings_head;
                        while(ptr->next != NULL){
                            cout<<ptr->account_no <<endl;
                            cout<<ptr->balance <<endl;
                            cout<<ptr->interest_rate <<endl;
                            ptr = ptr->next;
                        }
                        temp->addAccount();
                        temp->next = NULL;
                        ptr->next = temp;
                        //cout<<"A \n";
                        break;
                    }
                }
                else if(account_choice == 2){
                    cout<<"Please enter the account number of the Checking Account: ";
                    cin >> account_no;
                    cout<<"Please enter the Balance of the Checking Account: ";
                    cin >> balance;
                    cout<<"Please enter the transaction fee of the Checking Account: ";
                    cin >> fee;
                    checkingAccount* p = new checkingAccount();
                    checkingAccount object = checkingAccount(account_no, balance, fee);
                    if(checking_head == NULL){
                        checking_head = &object;
                        checking_head->next = NULL;
                        cout<<"A \n";
                        break;
                    }
                    else {
                        p = checking_head;
                        while(p->next != NULL){
                            p = p->next;
                        }
                        p->next = &object;
                        p->next->next = NULL;
                        //cout<<"A \n";
                        break;
                    }   
                }
                else {
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
                            //temp1.getAccount(savings_head, account_no);
                            cout <<"Please enter the amount you wish to credit: ";
                            cin >> amount;
                            temp->creditAmount(amount);
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
                            cout <<"Please enter the amount you wish to credit: ";
                            cin >> amount;
                            temp->creditAmount(amount);
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
                            cout <<"Please enter the amount you wish to debit: ";
                            cin >> amount;
                            temp->debitAmount(amount);
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
                            cout <<"Please enter the amount you wish to debit: ";
                            cin >> amount;
                            temp->debitAmount(amount);
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
                    cout <<"Please enter the new Interest Rate for Updating: ";
                    cin >> interest_rate;
                    temp->setInterest(interest_rate);
                }
                else {
                    cout<<"Please enter a valid account number to Update the Interest Rate \n";
                }
                break;
            case 5:
                cout<<"Please enter the account number of the Savings account you wish to calculate interest of: ";
                cin >> account_no;
                if(temp1.getAccount(savings_head, account_no) != NULL){
                    savingsAccount *temp = temp1.getAccount(savings_head, account_no);
                    interest_amount = temp->calculateInterest();
                    cout<<"The interest calculated for the account "<<account_no<<" is "<<interest_amount<< endl;
                }
                else {
                    cout<<"Please enter a valid account number to Calculate Interest \n";
                }
                break;
            case 6:
                cout<<"Please enter the account number of the Savings account you wish to calculate and update interest of: ";
                cin >> account_no;
                if(temp1.getAccount(savings_head, account_no) != NULL){
                    savingsAccount *temp = temp1.getAccount(savings_head, account_no);
                    interest_amount = temp->calculateInterest();
                    temp->creditAmount(interest_amount);
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
                    cout <<"Please enter the new Transaction fee for Updating: ";
                    cin >> fee;
                    temp->setFee(fee);
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
                    fee = temp->getFee();
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
                    cout <<"Please enter the amount you wish to debit: ";
                    cin >> amount;
                    temp->debitAmount(amount);
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
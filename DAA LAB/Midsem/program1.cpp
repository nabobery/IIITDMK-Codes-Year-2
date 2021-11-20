/* Question 1 : Given two integers m,n, (i) the objective is to perform m*n using binary representation of m and n  
(ii) Present the logic and its asymptotic analysis in worst case.
This Question is done by CS20B1044 Avinash R Changrani */

#include<vector>
#include <cmath>
#include <iostream>
using namespace std;

// A class containing all functions for the numbers
class binary{
    public :
        int m,n;
        vector<int> binaryM,binaryN,multiplication;
        void decitoBin();
        // A function to print the Binary representation of the number
        void binaryPrinter(vector<int> array){
            for(int i = array.size() - 1; i >= 0 ; i--){
                cout << array[i] ;
            }
            cout <<"\n";
        }
        void binaryMultiplication();
        vector<int> binaryAdder(vector<int> b1, vector<int> b2);
        int bintoDeci(vector<int> binary_number);

};

// Function to convert the 2 numbers from Decimal to Binary
void binary::decitoBin(){
    int temp;
    temp = m;
    while(temp != 0){
        binaryM.push_back(temp % 2);
        temp = temp / 2;
    }
    temp = n;
    while(temp != 0){
        binaryN.push_back(temp % 2);
        temp = temp / 2;
    }
}

// A fucntion to multiply 2 Binary Numbers
void binary::binaryMultiplication(){
    multiplication.push_back(0);
    for (int i = 0; i < binaryN.size(); ++i) {
        vector<int> temp;
        for (int j = 0; j < i; ++j) {
            temp.push_back(0);
        }
        for (int j = 0; j < binaryM.size(); ++j) {
            temp.push_back(binaryN[i] * binaryM[j]);
        }
        multiplication = binaryAdder(multiplication, temp);
    }
}

// A function to add 2 Binary Numbers
vector <int> binary::binaryAdder(vector <int> b1, vector <int> b2){
    vector<int> temp1=b1,temp2=b2,temp;
    if(temp1.size()<temp2.size()){
        temp=temp1;
        temp1=temp2;
        temp2=temp;
        for (int i = 0; i < temp1.size()-temp2.size(); ++i) {
            temp2.push_back(0);
        }

    }
    int carry=0,sum=0;
    for (int i = 0; i < temp2.size(); ++i) {
        sum=carry+temp1[i]+temp2[i];
        if(sum==3){
            temp1[i]=1;
            carry=1;
            continue;
        }
        else if(sum==2){
            carry=1;
            temp1[i]=0;
            continue;
        }
        else if(sum==1){
            carry=0;
            temp1[i]=1;
            continue;
        }
        else if(sum==0){
            carry=0;
            temp1[i]=0;
            continue;
        }
    }
    if(carry==1){
        temp1.push_back(1);
    }

    return temp1;
}

// A function to convert a Binary number to Decimal
int binary::bintoDeci(vector<int> binary_number) {
    int result=0;
    for (int i = 0; i < binary_number.size(); ++i) {
        result+=binary_number[i]*pow(2,i);
    }
    return result;
}


int main(){
    binary obj;
    cout << "Please enter Positive Number1: ";
    cin >> obj.m;
    cout << "Please enter Positive Number2: ";
    cin >> obj.n;
    obj.decitoBin();
    cout<<"The Binary Representation of number1: "<< obj.m << " is ";
    obj.binaryPrinter(obj.binaryM);
    cout<<"The Binary Representation of number2: "<< obj.n << " is ";
    obj.binaryPrinter(obj.binaryN);
    obj.binaryMultiplication();
    cout<<"The Binary Representation of the Multiplication of 2 numbers is: \n";
    obj.binaryPrinter(obj.multiplication);
    cout<<"The Decimal Representation of the Multiplication of 2 numbers is: "<< obj.bintoDeci(obj.multiplication) << "\n";
    return 0;
}

// CS20B1044 Avinash R Changrani
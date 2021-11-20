// Count the number of negative numbers in an integer array using 2-way and 3-way approach.
#include<vector>
#include<iostream>
using namespace std;

class Array{
    vector<int> array;
    public:
        void arrayEntry(int element){
            array.push_back(element);
        }  
        void countNegative_1way(){
            int count = 0;
            for(int i = 0; i < array.size();i++){
                if (array[i] < 0) 
                    count++;
            }
            cout << "The number of negative numbers in the array is " << count << endl;
        }
        void countNegative_2way(){

        }
};

int main(){
    Array arr;
    cout <<"This is a program to find the count of negative numbers in the array\n";
    int choice = 1, sum;
    while (choice){
        if (choice == 1){
            cout << "Please enter the element to be added to the array: \n";
            int element;
            cin >> element;
            arr.arrayEntry(element);
        }
        else{
            cout << "Please enter a valid choice\n";
        }
        cout << "Enter 1 if you want to add more else 0 \n";
        cin >> choice;
    }
    return 0;
}



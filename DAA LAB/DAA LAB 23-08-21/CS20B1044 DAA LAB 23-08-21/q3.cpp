/* Question 3 : Given an array arr of size n and an integer X. Find if there's a triplet in the array which sums up 
to the given integer X.*/
#include <iostream>
#include <vector>
using namespace std;

class array{
    private:
        vector<int> array;
    public:
        void arrayEntry(int element){
            array.push_back(element);
        }
        bool findTriplets(int sum){
            // Fix first element to be array[i]
            for (int i = 0; i < array.size() - 2; i++) {  
                // Fix second element to be array[j]
                for (int j = i + 1; j < array.size() - 1; j++) { 
                    // Fix third element to be array[k]
                    for (int k = j + 1; k < array.size(); k++) { 
                        if (array[i] + array[j] + array[k] == sum) { 
                            cout << "Triplets are " << array[i] << ", " << array[j] << ", " << array[k] << endl; 
                            return true; 
                    } 
                } 
            } 
        }
        // Return false if no triplet found 
        return false;
        }

};

int main(){
    array arr;
    cout <<"This is a program to tell whether there is a triplet in the given array that satisfies the sum given \n";
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
    cout<<"Please enter the sum you want to find if there're any triplets in the given array that satify the given sum \n";
    cin >> sum;
    if(arr.findTriplets(sum)){
        cout <<"Triplets exists in the array that satisfies the sum \n";
    }
    else {
        cout << "No Triplets exists that satisfies the sum in the given array\n";
    }
    return 0;
}
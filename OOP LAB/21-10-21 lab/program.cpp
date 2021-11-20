/* Question : Program to implement selection sort using the template in C++ (function template). The data is stored in 
an array of size ‘n’. Identify 1 boundary condition and handle them using exception handling. The program has the following 
menus,
1) Get Values
2) Sort
3) Display
4) Exit
Disclaimer : As the question stated only for one exception handling, I handled only one exception. There're many exceptions
possible, but as question stated, I handled only one.
*/

// This program was done by CS20B1044 Avinash R Changrani
#include <iostream>
using namespace std;

// A function template for swapping two values
template <typename T>
void swap(T *a, T *b){
    T temp = *a;
    *a = *b;
    *b = temp;
}

// A function template for sorting the array using Selection Sort
template <typename T>
void selectionSort(T arr[], int n){
    int min; 
    for (int i = 0; i < n-1; i++){
        min = i;
        for (int j = i+1; j < n; j++)
        if (arr[j] < arr[min])
            min = j; 
        swap(&arr[min], &arr[i]);
    }
}

// A function template for displaying the array
template <typename T>
void Display(T arr[], int n){
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << "\n";
}

// A function template for Menu driven program
template <typename T>
void Menu(T arr[], int n){
    int choice, flag = -1;
    while(1){
        cout<<"Menu : \n 1)Get Values \n 2)Sort \n 3)Display \n 4)Exit";
        cout<<"\nPlease Enter your choice: ";
        cin>>choice;
        switch(choice){
            case 1:
                cout<<"Please enter the elements of the array: \n";
                for(int i = 0; i < n; i++){
                    cout<<"Enter Element: ";
                    cin >> arr[i];
                }
                flag = 0;
                break;
            case 2:
                if(flag == -1){
                    cout<<"Please enter the array and try again!!\n";
                }
                else{
                    selectionSort(arr, n);
                    cout<<"The array is sorted using selectionSort \n";
                }
                break;
            case 3:
                if(flag == -1){
                    cout<<"The array is empty!! Please enter the array and try again \n";
                }
                else{
                    cout<<"The Array is: \n";
                    for(int i = 0; i < n; i++){
                        cout<< arr[i] << " ";
                    }
                    cout<<"\n";
                }
                break;
            case 4:
                exit(0);
            default:
                cout <<"Wrong choice, Please try again!\n";
        }
    }
}

// Main program
int main(){
    int option = 0, size = -1;
    cout<<"Please enter the data type of the array \n";
    while(option != 1 && option != 2 && option != 3){
        cout<<"Enter 1 for Int, 2 for Char and 3 for Float: ";
        cin >> option;
        if(option != 1 && option != 2 && option != 3){
            cout<<"Please enter a valid option again!\n";
        }
    }
    while(size <= 0){
        cout<<"Please enter the size of the array : ";
        cin >> size;
        // Exception handling for non-positive size inputs
        try {
            if (size<=0){
                throw size;
            }
        }
        catch(int x){
            cerr<<"Invalid size. Please try again.\n";
            continue;
        }
    }
    if(option == 1){
        int array[size];
        Menu(array, size);
    }
    else if (option == 2){
        char array[size];
        Menu(array, size);
    }
    else if (option == 3){
        float array[size];
        Menu(array, size);
    }
    return 0;
}
// CS20B1044 Avinash R Changrani
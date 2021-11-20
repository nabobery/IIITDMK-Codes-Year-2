#include <iostream>
#include <cmath>
using namespace std;


int *decitobin(int num){
    int size = ceil(log2(num));
    int arr[size];
    int *array = arr;
    int i = size;
    while(num >= 1){
        arr[i] = num % 2;
        num = num / 2;
        i--;
    }
    return array;
}

void arrayPrinter(int arr[]){
    int size = *(&arr + 1) - arr;
    for(int i = 0; i < size; i++){
        cout << arr[i] ;
    }
    cout <<"\n";
 }


int main(){
    int num1, num2;
    cout << "Please enter Number1: ";
    cin >> num1;
    cout << "Please enter Number2: ";
    cin >> num2;
    int *bin1 = decitobin(num1);
    int *bin2 = decitobin(num2);
    cout<<"The Binary Representation of number1: "<< num1 << " is ";
    arrayPrinter(bin1);
    cout<<"The Binary Representation of number2: "<< num2 << " is ";
    arrayPrinter(bin2);
    return 0;
}
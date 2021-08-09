#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"This is a program to get min,max,smin and smax of the given array \n";
    cout<<"Please enter the size of the array: \n";
    cin >> n;
    int arr[n];
    cout<<"Please enter the elements of the array of size " << n << ": \n";
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    return 0;
}
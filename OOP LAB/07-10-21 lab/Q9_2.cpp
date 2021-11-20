// This program is done by CS20B1044 Avinash R Changrani
#include <iostream>
using namespace std;

// A Function template for Bubble Sort
template<typename T>
void bubbleSort(T arr[], int size){
	for(int i=0; i < size-1; i++){
		for(int j=0; j < size-i-1; j++){
			if(arr[j]>arr[j+1]){
				T temp = arr[j+1];
				arr[j+1] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

// Menu Driven Program in main
int main(){
    int choice, size;
    while(1){
        cout<<"Menu : \n 1)Int Sort \n 2)Float Sort \n 3)Char Sort \n 4)Exit";
        cout<<"\nPlease Enter your choice: ";
        cin>>choice;
        if (choice == 1){
            cout<<"Please enter the size of the array you want to sort: ";
            cin >> size;
            int arr[size];
            cout<<"Please Enter the array elements :";
            for(int i=0; i<size; i++){
                cin >> arr[i];
            }
            bubbleSort<int>(arr,size);
            cout<<"The array after sorting is: ";
            for(int i=0; i<size; i++){
                cout << arr[i] << " ";
            }
            cout<<"\n";
        }
        else if(choice == 2){
            cout<<"Please enter the size of the array you want to sort: ";
            cin >> size;
            float arr[size];
            cout<<"Please Enter the array elements :";
            for(int i=0; i<size; i++){
                cin >> arr[i];
            }
            bubbleSort(arr, size);
            cout<<"The array after sorting is: ";
            for(int i=0; i<size; i++){
                cout << arr[i] << " ";
            }
            cout<<"\n";
        }       
        else if (choice == 3){ 
            cout<<"Please enter the size of the array you want to sort: ";
            cin >> size;
            char arr[size];
            cout<<"Please Enter the array elements: ";
            for(int i=0; i<size; i++){
                cin >> arr[i];
            }
            bubbleSort(arr, size);
            cout<<"The array after sorting is: ";
            for(int i=0; i<size; i++){
                cout << arr[i] << " ";
            }
            cout<<"\n";
        }
        else if (choice == 4){ 
            exit(0);
        }
        else {
            cout<<"Wrong choice, Please try again!\n";
        }

    }
    return 0;
}

// CS20B1044 Avinash R Changrani
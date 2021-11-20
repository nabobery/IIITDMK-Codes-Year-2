#include<vector>
#include<iostream>
using namespace std;

class Array{
    vector<int> array;
    public:
        void arrayEntry(int element){
            array.push_back(element);
        } 
        void insertionSort(int n){
            int key, j;
            for (int i = 1; i < n; i++){
                key = array[i];
                j = i - 1;
        
                /* Move elements of arr[0..i-1], that are
                greater than key, to one position ahead
                of their current position */
                while (j >= 0 && array[j] > key)
                {
                    array[j + 1] = array[j];
                    j = j - 1;
                }
                array[j + 1] = key;
            }
            for (int i = 0; i < n; i++)
                cout << array[i] << " ";
            cout << endl;

        }
        

};

int main(){
    Array arr;
    int size, element;
    cout << "Please enter the size of the array: ";
    cin >> size;
    for(int i = 0; i < size; i++){
        cout <<"Enter the array element: ";
        cin >> element;
        arr.arrayEntry(element);
    }
    cout <<"Array after Insertion Sort : \n";
    arr.insertionSort(size);
    return 0;
}
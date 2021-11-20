/*
Question 2 : Implement Quicksort with 2 pivots.   Choose two arbitrary elements of the given array A, say x and y.   
Maintain three windows at each iteration, assuming x < y, the first window has elements < x, the second window has 
elements between x and y, and the third window has elements > y.
This Question is done by CS20B1044 Avinash R Changrani
*/

#include <iostream>
#include <vector>
using namespace std;


// This algorithm offers O(n log(n)) performance but the worst case is still O(n^2) when the array is already sorted in an increasing or decreasing order.

class Array {
    public:
        vector<int> array;
        void arrayEntry(int element){
            array.push_back(element);
        } 
        void arrayPrinter(){
            for (int i=0; i<array.size(); i++){
                cout << array[i] << " ";
            }
            cout<<"\n";
        }
        int partition(int low, int high, int* lp);
        void swap(int* a, int* b){
            int temp = *a;
            *a = *b;
            *b = temp;
        }
        void DualPivotQuickSort(int low, int high);
};

int Array::partition(int low, int high, int* lp){
    if (array[low] > array[high])
        swap(&array[low], &array[high]);
  
    // p is the left pivot, and q is the right pivot.
    int j = low + 1;
    int g = high - 1, k = low + 1, p = array[low], q = array[high];
    while (k <= g) {
  
        // if elements are less than the left pivot
        if (array[k] < p) {
            swap(&array[k], &array[j]);
            j++;
        }
  
        // if elements are greater than or equal to the right pivot
        else if (array[k] >= q) {
            while (array[g] > q && k < g)
                g--;
            swap(&array[k], &array[g]);
            g--;
            if (array[k] < p) {
                swap(&array[k], &array[j]);
                j++;
            }
        }
        k++;
    }
    j--;
    g++;
  
    // bring pivots to their appropriate positions.
    swap(&array[low], &array[j]);
    swap(&array[high], &array[g]);
  
    // returning the indices of the pivots.
    *lp = j; // because we cannot return two elements
    // from a function.
  
    return g;
}

void Array::DualPivotQuickSort(int low, int high){
    if (low < high) {
        // lp means left pivot, and rp means right pivot.
        int lp, rp;
        rp = partition(low, high, &lp);
        DualPivotQuickSort(low, lp - 1);
        DualPivotQuickSort(lp + 1, rp - 1);
        DualPivotQuickSort(rp + 1, high);
    }

}

int main() {
    Array arr;
    int size, element;
    cout<<"Please enter size of array: ";
    cin >> size;
    for(int i = 0; i < size; i++){
        cout <<"Enter the array element: ";
        cin >> element;
        arr.arrayEntry(element);
    }
    cout<<"Given Array is: \n";
    arr.arrayPrinter();
    arr.DualPivotQuickSort(0, size - 1);
    cout << "\nSorted array is: \n";
    arr.arrayPrinter();
}
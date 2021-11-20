#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

int partition(vector<int> arr, int low, int high, int* lp);
int partition_r(vector<int> arr, int low, int high, int* lp);

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void DualPivotQuickSort(vector<int> arr, int low, int high)
{
    if (low < high) {
        // lp means left pivot, and rp means right pivot.
        int lp, rp;
        rp = partition_r(arr, low, high, &lp);
        DualPivotQuickSort(arr, low, lp - 1);
        DualPivotQuickSort(arr, lp + 1, rp - 1);
        DualPivotQuickSort(arr, rp + 1, high);
    }
}

int partition(vector<int> arr, int low, int high, int* lp)
{
    if (arr[low] > arr[high])
        swap(&arr[low], &arr[high]);
  
    // p is the left pivot, and q is the right pivot.
    int j = low + 1;
    int g = high - 1, k = low + 1, p = arr[low], q = arr[high];
    while (k <= g) {
  
        // if elements are less than the left pivot
        if (arr[k] < p) {
            swap(&arr[k], &arr[j]);
            j++;
        }
  
        // if elements are greater than or equal
        // to the right pivot
        else if (arr[k] >= q) {
            while (arr[g] > q && k < g)
                g--;
            swap(&arr[k], &arr[g]);
            g--;
            if (arr[k] < p) {
                swap(&arr[k], &arr[j]);
                j++;
            }
        }
        k++;
    }
    j--;
    g++;
  
    // bring pivots to their appropriate positions.
    swap(&arr[low], &arr[j]);
    swap(&arr[high], &arr[g]);
  
    // returning the indices of the pivots.
    *lp = j; // because we cannot return two elements
    // from a function.
  
    return g;
}

int partition_r(vector<int> arr, int low, int high, int* lp){
    srand(time(NULL));
    int random1 = low + rand() % (high - low);
    int random2 = low + rand() % (high - low);
    if(arr[random1] > arr[random2]){
        swap(arr[random2], arr[high]);
        swap(arr[random1], arr[low]);
    }
    else {
        swap(arr[random1], arr[high]);
        swap(arr[random2], arr[low]);
    }
    return partition(arr, low, high, lp);
}


int main(){
    vector<int> array;
    int size, element;
    cout<<"Please enter size of array: ";
    cin >> size;
    for (int i=0; i<size; i++){
        cout <<"Enter the array element: ";
        cin >> element;
        array.push_back(element);
    }
    cout<<"Given Array is: \n";
    for (int i=0; i<size; i++){
        cout << array[i] << " ";
    }
    DualPivotQuickSort(array, 0, size - 1);
    cout << "\n Sorted array is: \n";
    for (int i=0; i<size; i++){
        cout << array[i] << " ";
    }
    return 0;
}
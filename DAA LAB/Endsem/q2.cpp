// This code has been done by CS20B1044 Avinash R Changrani
// Question 2 :  Knapsack with all profits same (p_i is same for all objects)
#include <iostream>
using namespace std;
void merge(int array[], int const left, int const mid, int const right);
void mergeSort(int array[], int const begin, int const end);
void printArray(int arr[], int n);
void greedyKnapsack(int* weightArray,int profit,int number,int maxWeight);

void merge(int array[], int const left, int const mid, int const right){
    auto const subArrayOne = mid - left + 1;
    auto const subArrayTwo = right - mid;
    auto *leftArray = new int[subArrayOne], *rightArray = new int[subArrayTwo];
    for (auto i = 0; i < subArrayOne; i++)
        leftArray[i] = array[left + i];
    for (auto j = 0; j < subArrayTwo; j++)
        rightArray[j] = array[mid + 1 + j];

    auto indexOfSubArrayOne = 0,
    indexOfSubArrayTwo = 0;
    int indexOfMergedArray = left;
    while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) {
        if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]) {
            array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else {
            array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }
    while (indexOfSubArrayOne < subArrayOne) {
        array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }
    while (indexOfSubArrayTwo < subArrayTwo) {
        array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
}


void mergeSort(int array[], int const begin, int const end){
    if (begin >= end)
        return;

    auto mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);
    merge(array, begin, mid, end);
}

void printArray(int arr[], int n){
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout<<"\n";
}

void greedyKnapsack(int* weightArray,int profit,int n,int maxWeight){
    //Using Greedy strategy wrt weight by choosing lesser weight objects to maximise profit
    //We do this by sorting the weight array and add objects till we can longer add to knapsack
    //Using mergesort to sort which has complexity of O(nlogn) so that the whole algo is o(n^2)
    mergeSort(weightArray,0,n-1);
    int remaining_weight = maxWeight;
    int total_profit = 0;
    for (int i = 0; i < n; ++i){
        if(remaining_weight>=weightArray[i]){
            total_profit += profit;
            cout<<"Object of weight: "<<weightArray[i]<<" is Chosen\n";
            remaining_weight -= weightArray[i];
        }
        else{
            break;
        }
    }
    cout<<"Weight remaining in the Knapsack is "<<remaining_weight<<"\n";
    cout<<"The Maximum Profit of the Knapsack is "<<total_profit<<"\n";
}

int main(){
    int size, max_weight, profit;
    cout<<"Enter the size of the objects array: ";
    cin >> size;
    cout<<"Enter the maximum weight of the Knapsack:";
    cin>>max_weight;
    cout<<"Enter the profit of all the objects: ";
    cin >> profit;
    int weight[size];
    for(int i = 0; i < size;i++){
        cout<<"Enter the weight of the objects: ";
        cin >> weight[i];
    }
    cout<<"The given profit array is: \n";
    printArray(weight, size);
    greedyKnapsack(weight,profit,size,max_weight);
    return 0;
}


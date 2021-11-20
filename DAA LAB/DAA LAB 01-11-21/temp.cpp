#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

void knapSack(int weight,vector<int> weightArray, vector<int> valueArray){
    vector<vector<int>> knapSack(valueArray.size() + 1, vector<int>(weight + 1));
    for(int i = 0; i <= valueArray.size(); i++){
        for(int j = 0; j <= weight; j++){
            if(i == 0 || j == 0){
                knapSack[i][j] = 0;
            }
            else if(weightArray[i - 1] <= weight){
                knapSack[i][j] = max(valueArray[i - 1] + knapSack[i - 1][j - weightArray[i - 1]], knapSack[i - 1][j]);
            }
            else {
                knapSack[i][j] = knapSack[i - 1][j];
            }
        }
    }
    int result = knapSack[valueArray.size()][weight], w = weight;
    cout<<"The maximum total value is "<< result << " \n";
    cout<<"The weight of corresponding objects are: \n";
    for(int i = valueArray.size(); i > 0 && result > 0; i--){
        if(result == knapSack[i - 1][w]){
            continue;
        }
        else {
            cout<<weightArray[i - 1]<<" ";
            result = result - valueArray[i - 1];
            w -= weightArray[i - 1];
        }
    }
    cout<<"\n";
}

void knapSack(double weight,vector<double> weight_array, vector<double> value_array){
    vector<vector<double>> knapSack(value_array.size() + 1, vector<double>(ceil(weight) + 1));
    for(int i = 0; i <= value_array.size(); i++){
        for(int j = 0; j <= ceil(weight); j++){
            // filling first row and column with 0
            if(i == 0 || j == 0){
                knapSack[i][j] = 0;
            }
            // if weight of ith object less than weight, take max of Pi + knapsack(i - 1, w- weight) and knapsack(i - 1,weight)
            else if(weight_array[i - 1] <= weight){
                knapSack[i][j] = max(value_array[i - 1] + knapSack[i - 1][j - weight_array[i - 1]], knapSack[i - 1][j]);
            }
            else {
                knapSack[i][j] = knapSack[i - 1][j];
            }
        }
    }
    double result = knapSack[value_array.size()][weight], w = weight;
    cout<<"The maximum total value is "<< result << " \n";
    cout<<"The weight of corresponding objects are: \n";
    for(int i = value_array.size(); i > 0 && result > 0; i--){
        if(result == knapSack[i - 1][w]){
            continue;
        }
        else {
            cout<<weight_array[i - 1]<<" ";
            result = result - value_array[i - 1];
            w -= weight_array[i - 1];
        }
    }
    cout<<"\n";

}
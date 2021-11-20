#include<iostream>
#include<vector>
#include <cmath>
using namespace std;

class Polymorphism{
    private:
        vector<int>weightArray;
        vector<int>valueArray;
        vector<double>weight_array;
        vector<double>value_array;
    public:
        void arrayEntry(int data1, int data2){
            weightArray.push_back(data1);
            valueArray.push_back(data2);
        }
        void arrayEntry(double data1, double data2){
            weight_array.push_back(data1);
            value_array.push_back(data2);
        }
        int max(int a, int b){
            return (a > b) ? a : b;
        }
        double max(double x, double y){
            return (x > y) ? x : y;
        }
        void Display1(){
            cout<<"The given weight array of objects is \n";
            for(int i=0; i<weightArray.size(); i++){
                cout<<weightArray[i]<< " ";
            }
            cout<<"\n";
            cout<<"The given Value of objects array is \n";
            for(int i=0; i<valueArray.size(); i++){
                cout<<valueArray[i]<< " ";
            }
            cout<<"\n";
        }
        void Display2(){
            cout<<"The given weight array of objects is \n";
            for(int i=0; i<weight_array.size(); i++){
                cout<<weight_array[i]<< " ";
            }
            cout<<"\n";
            cout<<"The given Value of objects array is \n";
            for(int i=0; i<value_array.size(); i++){
                cout<<value_array[i]<< " ";
            }
            cout<<"\n";
        }
        void knapSack(int weight){
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

            cout<<"The maximum total value is "<< knapSack[valueArray.size()][weight] << " \n";
        }
        void knapSack(double weight){
            vector<vector<double>> knapSack(value_array.size() + 1, vector<double>(ceil(weight) + 1));
            for(int i = 0; i <= value_array.size(); i++){
                for(int j = 0; j <= ceil(weight); j++){
                    if(i == 0 || j == 0){
                        knapSack[i][j] = 0;
                    }
                    else if(weight_array[i - 1] <= weight){
                        knapSack[i][j] = max(value_array[i - 1] + knapSack[i - 1][j - weight_array[i - 1]], knapSack[i - 1][j]);
                    }
                    else {
                        knapSack[i][j] = knapSack[i - 1][j];
                    }
                }
            }
            cout<<"The maximum total value is "<< knapSack[value_array.size()][ceil(weight)] << " \n";
        }




};

int main(){
    // for testing
    /*Polymorphism object;
    int size;
    double value, weight, max_weight;
    cout<<"Enter the size of the objects array:";
    cin>>size;
    for(int i = 0; i < size; i++){
        cout<<"Enter the weight and value of the object: ";
        cin >> weight >> value;
        object.arrayEntry(weight, value);
    }
    cout<<"Enter the maximum weight of the Knapsack:";
    cin>>max_weight;
    object.Display2();
    object.knapSack(max_weight);*/
    return 0;
}
#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

class dpKnapsack {
    private:
        vector<int>weightArray;
        vector<int>valueArray;
    public:
        void arrayEntry(int data1, int data2){
            weightArray.push_back(data1);
            valueArray.push_back(data2);
        }
        /*int max(int a, int b){
            return (a > b) ? a : b;
        }*/
        void Display(){
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
        void knapSack(int weight){
            int n = valueArray.size();
            vector<vector<int>> knapSack(n + 1, vector<int>(weight + 1));
            for(int i = 0; i <= n; i++){
                for(int j = 0; j <= weight; j++){
                    if(i == 0 || j == 0){
                        knapSack[i][j] = 0;
                    }
                    else if(weightArray[i - 1] <= weight){
                        knapSack[i][j] = max((valueArray[i - 1] + knapSack[i - 1][j - weightArray[i - 1]]), knapSack[i - 1][j]);
                    }
                    else {
                        knapSack[i][j] = knapSack[i - 1][j];
                    }
                }
            }
            int result = knapSack[n][weight], w = weight;
            cout<<"The maximum total value is "<< result << " \n";
            cout<<"The weight of corresponding objects are: \n";
            for(int i = n; i > 0 && result > 0; i--){
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

};

int main() {
    dpKnapsack object;
    int size, value, weight, max_weight;
    cout<<"Enter the size of the objects array:";
    cin>>size;
    for(int i = 0; i < size; i++){
        cout<<"Enter the weight and value of the object: ";
        cin >> weight >> value;
        object.arrayEntry(weight, value);
    }
    cout<<"Enter the maximum weight of the Knapsack:";
    cin>>max_weight;
    object.Display();
    object.knapSack(max_weight);
    return 0;
}
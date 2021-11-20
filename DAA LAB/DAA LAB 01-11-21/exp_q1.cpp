#include<iostream>
#include<vector>
using namespace std;

// Coin Change
class dpCoin {
    private:
        vector<int>coinArray;
    public:
        void arrayEntry(int data){
            coinArray.push_back(data);
        }
        void Display(){
            for(int i = 0; i < coinArray.size(); i++){
                cout<<coinArray[i] << " ";
            }
            cout<<" \n";
        }
        int coinChange(int amount){
            vector<int>ways(amount + 1);
            ways[0] = 1;
            for(int i = 0; i < coinArray.size(); i++){
                for(int j = 0; j < ways.size(); j++){
                    if(coinArray[i] <= j){
                        ways[j] += ways[(j - coinArray[i])];
                    }
                }
            }
            return ways[amount];
        }
};

/* 0-1 Knapsack
class dpKnapsack {
    private:
        vector<int>weightArray;
        vector<int>valueArray;
    public:
        void arrayEntry(int data1, int data2){
            weightArray.push_back(data1);
            valueArray.push_back(data2);
        }
        int max(int a, int b){
            return (a > b) ? a : b;
        }
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
        int knapSack(int weight){
            vector<vector<int>> knapSack(valueArray.size() + 1, vector<int>(weight + 1));
            for(int i = 0; i <= valueArray.size(); i++){
                for(int j = 0; j <= weight; j++){
                    if(i == 0 || j == 0){
                        knapSack[i][j] = 0;
                    }
                    else if(weightArray[i] <= weight){
                        knapSack[i][j] = max(valueArray[i - 1] + knapSack[i - 1][j - weightArray[j - 1]], knapSack[i - 1][j]);
                    }
                    else {
                        knapSack[i][j] = knapSack[i - 1][j];
                    }
                }
            }
            return knapSack[valueArray.size()][weight];
        }

};

// main code

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
    cout<<"The result is "<< object.knapSack(max_weight) << " \n";
    return 0;
}
*/

int main() {
    int size, element, amount, ways;
    dpCoin object;
    cout<<"Enter the size of the Denominations array:";
    cin>>size;
    for(int i = 0; i < size; i++){
        cout<<"Enter the denomination: ";
        cin >> element;
        object.arrayEntry(element);
    }
    cout<<"Now enter the amount you want to find ways of denominations of: ";
    cin >> amount;
    cout<<"The given denominations array is: \n";
    object.Display();
    ways = object.coinChange(amount);
    cout<<"The number of ways(combinations) using the denominations to get the given amount is: "<< ways << "\n";
    return 0;
}
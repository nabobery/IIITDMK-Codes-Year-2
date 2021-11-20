#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

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
            int x, y, n = coinArray.size();
            int table[amount + 1][n];
            
            // value case (n = 0)
            for (int i = 0; i < n; i++)
                table[0][i] = 1;
        
            for (int i = 1; i < amount + 1; i++){
                for (int j = 0; j < n; j++){
                    // Count of solutions including S[j]
                    x = (i-coinArray[j] >= 0) ? table[i - coinArray[j]][j] : 0;
        
                    // Count of solutions excluding S[j]
                    y = (j >= 1) ? table[i][j - 1] : 0;
        
                    // total count
                    table[i][j] = x + y;
                }
            }
            return table[amount][n - 1];
        }
        /*
        int coinChange(int amount) {
            int Max = amount + 1;
            vector<int> dp(amount + 1, Max);
            dp[0] = 0;
            for (int i = 1; i <= amount; i++) {
                for (int j = 0; j < coinArray.size(); j++) {
                    if (coinArray[j] <= i) {
                        dp[i] = min(dp[i], dp[i - coinArray[j]] + 1);
                    }
                }
            }
            return dp[amount] > amount ? -1 : dp[amount];
        }
        */
};

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
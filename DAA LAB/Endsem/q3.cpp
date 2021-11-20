// This code has been done by CS20B1044 Avinash R Changrani
// Question 3 : (0, 1/2, 1)-Knapsack
// We use top-down approach of dynamic programming to solve this problem
#include <bits/stdc++.h>
using namespace std;

// Returns the value of maximum profit
double knapSackRec(int W, double wt[],double val[], int i,double **dp){
    // base condition
    if (i < 0)
        return 0;
    if (dp[i][W] != -1)
        return dp[i][W];

    if (wt[i] > W){
        // variant added to check for 1/2 weight.
        if (wt[i] / 2 > W)  {
            dp[i][W] = knapSackRec(W, wt,val, i - 1,dp);
        }
        else{
            dp[i][W] = max(val[i] / 2 + knapSackRec(W - wt[i] / 2,wt, val,i - 1, dp),knapSackRec(W, wt, val,i - 1, dp));
        }

        return dp[i][W];
    }
    else{
        // Store value in a table before return
        // finding max btw half anf full values of objects.
        dp[i][W] = max(val[i] / 2 + knapSackRec(W - wt[i] / 2,wt, val,i - 1, dp),max(val[i] + knapSackRec(W - wt[i],wt, val,i - 1, dp),knapSackRec(W, wt, val,i - 1, dp)));

        // Return value of table after storing
        return dp[i][W];
    }
}

double knapSack(int W, double wt[], double val[], int n){
    // declaring the double table dynamically
    double **dp;
    dp = new double *[n];

    // loop to create the table dynamically
    for (int i = 0; i < n; i++)
        dp[i] = new double[W + 1];

    // loop to initially filled the table with -1
    for (int i = 0; i < n; i++)
        for (int j = 0; j < W + 1; j++)
            dp[i][j] = -1;
    return knapSackRec(W, wt, val, n - 1, dp);
}

int main()
{
    int max_weight;
    cout << "Enter Maximum Weight OF Knapsack: ";
    cin >> max_weight;
    int n;
    cout << "Enter The Number of Objects : ";
    cin >> n;
    double weight_arr[n], value_arr[n];
    for (int i = 0; i < n; i++){
        cout<<"Enter the weight and value of the object: ";
        cin >> weight_arr[i] >> value_arr[i];
    }
    cout <<"The Maximum profit of the Knapsack is " << knapSack(max_weight, weight_arr, value_arr, n);
    return 0;
}

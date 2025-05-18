#include<iostream>
#include<vector>
using namespace std;

// Memoization table
// vector<vector<int>> dp;

// int knapsack(int index, int W, vector<int> &weights, vector<int> &values) {
//     if(index == 0) {
//         if(weights[0] <= W) return values[0];
//         else return 0;
//     }

//     if(dp[index][W] != -1) return dp[index][W];

//     int notPick = knapsack(index - 1, W, weights, values);
//     int pick = 0;
//     if(weights[index] <= W)
//         pick = values[index] + knapsack(index - 1, W - weights[index], weights, values);

//     return dp[index][W] = max(pick, notPick);
// }

int main() {
    vector<int> weights = {1, 3, 4, 5};
    vector<int> values = {10, 40, 50, 70};
    int W = 8;  // Knapsack capacity
    int n = weights.size();

    // Initialize memo table with -1
    // dp.assign(n, vector<int>(W + 1, -1));

    // cout << "Maximum value in Knapsack: " << knapsack(n - 1, W, weights, values) << endl;



    vector<vector<int>> dp(n , vector<int>(W+1 , 0));

    for(int i=0;i<=W;i++){
        dp[0][i] = weights[i];
    }

    for(int i =1;i<n;i++){
        for(int cap=0;cap<=W;cap++){
            int nottake = dp[i][cap];

            int take = INT_MIN;
            if(weights[i]<=cap){
                take = dp[i][cap-weights[i]];
            }

            dp[i][cap] = max(nottake , take);
        }
    }

    cout<<dp[n-1][W];

    return 0;
}

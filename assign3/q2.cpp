#include<iostream>
using namespace std;

// resucrsive 
// int solve(vector<int> &arr , int i , int j){
//     if(i==j) return 0;

//     int mini = INT_MAX;

//     for(int k=i;k<=j-1;k++){
//         int ans = solve(arr , i , k) + solve(arr , k+1 , j) + arr[i-1]*arr[k]*arr[j];

//         mini = min(ans , mini);
//     }

//     return mini;
// }

void printparas(int i , int j , vector<vector<int>>&bracket , char &name){
    if(i==j){
        cout<<name++;
        return;
    }

    cout<<"(";
    printparas(i , bracket[i][j] , bracket ,name);
    printparas(bracket[i][j]+1 , j , bracket , name);
    cout<<")";
}

int main(){
    vector<int> arr = {10, 20, 30, 40, 50};
    int n = arr.size();

    vector<vector<int> >dp(n , vector<int>(n , 0));
    vector<vector<int>> bracket(n, vector<int>(n, 0));

    for(int len = 2;len<n;len++){
        for(int i =1;i<n-len+1;i++){
            int j = i+len-1;

            dp[i][j] = INT_MAX;
            for(int k=i;k<j;k++){
                int cost = dp[i][k] + dp[k+1][j] + arr[i-1] * arr[k] * arr[j];
                if (cost < dp[i][j]) {
                    dp[i][j] = cost;
                    bracket[i][j] = k;  // store k
                }
            }
        }

    }
     cout<<dp[1][n-1];

     char name = 'A';
     printparas(1 , n-1 , bracket , name);
    
}
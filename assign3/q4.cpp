#include<iostream>
using namespace std;

int main(){
    int mat[6][5] = {
{0, 1, 1, 0, 1},
{1, 1, 0, 1, 0},
{0, 1, 1, 1, 0},
{1, 1, 1, 1, 0},
{1, 1, 1, 1, 1},
{0, 0, 0, 0, 0} };

int dp[6][5];

for(int i=0;i<=4;i++){
    dp[0][i] = mat[0][i];
}

for(int j=0;j<=5;j++){
    dp[j][0] = mat[j][0];
}

int maxsize = 0;

for(int i=1;i<=5;i++){
    for(int j=1;j<=4;j++){
       if(mat[i][j] == 1) {
                dp[i][j] = min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]) + 1;
                maxsize = max(maxsize, dp[i][j]);
            } else {
                dp[i][j] = 0;
            }
    }
}
cout<<maxsize;
}
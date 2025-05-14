#include<iostream>
#include<vector>
using namespace std;


int main(){
    string s1 = "AGGTAB";
    string s2 = "GXTXAYB";

     int m = s1.length();
    int n = s2.length();

    vector<vector<int> > dp(m+1, vector<int>(n+1, 0));

    

    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(s1[i-1]==s2[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else{
                dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
            }
        }
        
    }
    cout<<"length is " <<dp[m][n];


    // printing lcs 
    
    int index = dp[m][n];
    char lcs[index+1];
    lcs[index] = '\0';

    int i = m;
    int j =n;

    while(i>0 && j>0){
        if(s1[i-1]==s2[j-1]){
            lcs[index-1] = s1[i-1];
            i--;
            j--;
            index--;
        }
        else if(dp[i-1][j]>dp[i][j-1]){
            i--;
        }
        else j--;
    }

    cout<<"string is "<<lcs;
}
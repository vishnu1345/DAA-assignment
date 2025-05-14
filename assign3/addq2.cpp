#include<iostream>
#include<vector>
using namespace std;


int solve(int ind , int prev , int arr[]){

    if(ind==8){
        return 0;
    }

    int nt = solve(ind+1 , prev , arr);

    int take = 0;
    if(prev==-1 || arr[ind]>arr[prev]){
        take = 1 + solve(ind+1 , ind , arr);
    }

    return max(nt , take);
}
int main(){
    int arr[] = {10, 9, 2, 5, 3, 7, 101, 18};

    
    cout << "The length of the longest increasing subsequence is " << solve(0 , -1 , arr);
    
    return 0;
}
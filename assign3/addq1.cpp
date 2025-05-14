#include<iostream>
#include<vector>
using namespace std;

void solve(int i , int target , int arr[], vector<vector<int>> &ans , int n , vector<int> &output){

    if(target==0){
        ans.push_back(output);
        return ;
    }

    if(i==n || target<0){
        return ;
    }

  
    
    output.push_back(arr[i]);
    solve(i+1 , target-arr[i] , arr , ans , n , output);
   
    output.pop_back();
   
    
     solve(i+1 , target , arr , ans , n , output);
}

int main(){
    int arr[] = {2, 3, 7, 8, 10};
    int target = 10;
    int n = 5;

    vector<vector<int>> ans;
    vector<int> output;
    solve(0 , target , arr , ans , n , output);

    for(auto i : ans){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}
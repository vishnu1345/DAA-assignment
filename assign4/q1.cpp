#include<iostream>
#include<vector>
using namespace std;

bool place(int k , int i , vector<int> &queens){
    for(int j=0;j<k;j++){
        if(queens[j]==i || abs(queens[j]-i)==abs(j-k)){
            return false;
        }

    }
    return true;
}

void nqueens(int k , int n , vector<int> &queens , vector<vector<int>> &result){
    if(k==n){
        result.push_back(queens);
    }

    for(int i =0;i<n;i++){
        if(place(k , i , queens)){
            queens[k] = i;
            nqueens(k+1 , n , queens , result);
            queens[k] = -1;
        }
    }
}

int main(){
    int n = 4;
     vector<int> queens(n, -1);             
    vector<vector<int>> result;

    nqueens(0, n, queens, result);

    cout << "Total solutions: " << result.size() << "\n\n";
    for (const auto& sol : result) {
        for (int col : sol) {
            cout << col << " ";
        }
        cout << "\n";
    }

    return 0;
}
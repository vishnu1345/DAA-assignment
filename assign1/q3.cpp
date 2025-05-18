#include<iostream>
using namespace std;

int crosssum(vector<int> &arr , int s , int m , int e){
    int sum = 0;
    int leftsum = INT_MIN;

    for(int i = m;i>=s;i--){
        sum = sum + arr[i];
        if(sum>leftsum){
            leftsum = sum;
        }
    }

    sum = 0;
    int rightsum = INT_MIN;
    for(int i =m+1;i<=e;i++){
        sum = sum + arr[i];
        if(sum>rightsum){
            rightsum = sum;
        }
    }

    return (leftsum+rightsum);
}

int maxarr(vector<int> &arr , int s , int e){

    if(s>e){
        return INT_MIN;
    }

    if(s==e){
        return arr[s];
    }

    int m = s + (e-s)/2;

    int left = maxarr(arr , s , m);
    int right = maxarr(arr , m+1 , e);
    int cross = crosssum(arr , s , m , e);

    return max(max(left , right) , cross);
}


int maxSubarraySum(vector<int> &arr) {
    int n = arr.size();
    return maxarr(arr, 0, n - 1);
}

int main() {
    vector<int> arr = {2, 3, 4, 5, 7};
    cout << maxSubarraySum(arr);
    return 0;
}
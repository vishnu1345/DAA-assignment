#include<iostream> 
using namespace std;

int partition(vector<int> &arr , int left , int right){
    int pivot = arr[right];

    int i = left -1;

    for(int j = left;j<right;j++){
        if(arr[j]<pivot){
            i++;
            swap(arr[i] , arr[j]);
        }
    }

    swap(arr[i+1] , arr[right]);

    return i+1;
}

void quicksort(vector<int> &arr , int left , int right){
    if(left<right){
        int pi = partition(arr , left , right);

        quicksort(arr , left , pi-1);
        quicksort(arr , pi+1 , right);
    }
}

int main() {
    vector<int> arr = {10, 7, 8, 9, 1, 5};
    int n = arr.size();
    quicksort(arr, 0, n - 1);
  
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
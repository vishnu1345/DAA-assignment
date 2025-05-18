#include<iostream> 
using namespace std;

void merge(vector<int> &arr , int left , int mid , int right){
    int n1 = mid - left+1;
    int n2 = right - mid;

    vector<int> L(n1) , R(n2);

    for(int i = 0;i<n1;i++){
        L[i] = arr[left+i];
    }

    for(int i=0;i<n2;i++){
        R[i] = arr[mid+1+i];
    }

    int i =0;
    int j = 0;
    int k=left;

    while(i<n1 && j<n2){
        if(L[i]<=R[j]){
            arr[k] = L[i];
            i++;
            k++;
        }
        else{
            arr[k] = R[j];
            j++;
            k++;
        }
    }

    while(i<n1){
        arr[k] = L[i];
        i++;
        k++;
    }

    while(j<n2){
        arr[k] = R[j];
        j++;
        k++;
    }

}

void mergesort(vector<int> &arr , int left , int right){
    if(left>=right){
        return ;
    }

    int mid = left + (right-left)/2;

    mergesort(arr , left , mid);
    mergesort(arr , mid+1 , right);
    merge(arr , left , mid , right);
}

void printVector(vector<int>& arr)
{
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main(){
    vector<int> arr = { 12, 11, 13, 5, 6, 7 };
    int n = arr.size();

    cout << "Given vector is \n";
    printVector(arr);

    mergesort(arr, 0, n - 1);

    cout << "\nSorted vector is \n";
    printVector(arr);
}
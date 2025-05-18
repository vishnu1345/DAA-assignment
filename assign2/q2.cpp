#include<iostream>
#include<vector>

using namespace std;


int findPlatform(vector<int>& arr, vector<int>& dep) {
    sort(arr.begin() , arr.end());
        sort(dep.begin() , dep.end());
        
        int i = 0;
        int j = 0;
        int maxi = INT_MIN;
        int cnt = 0;
        while(i<arr.size() && j<dep.size()){
            if(arr[i]<=dep[j]){
                i++;
                cnt++;
            }
            else{
                cnt--;
                j++;
            }
            maxi = max(cnt , maxi);
        }
        
        while(i<arr.size()){
             i++;
                cnt++;
                maxi = max(cnt , maxi);
        }
        
        while(j<dep.size()){
            j++;
            cnt--;
            maxi = max(cnt , maxi);
        }
        
        return maxi;
}

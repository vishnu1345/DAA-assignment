#include<iostream>
using namespace std;

// Function to find the longest decreasing subsequence 
// to the left
int left(int prev, int idx, vector<int>& arr) {
    if (idx < 0) {
        return 0;
    }

    // Check if nums[idx] can be included 
    // in decreasing subsequence
    int include = 0;
    if (arr[idx] < arr[prev]) {
        include = 1 + left(idx, idx - 1, arr);
    }

    // Return the maximum of including 
    // or excluding nums[idx]
    return max(include, left(prev, idx - 1, arr));
}

// Function to find the longest decreasing 
// subsequence to the right
int right(int prev, int idx, vector<int>& arr) {
    if (idx >= arr.size()) {
        return 0;
    }

    // Check if nums[idx] can be included 
    // in decreasing subsequence
    int include = 0;
    if (arr[idx] < arr[prev]) {
        include = 1 + right(idx, idx + 1, arr);
    }

    // Return the maximum of including or 
    // excluding nums[idx]
    return max(include, right(prev, idx + 1, arr));
}

// Function to find the longest bitonic sequence
int LongestBitonicSequence(vector<int>& arr) {
    int maxLength = 0;

    // Iterate over potential peaks in the array
    for (int i = 1; i < arr.size() - 1; i++) {
      
        // Find the longest decreasing subsequences 
        // on both sides of arr[i]
        int leftLen = left(i, i - 1, arr);
        int rightLen = right(i, i + 1, arr);

        // Ensure both left and right subsequences are valid
        if (leftLen == 0 || rightLen == 0) {
            leftLen = 0;
            rightLen = 0;
        }

        // Update maximum bitonic sequence length
        maxLength = max(maxLength, leftLen + rightLen + 1);
    }

    // If no valid bitonic sequence, return 0
    return (maxLength < 3) ? 0 : maxLength;
}

int main() {
 
    vector<int> arr = {12, 11, 40, 5, 3, 1};

    cout << LongestBitonicSequence(arr) << endl;

    return 0;
}
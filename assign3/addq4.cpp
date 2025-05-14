#include<iostream>
using namespace std;

// Returns count of ways to color k posts
int countWays(int n, int k) {
    
    // base cases
    if (n == 1) return k;
    if (n == 2) return k*k;
    
    // Ways in which last fence 
    // is of different color.
    int cnt1 = countWays(n-1,k)*(k-1);
    
    // Ways in which last 2 fences
    // are of same color.
    int cnt2 = countWays(n-2,k)*(k-1);
    
    return cnt1 + cnt2;
}

int main() {
  
    int n = 3, k = 2;
    cout << countWays(n, k) << endl;
    return 0;
}
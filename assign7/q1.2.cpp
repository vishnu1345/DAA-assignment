#include <iostream>
#include <string>
#include<math.h>
using namespace std;

void rabinKarpMatcher(string T, string P, int d, int q) {
    int n = T.length();
    int m = P.length();
    int h = 1;

 
    h = (int)pow(d,m-1)%q;

    int p = 0;    
    int t0 = 0;    

    // Preprocessing: calculate initial hash values
    for (int i = 0; i < m; i++) {
        p = (d * p + P[i]) % q;
        t0 = (d * t0 + T[i]) % q;
    }

    // Matching phase
    for (int s = 0; s <= n - m; s++) {
        if (p == t0) {
            // If hash values match, check actual substring
            if (T.substr(s, m) == P)
                cout << "Pattern occurs with shift " << s << endl;
        }

        if (s < n - m) {
            t0 = (d * (t0 - T[s] * h) + T[s + m]) % q;

            // Handle negative t0
            if (t0 < 0)
                t0 = (t0 + q);
        }
    }
}

int main() {
    string T = "aabbcaba";
    string P = "cab";
    int d = 256; // Alphabet size (ASCII)
    int q = 101; 

    rabinKarpMatcher(T, P, d, q);
    return 0;
}

#include<iostream>
using namespace std;

void constructlps(string &p , vector<int> &lps){
    int len = 0;
    lps[0] = 0;

    int i = 1;
    
    while(i<p.length()){

        if(p[i]==p[len]){
            len++;
            lps[i] = len;
            i++;
        }
        else{

            if(len!=0){
                len = lps[len-1];
            }
            else{
                lps[i] = 0;
                i++;
            }
        }
    }
}

void search(string &T , string &P){
    int n = T.length();
    int m = P.length();

    vector<int> lps(m);
    constructlps(P , lps);

    int i =0;
    int j = 0;

    while(i<n){
        if(T[i]==P[j]){
            i++;
            j++;

            if(j==m){
                cout << "shift occured at "<<i-j<<endl;

                j = lps[j - 1];
            }
        }
        else{
            
            if(j!=0){
                j = lps[j-1];
            }
            else i++;
        }
    }
}

int main(){
     string T = "aabbcaba";
    string P = "cab";

    search(T,P);
}
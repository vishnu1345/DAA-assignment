#include<iostream>
using namespace std;

void solve(string &T , string &P){

    for(int i=0;i<=T.length()-P.length();i++){
        int j;
        for( j =0;j<P.length();j++){
            if(T[i+j]!=P[j]){
                break;
            }

            
        }
        if(j==P.length()){
                cout<<"index at "<<i<<endl;
            }
    }
}

int main(){
     string txt1 = "AABAACAADAABAABA";
    string pat1 = "AABA";
    
    solve(txt1, pat1);
}
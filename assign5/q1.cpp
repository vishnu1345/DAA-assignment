#include<iostream> 
#include <vector>
#include <algorithm>
using namespace std;

bool ishamiltonian(vector<vector<int>> &graph , vector<int> &path){
    int n = graph.size();

    for(int i =0;i<n-1;i++){
        if(graph[path[i]][path[i+1]]!=1){
            return false;
        }
    }

    if(graph[path[n-1]][path[0]]!=1){
        return false;
    }

    cout << "Hamiltonian Cycle found: ";
    for (int v : path) cout << v << " ";
    cout << path[0] << " (cycle complete)" << endl;


    return true;
}

void findhamiltonian(vector<vector<int>> &graph){
    int n = graph.size();

    vector<int> p(n);

    for(int i =0;i<n;i++){
        p[i] = i;
    }

    bool found = false;

    do{
        if(ishamiltonian(graph , p)){
            found = true;
        }
    }while(next_permutation(p.begin()+1 , p.end()));

      if (!found)
        cout << "No Hamiltonian Cycle found." << endl;
}

int main(){
    vector<vector<int>> graph = {{0, 1, 0, 1, 0},{1, 0, 1, 1, 1},{0, 1, 0, 0, 1},{1, 1, 0, 0, 1},{0, 1, 1, 1,
0}};

    findhamiltonian(graph);

}
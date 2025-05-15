#include<iostream>
using namespace std;

void findhamil(vector<vector<int>> &graph, vector<int> &path, vector<bool> &visited, int pos){
    int n = graph.size();

    if(pos==n){
        if(graph[path[n-1]][path[0]]==1){
            cout << "Hamiltonian Cycle found: ";
            for (int v : path) cout << v << " ";
            cout << path[0] << " (cycle complete)" << endl;
        }
        return ;
    }

    for(int v = 1;v<n;v++){
        if(!visited[v] && graph[path[pos-1]][v]==1){
            path[pos] = v;
            visited[v] = true;
            findhamil(graph , path , visited , pos+1);
            visited[v] = false;
        }
    }
}

int main(){
     vector<vector<int>> graph = {
        {0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 0}
    };

    int n = graph.size();
    vector<int> path(n, -1);
    vector<bool> visited(n, false);

    path[0] = 0;
    visited[0] = true;

    findhamil(graph, path, visited, 1);
    return 0;
}
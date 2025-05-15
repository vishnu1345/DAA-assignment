#include<iostream>
using namespace std;

void dfs(int node, vector<vector<int>> &adj , vector<bool> &visited , stack<int> &st){
    visited[node] = true;

    for(auto i:adj[node]){
        if(!visited[i]){
            dfs(i , adj , visited , st);
        }
    }

    st.push(node);
}

int main(){
     int V = 6;

  
    vector<vector<int>> edges = {
        {0, 1}, {1, 2}, {2, 3},
        {4, 5}, {5, 1}, {5, 2}
    };

    vector<vector<int>> adj(V);
    for(auto i:edges){
        adj[i[0]].push_back(i[1]);
    }

    vector<bool> visited(V);
    stack<int> st;

    for(int i=0;i<V;i++){
        if (!visited[i]) {
            dfs(i, adj, visited, st);
        }
    }

     cout << "Topological Sort: ";
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
}
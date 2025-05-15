#include<iostream>
using namespace std;

vector<vector<int>> constructadj(vector<vector<int>> &graph , int V){
    vector<vector<int>> adj(V);

    for(auto i : graph){
        adj[i[0]].push_back(i[1]);
    }

    return adj;
}

vector<int> topological(int V , vector<vector<int>> &graph){
    vector<vector<int>> adj = constructadj(graph , V);

    vector<int> indegree(V);

    for(int i=0;i<V;i++){
        for(auto it:adj[i]){
            indegree[it]++;
        }
    }


    queue<int> q;
    for(int i=0;i<V;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }

    vector<int> result;
    while(!q.empty()){
        int front = q.front();
        q.pop();
        result.push_back(front);

        for(auto i:adj[front]){
            indegree[i]--;

            if(indegree[i]==0){
                q.push(i);
            }
        }


    }

    return result;
}

int main()
{


    int V = 6;

  
    vector<vector<int> > edges
        = {{2, 3}, {3, 1}, {4, 0},
           {4, 1}, {5, 0}, {5, 2}};

    vector<int> result = topological(V, edges);

  
    for (auto i : result) {
        cout << i << " ";
    }

    return 0;
}
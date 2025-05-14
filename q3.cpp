#include <iostream>
#include <vector>
using namespace std;

bool isSafe(int vertex, int color, const vector<vector<int>>& graph, const vector<int>& colors) {
    for (int neighbor = 0; neighbor < graph.size(); neighbor++) {
        if (graph[vertex][neighbor] == 1 && colors[neighbor] == color) {
            return false;
        }
    }
    return true;
}

void graphColoring(int vertex, int n, int m, const vector<vector<int>>& graph, vector<int>& colors, vector<vector<int>>& solutions) {
    if (vertex == n) {
        solutions.push_back(colors);
        return;
    }

    for (int c = 1; c <= m; c++) {
        if (isSafe(vertex, c, graph, colors)) {
            colors[vertex] = c;
            graphColoring(vertex + 1, n, m, graph, colors, solutions);
            colors[vertex] = 0; // backtrack
        }
    }
}

int main() {
    int n, m; // n = number of vertices, m = number of colors
    cout << "Enter number of vertices: ";
    cin >> n;
    cout << "Enter number of colors: ";
    cin >> m;

    vector<vector<int>> graph(n, vector<int>(n));
    cout << "Enter adjacency matrix:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> graph[i][j];

    vector<int> colors(n, 0);
    vector<vector<int>> solutions;

    graphColoring(0, n, m, graph, colors, solutions);

    if (solutions.empty()) {
        cout << "No solution exists.\n";
    } else {
        cout << "Solutions found: " << solutions.size() << "\n";
        for (const auto& sol : solutions) {
            for (int c : sol)
                cout << c << " ";
            cout << "\n";
        }
    }

    return 0;
}

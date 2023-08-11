#include <iostream>
#include <vector>
#include <stack>
using namespace std;
class Graph {
private:
    int V; // Number of vertices
    vector<vector<int>> adj; // Adjacency list

public:
    Graph(int v) : V(v), adj(v) {}

    void addEdge(int v, int w) {
        adj[v].push_back(w);
    }

    void topologicalSortUtil(int v, vector<bool>& visited, stack<int>& stack) {
        visited[v] = true;

        for (int neighbor : adj[v]) {
            if (!visited[neighbor]) {
                topologicalSortUtil(neighbor, visited, stack);
            }
        }

        stack.push(v);
    }

    void topologicalSort() {
        vector<bool> visited(V, false);
        stack<int> stack;

        for (int i = 0; i < V; ++i) {
            if (!visited[i]) {
                topologicalSortUtil(i, visited, stack);
            }
        }

        cout << "Topological Sorting: ";
        while (!stack.empty()) {
            cout << stack.top() << " ";
            stack.pop();
        }
    }
};

int main() {
    Graph g(6);

    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);

    cout << "Topological Sort order: ";
    g.topologicalSort();

    return 0;
}

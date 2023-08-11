#include <iostream>
#include <vector>
#include <stack>
using namespace std;
class Graph {
private:
    int V;
    vector<vector<int>> adj;

public:
    Graph(int v) : V(v), adj(v) {}

    void addEdge(int v, int w) {
        adj[v].push_back(w);
    }

    void DFS(int start) {
        vector<bool> visited(V, false);
        stack<int> stack;

        visited[start] = true;
        stack.push(start);

        while (!stack.empty()) {
            int current = stack.top();
            stack.pop();
            cout << current << " ";

            for (int neighbor : adj[current]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    stack.push(neighbor);
                }
            }
        }
    }
};

int main() {
    Graph g(6);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(3, 5);

    cout << "DFS starting from vertex 0: ";
    g.DFS(0);

    return 0;
}

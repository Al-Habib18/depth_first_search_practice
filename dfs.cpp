#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Graph {
public:
    int vertices;
    vector<vector<int>> adjacencyList;

    Graph(int v) {
        vertices = v;
        adjacencyList.resize(vertices);
    }

    void addEdge(int u, int v) {
        adjacencyList[u].push_back(v);
        adjacencyList[v].push_back(u); // For undirected graph
    }

    void dfs(int startVertex) {
        vector<bool> visited(vertices, false);
        stack<int> s;

        visited[startVertex] = true;
        s.push(startVertex);

        while (!s.empty()) {
            int currentVertex = s.top();
            cout << currentVertex << " ";
            s.pop();

            for (int adjacentVertex : adjacencyList[currentVertex]) {
                if (!visited[adjacentVertex]) {
                    visited[adjacentVertex] = true;
                    s.push(adjacentVertex);
                }
            }
        }
    }
};

int main() {
    Graph graph(6); // Create a graph with 6 vertices

    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(1, 4);
    graph.addEdge(2, 4);
    graph.addEdge(3, 5);
    graph.addEdge(4, 5);

    cout << "DFS starting from vertex 0: ";
    graph.dfs(0);
    cout << endl ;

    return 0;
}

#include <iostream>
#include <vector>

using namespace std;

/**
 * Performs a Depth-First Search (DFS) on a graph starting from a given vertex.
 *
 * Parameters:
 * - graph: An adjacency list representation of the graph, where graph[u] contains a list of neighbors of vertex u.
 * - vertex: The current vertex being explored.
 * - visited: A boolean vector tracking which vertices have been visited.
 * - order: A vector storing the order in which vertices are visited during DFS.
 */
void DFS(const vector<vector<int>>& graph, int vertex, vector<bool>& visited, vector<int>& order) {
    visited[vertex] = true; // Mark the vertex as visited
    order.push_back(vertex); // Add the vertex to the order of visited vertices

    // For all neighbors of the current vertex
    for (int neighbor : graph[vertex]) {
        if (!visited[neighbor]) {
            DFS(graph, neighbor, visited, order); // Recursively call DFS for the unvisited neighbor
        }
    }
}

int main() {
    // Example graph represented as an adjacency list
    vector<vector<int>> graph = {
        {1, 2}, // Neighbors of vertex 0
        {0, 3, 4}, // Neighbors of vertex 1
        {0, 4}, // Neighbors of vertex 2
        {1, 5}, // Neighbors of vertex 3
        {1, 2, 5}, // Neighbors of vertex 4
        {3, 4} // Neighbors of vertex 5
    };

    int startVertex = 0; // Starting vertex
    vector<bool> visited(graph.size(), false); // Vector to keep track of visited vertices
    vector<int> dfsOrder; // Order of visited vertices

    DFS(graph, startVertex, visited, dfsOrder);

    cout << "Order of visited vertices: ";
    for (int vertex : dfsOrder) {
        cout << vertex << " ";
    }
    cout << endl;

    return 0;
}

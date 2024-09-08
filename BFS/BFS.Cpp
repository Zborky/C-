#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/**
 * This function performs a Breadth-First Search (BFS) on a graph starting from a given vertex and
 * returns the order in which vertices are visited.
 *
 * Parameters:
 * - graph: An adjacency list representation of the graph, where graph[u] contains a list of neighbors of vertex u.
 * - start: The starting vertex for the BFS.
 *
 * Return value:
 * - A vector of vertices in the order they were visited by BFS.
 */
vector<int> BFS(const vector<vector<int>>& graph, int start) {
    vector<bool> visited(graph.size(), false); // Keep track of visited vertices
    vector<int> order; // Store the order in which vertices are visited
    queue<int> q; // Use a queue for BFS

    visited[start] = true; // Mark the starting vertex as visited
    q.push(start); // Enqueue the starting vertex

    while (!q.empty()) {
        int vertex = q.front(); // Dequeue a vertex
        q.pop();
        order.push_back(vertex); // Add the vertex to the order

        // Explore all neighbors of the current vertex
        for (int neighbor : graph[vertex]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true; // Mark the neighbor as visited
                q.push(neighbor); // Enqueue the neighbor
            }
        }
    }

    return order;
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

    // Starting vertex
    int startVertex = 0;

    vector<int> bfsOrder = BFS(graph, startVertex);

    cout << "Order of visited vertices: ";
    for (int vertex : bfsOrder) {
        cout << vertex << " ";
    }
    cout << endl;

    return 0;
}

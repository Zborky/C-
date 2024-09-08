#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <limits>
#include <queue>
#include <string>
#include <sstream> // For using std::stringstream

using namespace std;

const int INF = numeric_limits<int>::max(); // Represents infinity for unreachable nodes
const int NUM_STOPS = 23; // Number of stops from A to W

/**
 * The Graph class represents a transportation network using a graph structure.
 */
class Graph {
    int numStops; // Number of stops in the transportation network
    vector<vector<pair<int, int>>> adjList; // Adjacency list for each stop (stop, travel time)

public:
    /**
     * Graph constructor.
     * @param numStops The number of stops in the transportation network.
     */
    Graph(int numStops) {
        this->numStops = numStops;
        adjList.resize(numStops); // Resize adjacency list to the number of stops
    }

    /**
     * Adds an edge between two stops with a given travel time.
     * @param u First stop.
     * @param v Second stop.
     * @param time Travel time between the stops.
     */
    void addEdge(int u, int v, int time) {
        adjList[u].emplace_back(v, time);  // Add an edge from stop `u` to stop `v`
        adjList[v].emplace_back(u, time);  // Add an edge from stop `v` to stop `u` (undirected graph)
    }

    /**
     * Dijkstra's algorithm to find the shortest paths from a starting stop.
     * @param start The starting stop.
     * @return A vector of the shortest times to all other stops.
     */
    vector<int> dijkstra(int start) {
        vector<int> dist(numStops, INF); // Initialize distances to infinity
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq; // Min-heap priority queue

        dist[start] = 0; // Distance to the starting stop is 0
        pq.emplace(0, start); // Push the starting stop to the priority queue

        while (!pq.empty()) {
            int currTime = pq.top().first; // Get the current time
            int u = pq.top().second;       // Get the current stop
            pq.pop();

            if (currTime > dist[u]) continue; // Skip if we already found a better path

            for (auto &neighbor : adjList[u]) {
                int v = neighbor.first;  // Neighboring stop
                int time = neighbor.second; // Time to reach the neighboring stop

                // If a shorter path is found
                if (dist[u] + time < dist[v]) {
                    dist[v] = dist[u] + time;  // Update the distance
                    pq.emplace(dist[v], v);    // Push the new distance to the queue
                }
            }
        }

        return dist; // Return the distance vector
    }

    /**
     * Finds the shortest path through multiple specified stops.
     * @param stops A vector of stops to be visited in the specified order.
     * @return The shortest time needed to travel through all the stops.
     */
    int shortestPathWithMultipleStops(vector<char> stops) {
        int totalDistance = 0; // Total time for the route

        // Iterate through each consecutive pair of stops
        for (size_t i = 0; i < stops.size() - 1; ++i) {
            int u = stops[i] - 'A';    // Convert char stop to integer (A = 0)
            int v = stops[i + 1] - 'A'; // Convert next char stop to integer

            vector<int> dist = dijkstra(u); // Get shortest distances from stop `u`
            if (dist[v] == INF) { // If the destination stop is unreachable
                return INF; // Return infinity (unreachable)
            }
            totalDistance += dist[v]; // Add the shortest distance to total
        }

        return totalDistance; // Return the total distance for the entire route
    }
};

int main() {
    Graph g(NUM_STOPS); // Create a graph with the predefined number of stops

    // Reading the number of edges (routes between stops)
    cout << "Enter the number of edges: ";
    int numEdges;
    cin >> numEdges;

    // Reading the edges and travel times between stops
    cout << "Enter edges in the format 'A B 5', where A and B are stops, and 5 is the time (in minutes):\n";
    for (int i = 0; i < numEdges; ++i) {
        char from, to;
        int time;
        cin >> from >> to >> time;

        int u = from - 'A';  // Convert char stop to integer
        int v = to - 'A';    // Convert char stop to integer
        g.addEdge(u, v, time); // Add the edge with the specified travel time
    }

    // Reading the user's desired route
    string input;
    cout << "Enter the route you want to travel (e.g., ABCFW): ";
    cin >> input;

    // Validate the input (only letters from A to W are allowed)
    for (char c : input) {
        if (c < 'A' || c > 'W') {
            cout << "Invalid input. Use letters from A to W." << endl;
            return 1;
        }
    }

    vector<char> stops(input.begin(), input.end()); // Convert the input string to a vector of chars

    int totalDistance = g.shortestPathWithMultipleStops(stops); // Get the shortest path for the specified route

    if (totalDistance == INF) { // If the route is not possible
        cout << "It is not possible to travel through all the specified stops." << endl;
    } else {
        cout << "The shortest route through all stops takes " << totalDistance << " minutes." << endl;
    }

    return 0;
}

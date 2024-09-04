#include <iostream>
#include <vector>

using namespace std;

/**
 * Funkcia DFS prehľadá graf do hĺbky z východiskového vrcholu.
 * 
 * Parametre:
 * - graph: Adjacency list reprezentácia grafu, kde graph[u] obsahuje zoznam susedov vrcholu u.
 * - vertex: Aktuálny vrchol, ktorý sa prehľadáva.
 * - visited: Vektor boolean hodnôt, ktorý sleduje, ktoré vrcholy boli navštívené.
 * - order: Vektor vrcholov v poradí, v akom boli navštívené DFS.
 */
void DFS(const vector<vector<int>>& graph, int vertex, vector<bool>& visited, vector<int>& order) {
    visited[vertex] = true; // Označi vrchol ako navštívený
    order.push_back(vertex); // Pridá vrchol do poradia navštívených vrcholov

    // Pre všetkých susedov aktuálneho vrcholu
    for (int neighbor : graph[vertex]) {
        if (!visited[neighbor]) {
            DFS(graph, neighbor, visited, order); // Rekurzívne zavolá DFS pre nenavštíveného suseda
        }
    }
}

int main() {
    // Príklad grafu reprezentovaného adjacency listom
    vector<vector<int>> graph = {
        {1, 2},    // susedia vrcholu 0
        {0, 3, 4}, // susedia vrcholu 1
        {0, 4},    // susedia vrcholu 2
        {1, 5},    // susedia vrcholu 3
        {1, 2, 5}, // susedia vrcholu 4
        {3, 4}     // susedia vrcholu 5
    };

    int startVertex = 0; // Východiskový vrchol
    vector<bool> visited(graph.size(), false); // Vektor, ktorý sleduje, či bol vrchol navštívený
    vector<int> dfsOrder; // Poradie navštívených vrcholov

    DFS(graph, startVertex, visited, dfsOrder);

    cout << "Poradie navštívených vrcholov: ";
    for (int vertex : dfsOrder) {
        cout << vertex << " ";
    }
    cout << endl;

    return 0;
}
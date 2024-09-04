#include<iostream>
#include<vector>
#include<queue>

using namespace std;

/**
 * Funkcia BFS prehľadá graf do šírky z východiskového vrcholu a vráti poradie prehľadávaných vrcholov.
 * 
 * Parametre:
 * - graph: Adjacency list reprezentácia grafu, kde graph[u] obsahuje zoznam susedov vrcholu u.
 * - start: Východiskový vrchol pre BFS.
 * 
 * Návratová hodnota:
 * - Vektor vrcholov v poradí, v akom boli navštívené BFS.
 */

vector<int> BFS(const vector<vector<int>>& graph, int start){
    vector<int> visited(graph.size(),false);
    vector<int> order;
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while(!q.empty()){
        int vertex = q.front();
        q.pop();
        order.push_back(vertex);

        for(int neighbor : graph[vertex]){
            if(!visited[neighbor]){
                visited[neighbor] = true;
                q.push(neighbor);

            }

        }

    }
    return order;

}

int main(){
    // Príklad grafu reprezentovaného adjacency listom
    vector<vector<int>> graph = {
        {1, 2},    // susedia vrcholu 0
        {0, 3, 4}, // susedia vrcholu 1
        {0, 4},    // susedia vrcholu 2
        {1, 5},    // susedia vrcholu 3
        {1, 2, 5}, // susedia vrcholu 4
        {3, 4}     // susedia vrcholu 5
    };

    //Vychodiskovy vrchol

    int startVertex = 0;

    vector<int> bfsOrder = BFS(graph, startVertex);

    cout << "Poradie navstivenych vrcholov ";

    for(int vertex : bfsOrder){
        cout << vertex << "";

    }
        cout << endl;
        return 0;

}
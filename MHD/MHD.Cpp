#include <iostream>
#include <vector>
#include <limits>
#include <queue>
#include <string>
#include <sstream> // Pre použitie std::stringstream

using namespace std;

const int INF = numeric_limits<int>::max();
const int NUM_STOPS = 23; // Počet zastávok od A po W

/**
 * Trieda Graph reprezentuje dopravnú sieť pomocou grafu.
 */
class Graph {
    int numStops; // Počet zastávok v dopravnej sieti
    vector<vector<pair<int, int>>> adjList; // Zoznam susedov pre každú zastávku (zastávka, čas)

public:
    /**
     * Konštruktor Graph.
     * @param numStops Počet zastávok v dopravnej sieti.
     */
    Graph(int numStops) {
        this->numStops = numStops;
        adjList.resize(numStops);
    }

    /**
     * Pridá spoj medzi dvoma zastávkami s konkrétnym časom.
     * @param u Prvá zastávka.
     * @param v Druhá zastávka.
     * @param time Čas prekonania medzi zastávkami.
     */
    void addEdge(int u, int v, int time) {
        adjList[u].emplace_back(v, time);
        adjList[v].emplace_back(u, time); // Ak je graf neorientovaný
    }

    /**
     * Implementácia Dijkstraovho algoritmu na nájdenie najkratších trás z východzej zastávky.
     * @param start Východzia zastávka.
     * @return Vektor najkratších časov do všetkých ostatných zastávok.
     */
    vector<int> dijkstra(int start) {
        vector<int> dist(numStops, INF);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

        dist[start] = 0;
        pq.emplace(0, start);

        while (!pq.empty()) {
            int currTime = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            if (currTime > dist[u]) continue;

            for (auto &neighbor : adjList[u]) {
                int v = neighbor.first;
                int time = neighbor.second;

                if (dist[u] + time < dist[v]) {
                    dist[v] = dist[u] + time;
                    pq.emplace(dist[v], v);
                }
            }
        }

        return dist;
    }

    /**
     * Nájde najkratšiu trasu cez viacero zadaných zastávok.
     * @param stops Vektor zastávok, ktoré musia byť navštívené v zadanom poradí.
     * @return Najkratší čas potrebný na prekonanie trasy cez všetky zastávky.
     */
    int shortestPathWithMultipleStops(vector<char> stops) {
        int totalDistance = 0;

        for (size_t i = 0; i < stops.size() - 1; ++i) {
            int u = stops[i] - 'A';
            int v = stops[i + 1] - 'A';

            vector<int> dist = dijkstra(u);
            if (dist[v] == INF) {
                return INF; // Nie je možné dosiahnuť cieľ
            }
            totalDistance += dist[v];
        }

        return totalDistance;
    }
};

int main() {
    Graph g(NUM_STOPS);

    // Načítanie hrán a časov medzi nimi
    cout << "Zadajte počet hrán: ";
    int numEdges;
    cin >> numEdges;

    cout << "Zadajte hrany vo formáte 'A B 5', kde A a B sú zastávky a 5 je čas (v minútach):\n";
    for (int i = 0; i < numEdges; ++i) {
        char from, to;
        int time;
        cin >> from >> to >> time;

        int u = from - 'A';
        int v = to - 'A';
        g.addEdge(u, v, time);
    }

    // Načítanie vlastnej trasy od používateľa
    string input;
    cout << "Zadajte trasu, ktorú chcete prejsť (napr. ABCFW): ";
    cin >> input;

    // Overenie, že vstup je platný (len písmená od A po W)
    for (char c : input) {
        if (c < 'A' || c > 'W') {
            cout << "Neplatný vstup. Použite písmená od A po W." << endl;
            return 1;
        }
    }

    vector<char> stops(input.begin(), input.end()); // Prevedie vstup na vektor charov

    int totalDistance = g.shortestPathWithMultipleStops(stops);

    if (totalDistance == INF) {
        cout << "Nie je možné prejsť všetky zadané zastávky." << endl;
    } else {
        cout << "Najkratšia cesta pre všetky zastávky trvá " << totalDistance << " minút." << endl;
    }

    return 0;
}

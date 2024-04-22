#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

// Define a structure to represent edges in the graph
struct Edge {
    int destination;
    int weight;
};

// Define a structure to represent a vertex in the graph
struct Vertex {
    vector<Edge> neighbors;
};

// Function to perform Dijkstra's algorithm
void dijkstra(vector<Vertex>& graph, int src) {
    int V = graph.size(); // Number of vertices in the graph
    vector<int> dist(V, INT_MAX); // Array to store distances
    dist[src] = 0; // Distance from source to itself is 0

    // Priority queue to store vertices with their distances
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src}); // Push source vertex into the queue

    // Dijkstra's algorithm
    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        // Visit each neighbor of u
        for (const Edge& edge : graph[u].neighbors) {
            int v = edge.destination;
            int w = edge.weight;

            // Relaxation
            if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    // Print the distances
    cout << "Vertex \t Distance from Source" << endl;
    for (int i = 0; i < V; ++i) {
        cout << i << " \t\t\t\t" << dist[i] << endl;
    }
}

int main() {
    // Let us create the example graph
    int V = 9;
    vector<Vertex> graph(V);

    // Adding edges to the graph
    graph[0].neighbors.push_back({1, 4});
    graph[0].neighbors.push_back({7, 8});
    graph[1].neighbors.push_back({0, 4});
    graph[1].neighbors.push_back({2, 8});
    graph[1].neighbors.push_back({7, 11});
    graph[2].neighbors.push_back({1, 8});
    graph[2].neighbors.push_back({3, 7});
    graph[2].neighbors.push_back({5, 4});
    graph[2].neighbors.push_back({8, 2});
    graph[3].neighbors.push_back({2, 7});
    graph[3].neighbors.push_back({4, 9});
    graph[3].neighbors.push_back({5, 14});
    graph[4].neighbors.push_back({3, 9});
    graph[4].neighbors.push_back({5, 10});
    graph[5].neighbors.push_back({2, 4});
    graph[5].neighbors.push_back({3, 14});
    graph[5].neighbors.push_back({4, 10});
    graph[5].neighbors.push_back({6, 2});
    graph[6].neighbors.push_back({5, 2});
    graph[6].neighbors.push_back({7, 1});
    graph[6].neighbors.push_back({8, 6});
    graph[7].neighbors.push_back({0, 8});
    graph[7].neighbors.push_back({1, 11});
    graph[7].neighbors.push_back({6, 1});
    graph[7].neighbors.push_back({8, 7});
    graph[8].neighbors.push_back({2, 2});
    graph[8].neighbors.push_back({6, 6});
    graph[8].neighbors.push_back({7, 7});

    // Function call
    dijkstra(graph, 0);

    return 0;
}

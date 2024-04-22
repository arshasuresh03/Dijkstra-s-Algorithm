# Dijkstra-s-Algorithm
Given a weighted graph and a source vertex in the graph, find the shortest paths from the source to all the other vertices in the given graph.

Dijkstra's algorithm is a fundamental method used to find the shortest paths from a source vertex to all other vertices in a weighted graph. It's a core algorithm in the domain of graph theory and plays a crucial role in various applications such as network routing protocols, transportation networks, and many others.

Here's a breakdown of the components involved in Dijkstra's algorithm:

-Graph Representation:
The graph is represented as a collection of vertices and edges.
Each vertex typically contains a list of its neighboring vertices along with the associated edge weights. This representation can be done using adjacency lists or matrices.

-Initialization:
Initialize an array dist[] to store the shortest distances from the source vertex to all other vertices.
Initialize a set sptSet[] (shortest path tree set) to keep track of vertices included in the shortest path tree.

-Main Loop:
The algorithm iteratively selects the vertex with the minimum distance (not yet included in sptSet[]) from the source vertex.
Once a vertex u is selected, it is marked as processed by adding it to the sptSet[].
Then, update the distances of its neighboring vertices (v) if a shorter path to v is found through u.

-Relaxation:
For each neighboring vertex v of the selected vertex u, update its distance if the sum of the distance to u and the weight of the edge from u to v is smaller than the current distance to v.
This step ensures that the algorithm progressively finds shorter paths as it explores the graph.

-Termination:
Repeat the main loop until all vertices are included in the sptSet[].

Output:
After the algorithm terminates, the array dist[] contains the shortest distances from the source vertex to all other vertices.
These distances represent the lengths of the shortest paths from the source vertex to each destination vertex.

DEMO:

![image](https://github.com/arshasuresh03/Dijkstra-s-Algorithm/assets/160167081/d93e5f38-4211-4651-a578-1ebf4ff16205)

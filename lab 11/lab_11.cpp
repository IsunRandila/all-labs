#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

typedef pair<int, int> pii; 

//addind an edge
void addEdge(vector<vector<pii>>& graph, int u, int v, int weight) {
    graph[u].push_back(make_pair(v, weight));
    graph[v].push_back(make_pair(u, weight));
}

// Prim's algorithm to find the minimum spanning tree
void primMST(vector<vector<pii>>& graph, int startNode) {
    int numNodes = graph.size();
    vector<int> key(numNodes, INT_MAX); 
    vector<bool> mstSet(numNodes, false); 
    vector<int> parent(numNodes, -1); 

    //  a priority queue to store vertices with their key values
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    // Start with the given startNode
    
    pq.push(make_pair(0, startNode));
    key[startNode] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        // Include the picked vertex in the MST
        // make it True
        mstSet[u] = true;

        // Traverse all adjacent vertices of u
        for (auto& neighbor : graph[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;

            // If v is not yet included in MST and the weight of the edge (u,v) is 
            // smaller than the current key of v
            // according to the algorithm
            if (!mstSet[v] && weight < key[v]) {
                key[v] = weight;
                parent[v] = u;
                pq.push(make_pair(key[v], v));
            }
        }
    }

    // Print the  MST
    cout << "Edge \tWeight" << endl;
    for (int i = 1; i < numNodes; ++i) {
        cout << parent[i] << "  " << i << "\t" << key[i] << endl;
    }
}

int main() {
    int numNodes = 6; // Number of nodes in the graph
    vector<vector<pii>> graph(numNodes); // Adjacency list to represent the graph

    // Adding edges to the graph
     addEdge(graph, 0, 1, 3);
    addEdge(graph, 0, 5, 1);
    addEdge(graph, 1, 2, 2);
    addEdge(graph, 1, 3, 1);
    addEdge(graph, 1, 4, 10);
    addEdge(graph, 2, 5, 5);
    addEdge(graph, 2, 3, 3);
    addEdge(graph, 3, 4, 5);
    addEdge(graph, 4, 5, 4);

    int startNode = 0; 

    primMST(graph, startNode);

    return 0;
}
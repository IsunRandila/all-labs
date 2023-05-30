#include <iostream>
#include <limits>
using namespace std;

#define V 6 // Number of vertices

// Function to find the city with the minimum distance value
int minDistance(int dist[], bool visited[])
{
    int minDist = numeric_limits<int>::max();
    int minIndex;

    for (int v = 0; v < V; ++v)
    {
        if (visited[v] == false && dist[v] <= minDist)
        {
            minDist = dist[v];
            minIndex = v;
        }
    }

    return minIndex;
}

void print(int dist[],int source)
{
    cout << "source node: " << source << "\n";
    int sum = 0;
    for (int i = 0; i < V; ++i)
    {
        cout << "City " << i << ": " << dist[i] << endl;
        sum += dist[i];
    }
    int average_time;
    average_time = sum/5;
    cout << average_time <<"\n"; ;
}

// Dijkstra's algorithm 
void dijkstra(int graph[V][V], int source)
{
    int dist[V];
    bool visited[V];

    // Initialize distances and visited array
    for (int i = 0; i < V; ++i)
    {
        dist[i] = numeric_limits<int>::max();
        visited[i] = false;
    }

    // Distance of source node from itself is  0
    dist[source] = 0;

    // Find shortest path for all vertices
    for (int count = 0; count < V - 1; ++count)
    {
        int u = minDistance(dist, visited);

        // marking the selected nodes
        visited[u] = true;

        // Update distance values of adjacent vertices
        for (int v = 0; v < V; ++v)
        {
            if (!visited[v] && graph[u][v] != 0 && dist[u] != numeric_limits<int>::max() &&
                dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    print(dist, source);
}

int main()
{
    // weighted adjacency matrix
    int graph[V][V] = {
        {0, 10, 0, 0, 15, 5},
        {10, 0, 10, 30, 0, 0},
        {0, 10, 0, 12, 5, 0},
        {0, 30, 12, 0, 0, 20},
        {15, 0, 5, 0, 0, 0},
        {5, 0, 0, 20, 0, 0}
    };

    int source;
    
    for (int i = 0; i < 6; ++i){
    dijkstra(graph, i) ;
    }

    return 0;
}
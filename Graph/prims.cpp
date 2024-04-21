#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Graph
{
private:
    int vertices;
    vector<vector<int> > adjacencyMatrix;

public:
    Graph(int V) : vertices(V), adjacencyMatrix(V, vector<int>(V, 0)) {}

    void addEdge(int u, int v, int weight)
    {
        adjacencyMatrix[u][v] = weight;
        adjacencyMatrix[v][u] = weight;
    }

    int findMinVertex(vector<int> &weights, vector<bool> &included)
    {
        int minVertex = -1;
        int minWeight = INT_MAX;

        for (int v = 0; v < vertices; ++v)
        {
            if (!included[v] && weights[v] < minWeight)
            {
                minVertex = v;
                minWeight = weights[v];
            }
        }

        return minVertex;
    }

    void primMST()
    {
        vector<int> parent(vertices, -1);
        vector<int> weights(vertices, INT_MAX);
        vector<bool> included(vertices, false);

        weights[0] = 0; // Start with vertex 0

        for (int i = 0; i < vertices - 1; ++i)
        {
            int minVertex = findMinVertex(weights, included);
            included[minVertex] = true;

            for (int v = 0; v < vertices; ++v)
            {
                if (adjacencyMatrix[minVertex][v] != 0 && !included[v] && adjacencyMatrix[minVertex][v] < weights[v])
                {
                    parent[v] = minVertex;
                    weights[v] = adjacencyMatrix[minVertex][v];
                }
            }
        }

        cout << "Minimum Cost Spanning Tree edges:\n";
        for (int i = 1; i < vertices; ++i)
        {
            cout << "Edge: " << parent[i] << " - " << i << " Weight: " << weights[i] << "\n";
        }
    }
};

int main()
{
    int V, E;
    cout << "Enter the number of vertices and edges: ";
    cin >> V >> E;

    Graph graph(V);

    cout << "Enter " << E << " edges and their weights (format: u v weight):\n";
    for (int i = 0; i < E; ++i)
    {
        int u, v, weight;
        cin >> u >> v >> weight;
        graph.addEdge(u, v, weight);
    }

    graph.primMST();

    return 0;
}

#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

class Graph
{
private:
    int vertices;
    vector<vector<int> > adjacencyList;

public:
    Graph(int V) : vertices(V), adjacencyList(V) {}

    void addEdge(int u, int v)
    {
        adjacencyList[u].push_back(v);
        adjacencyList[v].push_back(u);
    }

    void BFS(int startVertex)
    {
        vector<bool> visited(vertices, false);
        queue<int> bfsQueue;

        visited[startVertex] = true;
        bfsQueue.push(startVertex);

        while (!bfsQueue.empty())
        {
            int currentVertex = bfsQueue.front();
            bfsQueue.pop();
            cout << currentVertex << " ";

            for (int neighbor : adjacencyList[currentVertex])
            {
                if (!visited[neighbor])
                {
                    visited[neighbor] = true;
                    bfsQueue.push(neighbor);
                }
            }
        }
    }

    void DFS(int startVertex)
    {
        vector<bool> visited(vertices, false);
        stack<int> dfsStack;

        dfsStack.push(startVertex);

        while (!dfsStack.empty())
        {
            int currentVertex = dfsStack.top();
            dfsStack.pop();

            if (!visited[currentVertex])
            {
                cout << currentVertex << " ";
                visited[currentVertex] = true;

                for (int neighbor : adjacencyList[currentVertex])
                {
                    if (!visited[neighbor])
                    {
                        dfsStack.push(neighbor);
                    }
                }
            }
        }
    }
};

int main()
{
    int V, E;
    cout << "Enter the number of vertices and edges: ";
    cin >> V >> E;

    Graph graph(V);

    cout << "Enter " << E << " edges (format: u v):\n";
    for (int i = 0; i < E; ++i)
    {
        int u, v;
        cin >> u >> v;
        graph.addEdge(u, v);
    }
    /*

1 2
1 3
2 4
2 5
4 6
4 5
3 5
5 6

    */

    // BFS
    int startVertexBFS;
    cout << "Enter the starting vertex for BFS: ";
    cin >> startVertexBFS;

    cout << "BFS starting from vertex " << startVertexBFS << ":\n";
    graph.BFS(startVertexBFS);

    // DFS
    int startVertexDFS;
    cout << "\nEnter the starting vertex for DFS: ";
    cin >> startVertexDFS;
    cout << "DFS starting from vertex " << startVertexDFS << ":\n";
    graph.DFS(startVertexDFS);

    return 0;
}

// #include <iostream>
// #include <list>
// #include <vector>
// #include <queue>
// #include <stack>
// using namespace std;

// class Graph
// {
//     int vertices;             // Number of vertices
//     list<int> *adjacencyList; // Adjacency list representation

// public:
//     Graph(int v);
//     void addEdge(int source, int destination);
//     void BFS(int startNode);
//     void DFS(int startNode);
// };

// Graph::Graph(int v)
// {
//     vertices = v;
//     adjacencyList = new list<int>[vertices];
// }

// void Graph::addEdge(int source, int destination)
// {
//     adjacencyList[source].push_back(destination);
// }

// void Graph::BFS(int startNode)
// {
//     vector<bool> visited(vertices, false); // Track visited nodes
//     queue<int> q;                          // Create a queue for BFS

//     visited[startNode] = true;
//     q.push(startNode);

//     while (!q.empty())
//     {
//         int current = q.front();
//         cout << current << " ";
//         q.pop();

//         for (int neighbor : adjacencyList[current])
//         {
//             if (!visited[neighbor])
//             {
//                 visited[neighbor] = true;
//                 q.push(neighbor);
//             }
//         }
//     }
//     cout << endl;
// }

// void Graph::DFS(int startNode)
// {
//     vector<bool> visited(vertices, false); // Track visited nodes
//     stack<int> s;                          // Create a stack for DFS

//     s.push(startNode);

//     while (!s.empty())
//     {
//         int current = s.top();
//         s.pop();

//         if (!visited[current])
//         {
//             cout << current << " ";
//             visited[current] = true;
//         }

//         for (int neighbor : adjacencyList[current])
//         {
//             if (!visited[neighbor])
//             {
//                 s.push(neighbor);
//             }
//         }
//     }
//     cout << endl;
// }

// int main()
// {
//     int numVertices, numEdges;
//     cout << "Enter the number of vertices: ";
//     cin >> numVertices;

//     Graph g(numVertices);

//     cout << "Enter the number of edges: ";
//     cin >> numEdges;

//     cout << "Enter the edges (source destination):" << endl;
//     for (int i = 0; i < numEdges; i++)
//     {
//         int source, destination;
//         cin >> source >> destination;
//         g.addEdge(source, destination);
//     }

//     int startNode;
//     cout << "Enter the starting node for BFS and DFS: ";
//     cin >> startNode;

//     cout << "BFS traversal starting from node " << startNode << ": ";
//     g.BFS(startNode);

//     cout << "DFS traversal starting from node " << startNode << ": ";
//     g.DFS(startNode);

//     return 0;
// }
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;
class Graph
{
    private:
        int vertices;
        vector <vector <int> > adjList;
    public:
        Graph(int V) : vertices(V) , adjList(V) {};

        void addEdge(int u, int v)
        {
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        void DFS(int start)
        {
            vector <bool> visited(vertices,false);
            stack <int> dfsStack;
            dfsStack.push(start);
            while(!dfsStack.empty())
            {
                int curr = dfsStack.top();
                dfsStack.pop();
                if(!visited[curr])
                {
                    cout << curr << " ";
                    visited[curr] = true;
                    for(int i : adjList[curr])
                    {
                        if(!visited[i])
                        {
                            dfsStack.push(i);
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
    int startVertexBFS;
    cout << "Enter the starting vertex for BFS: ";
    cin >> startVertexBFS;

    cout << "BFS starting from vertex " << startVertexBFS << ":\n";
    graph.DFS(startVertexBFS);
}
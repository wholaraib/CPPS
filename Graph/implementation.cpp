#include <iostream>
using namespace std;
void print(int arr[][3],int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < 3; j++) cout << arr[i][j] << " ";
        cout << endl;
    }
}
void setGraph(int arr[][3], int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < 3; j++) arr[i][j] = 0;
    }   
}
int main()
{   
    // using adjacency matrix -- O(N^2) extra space therefore not a good approach

    int n; // number of nodes
    int m; // number of edges
    cout << "Enter the number of nodes : ";
    cin >> n;
    cout << "Enter the number of edges : ";
    cin >> m;
    int graph[n][n];
    setGraph(graph,n);
    for(int i = 0; i < m; i++) // input of m lines
    {
        int u,v;
        cout << "Enter the connection of edge " << (i+1) << " : ";
        cin >> u >> v;
        graph[u][v] = 1;
        graph[v][u] = 1;
    }
    print(graph,n);

}
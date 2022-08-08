// Dfs
//i. Use stack as Recursion
//ii. visited array

#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adjList[], int src, int dest)
{
    adjList[src].push_back(dest);
    adjList[dest].push_back(src);
}

void dfs(int node, vector<int> adjList[], vector<int> &storeDfs, vector<int> &visit)
{
    storeDfs.push_back(node);
    visit[node] = 1;

    for (auto it : adjList[node])
    {
        if (visit[it] == 0)
        {
            dfs(it, adjList, storeDfs, visit);
        }
    }
}

void dfsTraversal(vector<int> adjList[], int V)
{
    vector<int> storeDfs;
    vector<int> visit(V, 0);

    for (int i = 0; i < V; i++)
    {
        if (visit[i] == 0)
        {
            dfs(i, adjList, storeDfs, visit);
        }
    }

    for (auto i = storeDfs.begin(); i != storeDfs.end(); i++)
    {
        cout << *i << " ";
    }
}

void printGraph(vector<int> adjList[], int V)
{
    for (int v = 0; v < V; v++)
    {
        cout << "Adjacency list of vertex " << v << "\n";
        cout << "head";

        for (int x : adjList[v])
        {
            cout << "->" << x;
        }
        cout << "\n";
    }
}
int main()
{
    int V = 5;
    vector<int> adjList[V];

    addEdge(adjList, 0, 1);
    addEdge(adjList, 0, 3);
    addEdge(adjList, 0, 2);
    addEdge(adjList, 2, 4);
    addEdge(adjList, 3, 4);
    addEdge(adjList, 2, 1);

    printGraph(adjList, V);

    dfsTraversal(adjList, V);

    return 0;
}
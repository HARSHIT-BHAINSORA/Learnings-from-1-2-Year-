// Graph respresentation using AdjList...

// Graph of Bidirection and unweighted graph.

#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adjList[], int src, int dest)
{
    adjList[src].push_back(dest);
    adjList[dest].push_back(src);
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

    vector<int> adjlist[V];

    addEdge(adjlist, 0, 1);
    addEdge(adjlist, 4, 1);
    addEdge(adjlist, 3, 1);
    addEdge(adjlist, 3, 4);
    addEdge(adjlist, 4, 2);
    addEdge(adjlist, 0, 2);
    addEdge(adjlist, 0, 3);

    printGraph(adjlist, V);
}
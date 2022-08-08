// direction Weighted graph

#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<pair<int, int>> adjList[], int scr, int dest, int w)
{
    adjList[scr].push_back({dest, w});
}

void printGraph(vector<pair<int, int>> adjList[], int V)
{
    int u, w;
    for (int v = 0; v < V; v++)
    {
        cout << "Node" << v << "Makes an edge with \n";
        for (auto it = adjList[v].begin(); it != adjList[v].end(); it++)
        {
            u = it->first;
            w = it->second;

            cout << "Node " << u << "With edge weight = " << w << "\n";
        }

        cout << "\n";
    }
}

int main()
{
    int V = 4;
    vector<pair<int, int>> adjList[V];

    addEdge(adjList, 0, 1, 5);
    addEdge(adjList, 0, 3, 10);
    addEdge(adjList, 1, 2, 6);
    addEdge(adjList, 2, 0, 11);
    addEdge(adjList, 3, 1, 4);

    printGraph(adjList, V);

    return 0;
}
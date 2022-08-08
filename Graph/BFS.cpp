// bfs traversal in graph

// i.visited array
// ii. Queue
// iii. Addition array

#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adjList[], int src, int dest)
{
    adjList[src].push_back(dest);
    adjList[dest].push_back(src);
}

void bfsTraversal(vector<int> adjList[], int V)
{
    vector<int> visit(V, 0); // all elemenet will become 0 now.
    vector<int> bsf[V];

    for (int i = 0; i < V; i++)
    {
        if (visit[i] == 0)
        {
            queue<int> q;
            q.push(i);
            visit[i] = 1;

            while (!q.empty())
            {
                int node = q.front();
                q.pop();
                bsf[i].push_back(node);

                for (auto it : adjList[node])
                {
                    if (visit[i] == 0)
                    {
                        q.push(it);
                        visit[it] = 1;
                    }
                }
            }
        }
    }

    for (int i = 0; i < V; i++)
    {
        for (auto it : bsf[i])
        {
            cout << it << " ";
        }
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

    bfsTraversal(adjList, V);

    return 0;
}
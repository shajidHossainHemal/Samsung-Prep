#include <bits/stdc++.h>
using namespace std;

#define MX 100
#define INF 1000000000

vector<int> adj[MX];
int weights[MX][MX], dist[MX];

void bfs(int source)
{
    queue<int> bfsQ;

    bfsQ.push(source);
    dist[source] = 0;

    while (!bfsQ.empty())
    {
        int u = bfsQ.front();
        bfsQ.pop();

        for (auto v : adj[u])
        {
            if (weights[u][v] + dist[u] < dist[v])
            {
                dist[v] = weights[u][v] + dist[u];
                bfsQ.push(v);
            }
        }
    }
}

int main()
{
    int nodes, edges, source;

    cin >> nodes >> edges;

    int from, to, cost;
    for (int i = 0; i < edges; i++)
    {
        cin >> from >> to >> cost;

        adj[from].push_back(to);
        weights[from][to] = cost;
    }

    cin >> source;

    for (int i = 0; i < MX; i++)
        dist[i] = INF;

    bfs(source);

    cout << endl;
    for (int i = 0; i < nodes; i++)
        cout << i << "th Node: " << dist[i] << endl;

    return 0;
}

/*

6 11
0 1 50
0 3 10
0 2 45
1 2 10
1 3 15
2 4 30
3 0 10
3 4 15
4 1 20
4 2 35
5 4 3
0

*/
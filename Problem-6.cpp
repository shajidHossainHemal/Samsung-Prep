#include <bits/stdc++.h>
using namespace std;

vector<int> white_nodes;
vector<int> graph[100005];
int nodes, edges;

bool isBipartite()
{
    int color[nodes], visited[nodes];

    memset(color, 0, sizeof(color));
    memset(visited, 0, sizeof(visited));

    for (int i = 0; i < nodes; i++)
    {
        if (visited[i])
            continue;

        visited[i] = 1;
        color[i] = 1;

        queue<int> bfsQ;
        bfsQ.push(i);

        while (!bfsQ.empty())
        {
            int u = bfsQ.front();

            if (color[u] == 1)
                white_nodes.push_back(u);

            bfsQ.pop();

            for (int v : graph[u])
            {
                if (!visited[v])
                {
                    visited[v] = 1;
                    color[v] = 1 - color[u];
                    bfsQ.push(v);
                }

                if (color[v] == color[u])
                    return false;
            }
        }
    }

    return true;
}

int main()
{
    // int testCase;

    // cin >> testCase;

    // while(testCase--)
    // {

    // }

    cin >> nodes >> edges;

    for (int i = 0; i < edges; i++)
    {
        int from, to;
        cin >> from >> to;

        graph[from].push_back(to);
        graph[to].push_back(from);
    }

    if (isBipartite())
    {
        cout << "The graph is bipartite." << endl;
        cout << "White colored nodes: ";
        for (int x : white_nodes)
            cout << x << " ";
        cout << endl;
    }
    else
        cout << "The graph is not bipartite." << endl;

    return 0;
}
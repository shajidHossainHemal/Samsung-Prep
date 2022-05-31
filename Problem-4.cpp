#include <bits/stdc++.h>
using namespace std;

int nodes, edges, recStack[101], last;
bool visited[101], adj[101][101], flag = true;

bool dfs(int node, int nodeCopy)
{
    visited[node] = true;

    for (int i = 0; i < nodes; i++)
    {
        if (adj[node][i])
        {
            if (i == nodeCopy)
            {
                last = node;
                return false;
            }
            if (!visited[i])
            {
                flag = flag & dfs(i, nodeCopy);
                recStack[i] = node;
            }
        }
    }
    return flag;
}

int main()
{
    // int testCases;

    // cin >> testCases;

    // while (testCases--)
    // {

    // }

    cin >> nodes >> edges;

    for (int i = 0; i < edges; i++)
    {
        int from, to;
        cin >> from >> to;
        adj[from][to] = true;
    }

    cout << endl;

    for (int i = 0; i < nodes; i++)
    {
        if (!dfs(i, i))
        {
            cout << "Cycle: ";

            int now = last;
            vector<int> backtrack;

            while (1)
            {
                backtrack.push_back(now);
                if (now == i)
                {
                    break;
                }
                now = recStack[now];
            }

            reverse(backtrack.begin(), backtrack.end());
            for (auto x : backtrack)
                cout << x << ' ';
            cout << i << endl;
        }

        // Reset Values
        flag = true;
        for (int i = 0; i < nodes; i++)
            visited[i] = false;
    }

    return 0;
}

/*

6 12
0 1
0 2
0 5
1 3
1 5
2 1
2 4
3 0
4 3
5 0
5 3
5 4

*/
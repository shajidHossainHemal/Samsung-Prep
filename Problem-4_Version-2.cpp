#include <bits/stdc++.h>
using namespace std;

vector<int> visited(101);
deque<int> cycle;
list<int> adjacency[101];

bool dfs(int node)
{
    cycle.push_back(node);

    for(auto v : adjacency[node])
    {
        if(visited[v] == 0)
        {
            visited[v] = 1;

            if(dfs(v))
                return true;
        }
        else if(visited[v] == 1)
        {
            cycle.push_back(v);
            
            return true;
        }
    }
    cycle.clear();

    return false;
}

int main()
{
    int nodes, edges;

    cin >> nodes >> edges;

    int from, to;
    for(int i = 0; i < edges; i++)
    {
        cin >> from >> to;

        from--;
        to--;
        adjacency[from].push_back(to);
    }

    bool flag = false;
    for(int i = 0; i < nodes; i++)
    {
        if(visited[i] == 0)
        {
            visited[i] = 1;

            if(dfs(i))
            {
                flag = true;
                break;
            }
        }
    }

    if(flag)
    {
        cout << cycle.size() << endl;
        
        for(auto x : cycle)
            cout << x + 1 << ' ';
        cout << endl;
    }
    else
    {
        cout << "IMPOSSIBLE" << endl;
    }

    return 0;
}
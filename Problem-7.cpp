#include <bits/stdc++.h>
using namespace std;

int adj[1000][1000];
int color[10005];
int nodes, edges;

enum Color
{
    WHITE,
    GREY,
    BLACK
};

bool dfs(int vertex)
{
    color[vertex] = GREY;

    for(int i = 0; i < nodes; i++)
    {
        if(adj[vertex][i] == 1)
        {
            if(color[i] == GREY)
                return true;
            
            if(color[i] == WHITE)
            {
                if(dfs(i))
                {
                    return true;
                }
            }
        }
    }

    color[vertex] = BLACK;

    return false;
}

int main()
{
    int testCase;

    // cin >> testCase;

    // while(testCase--)
    // {

    // }

    cin >> nodes >> edges;

    for(int i = 0; i < edges; i++)
    {
        int to, from;
        cin >> to >> from;
        adj[to][from] = 1;
    }

    bool flag = false;
    
    for(int i = 0; i < nodes; i++)
    {
        if(color[i] == WHITE)
        {
            if(dfs(i))
            {
                flag = true;
                break;
            }
        }
    }

    if(flag)
        cout << "Graph contains a cycle." << endl;
    else
        cout << "Graph doesn't contain a cycle." << endl;
    
    
    for(int i = 0; i < nodes; i++)
        color[i] = 0;
    for(int i = 0; i < nodes; i++)
        for(int j = 0; j < nodes; j++)
            adj[i][j] = 0;

    return 0;
}
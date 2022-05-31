/*

John has n tasks to do. Unfortunately, the tasks are not independent and the execution of one task is
only possible if other tasks have already been executed.

Input
The input will consist of several instances of the problem. Each instance begins with a line containing
two integers, 1 <= n <= 100 and m. n is the number of tasks (numbered from 1 to n) and m is the
number of direct precedence relations between tasks. After this, there will be m lines with two integers
i and j, representing the fact that task i must be executed before task j.
An instance with n = m = 0 will finish the input.

Output
For each instance, print a line with n integers representing the tasks in a possible order of execution.

Sample Input
5 4
1 2
2 3
1 3
1 5
0 0

Sample Output
1 4 2 5 3

*/

#include <bits/stdc++.h>
using namespace std;

#define MX 105

int nodes, edges;
list<int> adj[MX];
bool visited[MX] = {false};
vector<int> topologicalOrder;

void dfs(int u)
{
    visited[u] = true;

    for (int v : adj[u])
    {
        if (!visited[v])
            dfs(v);
    }
    topologicalOrder.push_back(u);
}

int main()
{
    while (cin >> nodes >> edges)
    {
        if (nodes == 0 and edges == 0)
            break;

        int from, to;
        for (int i = 1; i <= edges; i++)
        {
            cin >> from >> to;

            adj[from].push_back(to);
        }

        for (int i = 1; i <= nodes; i++)
        {
            if (!visited[i])
                dfs(i);
        }

        reverse(topologicalOrder.begin(), topologicalOrder.end());

        for (int x : topologicalOrder)
            cout << x << ' ';
        cout << endl;

        for (int i = 1; i <= nodes; i++)
        {
            adj[i].clear();
            visited[i] = false;
        }
        topologicalOrder.clear();
    }

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int n, answer;

int dx4[4] = {0, 0, 1, -1}, dy4[4] = {1, -1, 0, 0}; // UDRL

bool isValid(int i, int j)
{
    return (i >= 0 and i < n and j >= 0 and j < n);
}

void dfs(int x, int y, int value, int **maze, int **path, int **visited)
{
    // Base case, answer and path marking
    if (x == n - 1 and y == n - 1)
    {
        if (value >= answer)
        {
            answer = value;

            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (visited[i][j] == 1)
                        path[i][j] = 3;
                    else
                        path[i][j] = maze[i][j];
                }
            }
        }
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        int newX = x + dx4[i];
        int newY = y + dy4[i];

        if (isValid(newX, newY))
        {
            // Check for path
            if (visited[newX][newY] == 0 and maze[newX][newY] == 0)
            {
                visited[newX][newY] = 1;                     // Mark as visited
                dfs(newX, newY, value, maze, path, visited); // Again check with newX and newY
                visited[newX][newY] = 0;                     // Backtrack
            }

            // Check for jewel
            if (visited[newX][newY] == 0 and maze[newX][newY] == 2)
            {
                visited[newX][newY] = 1;                         // Mark as visited
                dfs(newX, newY, value + 1, maze, path, visited); // Again check with newX and newY with increasing value
                visited[newX][newY] = 0;                         // Backtrack
            }
        }
    }
}

void printPath(int **path)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << path[i][j] << ' ';
        }
        cout << endl;
    }
}

int main()
{
    // int testCase;

    // cin >> testCase;

    // while(testCase--)
    // {

    // }

    cin >> n;

    int **maze = new int *[n + 1]; // initialize an nxn maze
    for (int i = 0; i < n; i++)
    {
        maze[i] = new int[n + 1];
    }

    int **path = new int *[n + 1]; // initialize an nxn path
    for (int i = 0; i < n; i++)
    {
        path[i] = new int[n + 1];
    }

    int **visited = new int *[n + 1]; // initialize an nxn visited
    for (int i = 0; i < n; i++)
    {
        visited[i] = new int[n + 1];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> maze[i][j];

            visited[i][j] = 0;
            path[i][j] = 0;
        }
    }

    answer = INT_MIN;
    int x = 0, y = 0;

    visited[x][y] = 1;

    if (maze[x][y] == 2)
    {
        dfs(x, y, 1, maze, path, visited);
    }
    else
    {
        dfs(x, y, 0, maze, path, visited);
    }

    cout << "Path traversed: " << endl;
    printPath(path);
    cout << "Total jewel found: " << answer << endl;

    return 0;
}
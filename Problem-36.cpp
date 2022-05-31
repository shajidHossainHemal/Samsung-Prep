#include <bits/stdc++.h>
using namespace std;

int heightOfTheMap, widthOfTheMap, sourceX, sourceY, lengthOfTheEndoscope;
int grid[10003][10003], dist[10003][10003];
bool visited[10003][10003];

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, 1, -1};

bool isValid(int uX, int uY, int x, int y)
{
    bool isBidirectional = false;

    if(grid[x][y] == 1)
    {
        for(int i = 0; i < 4; i++)
        {
            int tempX = x + dx[i];
            int tempY = y + dy[i];

            if(tempX == uX and tempY == uY)
                isBidirectional = true;
        }
    }
    else if(grid[x][y] == 2)
    {
        for(int i = 0; i < 4; i++)
        {
            if (i == 2 or i == 3)
                continue;
            int tempX = x + dx[i];
            int tempY = y + dy[i];
            
            if(tempX == uX and tempY == uY)
                isBidirectional = true;
        }
    }
    else if (grid[x][y] == 3)
    {
        for (int i = 0; i < 4; i++)
        {
            if (i == 0 or i == 1)
                continue;
            int tempX = x + dx[i];
            int tempY = y + dy[i];

            if (tempX == uX and tempY == uY)
                isBidirectional = true;
        }
    }
    else if (grid[x][y] == 4)
    {
        for (int i = 0; i < 4; i++)
        {
            if (i == 1 or i == 3)
                continue;
            int tempX = x + dx[i];
            int tempY = y + dy[i];

            if (tempX == uX and tempY == uY)
                isBidirectional = true;
        }
    }
    else if (grid[x][y] == 5)
    {
        for (int i = 0; i < 4; i++)
        {
            if (i == 0 or i == 3)
                continue;
            int tempX = x + dx[i];
            int tempY = y + dy[i];

            if (tempX == uX and tempY == uY)
                isBidirectional = true;
        }
    }
    else if (grid[x][y] == 6)
    {
        for (int i = 0; i < 4; i++)
        {
            if (i == 0 or i == 2)
                continue;
            int tempX = x + dx[i];
            int tempY = y + dy[i];

            if (tempX == uX and tempY == uY)
                isBidirectional = true;
        }
    }
    else if (grid[x][y] == 7)
    {
        for (int i = 0; i < 4; i++)
        {
            if (i == 1 or i == 2)
                continue;
            int tempX = x + dx[i];
            int tempY = y + dy[i];

            if (tempX == uX and tempY == uY)
                isBidirectional = true;
        }
    }

    if(x >= 0 and x < heightOfTheMap and y >= 0 and y < widthOfTheMap and !visited[x][y] and grid[x][y])
        return true;
    return false;
}

void bfs(int sourceX, int sourceY)
{
    queue<pair<int, int>> q;

    q.push({sourceX, sourceY});

    dist[sourceX][sourceY] = 0;
    visited[sourceX][sourceY] = true;

    while(!q.empty())
    {
        int uX = q.front().first;
        int uY = q.front().second;

        q.pop();

        if(grid[uX][uY] == 1)
        {
            for(int i = 0; i < 4; i++)
            {
                int tempX = uX + dx[i];
                int tempY = uY + dy[i];

                if(isValid(uX, uY, tempX, tempY))
                {
                    visited[tempX][tempY] = true;
                    dist[tempX][tempY] = dist[uX][uY] + 1;

                    q.push({tempX, tempY});
                }
            }
        }
        else if (grid[uX][uY] == 2)
        {
            for (int i = 0; i < 4; i++)
            {
                if(i == 2 or i == 3)
                    continue;
                
                int tempX = uX + dx[i];
                int tempY = uY + dy[i];

                if (isValid(uX, uY, tempX, tempY))
                {
                    visited[tempX][tempY] = true;
                    dist[tempX][tempY] = dist[uX][uY] + 1;

                    q.push({tempX, tempY});
                }
            }
        }
        else if (grid[uX][uY] == 3)
        {
            for (int i = 0; i < 4; i++)
            {
                if(i == 0 or i == 1)
                    continue;
                
                int tempX = uX + dx[i];
                int tempY = uY + dy[i];

                if (isValid(uX, uY, tempX, tempY))
                {
                    visited[tempX][tempY] = true;
                    dist[tempX][tempY] = dist[uX][uY] + 1;

                    q.push({tempX, tempY});
                }
            }
        }
        else if (grid[uX][uY] == 4)
        {
            for (int i = 0; i < 4; i++)
            {
                if(i == 1 or i == 3)
                    continue;
                
                int tempX = uX + dx[i];
                int tempY = uY + dy[i];

                if (isValid(uX, uY, tempX, tempY))
                {
                    visited[tempX][tempY] = true;
                    dist[tempX][tempY] = dist[uX][uY] + 1;

                    q.push({tempX, tempY});
                }
            }
        }
        else if (grid[uX][uY] == 5)
        {
            for (int i = 0; i < 4; i++)
            {
                if(i == 0 or i == 3)
                    continue;
                
                int tempX = uX + dx[i];
                int tempY = uY + dy[i];

                if (isValid(uX, uY, tempX, tempY))
                {
                    visited[tempX][tempY] = true;
                    dist[tempX][tempY] = dist[uX][uY] + 1;

                    q.push({tempX, tempY});
                }
            }
        }
        else if (grid[uX][uY] == 6)
        {
            for (int i = 0; i < 4; i++)
            {
                if(i == 0 or i == 2)
                    continue;
                
                int tempX = uX + dx[i];
                int tempY = uY + dy[i];

                if (isValid(uX, uY, tempX, tempY))
                {
                    visited[tempX][tempY] = true;
                    dist[tempX][tempY] = dist[uX][uY] + 1;

                    q.push({tempX, tempY});
                }
            }
        }
        else if (grid[uX][uY] == 7)
        {
            for (int i = 0; i < 4; i++)
            {
                if(i == 1 or i == 2)
                    continue;
                
                int tempX = uX + dx[i];
                int tempY = uY + dy[i];

                if (isValid(uX, uY, tempX, tempY))
                {
                    visited[tempX][tempY] = true;
                    dist[tempX][tempY] = dist[uX][uY] + 1;

                    q.push({tempX, tempY});
                }
            }
        }
    }
}

void reset()
{
    for(int i = 0; i < heightOfTheMap; i++)
    {
        for(int j = 0; j < widthOfTheMap; j++)
        {
            dist[i][j] = 0;
            visited[i][j] = false;
        }
    }
}

int main()
{
    // int testCase;

    // cin >> testCase;

    // while(testCase--)
    // {

    // }

    cin >> heightOfTheMap >> widthOfTheMap >> sourceX >> sourceY >> lengthOfTheEndoscope;

    for(int i = 0; i < heightOfTheMap; i++)
    {
        for(int j = 0; j < widthOfTheMap; j++)
        {
            cin >> grid[i][j];
        }
    }

    bfs(sourceX, sourceY);
    
    int answer = 0;

    for(int i = 0; i < heightOfTheMap; i++)
    {
        for(int j = 0; j < widthOfTheMap; j++)
        {
            if(grid[i][j] > 0)
            {
                if(dist[i][j] < lengthOfTheEndoscope)
                    answer++;
            }
        }
    }

    cout << answer << endl;
    reset();

    return 0;
}

/*

5 5 0 0 3
1 2 0 3 5
7 1 0 0 3
4 6 7 2 3
1 2 3 4 5
0 0 0 3 0

*/
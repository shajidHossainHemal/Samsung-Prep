#include <bits/stdc++.h>
using namespace std;

int n;
int grid[1003][1003];
int dist[1003][1003];
int dx4[] = {-1, 0, 1, 0};
int dy4[] = {0, 1, 0, -1};
vector<pair<int, int>> rareElementCoordinates;

struct point
{
    int x;
    int y;
    int cost;
};

bool isSafe(int i, int j)
{
    return (i >= 0 and i < n and j >= 0 and j < n and grid[i][j]);
}

void bfs(int sourceX, int sourceY)
{
    queue<point> q;

    q.push({sourceX, sourceY, 0});

    while(!q.empty())
    {
        int uX = q.front().x;
        int uY = q.front().y;
        int uCost = q.front().cost;
        q.pop();

        for(int i = 0; i < 4; i++)
        {
            int newX = dx4[i] + uX;
            int newY = dy4[i] + uY;

            if(isSafe(newX, newY)) 
            {
                if (uCost + 1 < dist[newX][newY])
                {
                    dist[newX][newY] = uCost + 1;
                    q.push({newX, newY, dist[newX][newY]});
                }
            }
        }
    }
}

int main()
{
    cin >> n;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> grid[i][j];
    
    int rare;
    
    cin >> rare;

    int tempX, tempY;
    for(int i = 0; i < rare; i++)
    {
        cin >> tempX >> tempY;
        rareElementCoordinates.push_back( {tempX, tempY} );
    }

    int answer = INT_MAX;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(grid[i][j])
            {
                for(int k = 0; k < n; k++)
                {
                    fill(dist[k], dist[k] + n, INT_MAX);
                }

                bfs(i, j);

                int maxDistance = -1;
                
                for(int k = 0; k < rare; k++)
                {
                    int x = rareElementCoordinates[k].first;
                    int y = rareElementCoordinates[k].second;
                    maxDistance = max(maxDistance, dist[x][y]);
                }

                if(maxDistance != INT_MAX)
                {
                    answer = min(answer, maxDistance);
                }
            }
        }
    }
    cout << answer << endl;

    return 0;
}

/*

4
1 0 1 1
1 0 1 0
0 1 1 1
1 1 1 0
2
1 1
0 3

*/
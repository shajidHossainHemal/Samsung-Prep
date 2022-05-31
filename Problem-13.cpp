#include <bits/stdc++.h>
using namespace std;

int numberOfWormholes, answer, wormholes[100][5];
bool visited[100] = {false};

int distance(int x1, int y1, int x2, int y2)
{
    return (abs(x1 - x2) + abs(y1 - y2));
}

void solver(int sourceX, int sourceY, int destinationX, int destinationY, int cost)
{
    answer = min(answer, distance(sourceX, sourceY, destinationX, destinationY) + cost);

    int temp;

    for(int i = 0; i < numberOfWormholes; i++)
    {
        if(!visited[i])
        {
            visited[i] = true;

            // Entering through the front of the wormhole
            temp = distance(sourceX, sourceY, wormholes[i][0], wormholes[i][1]) + wormholes[i][4] + cost;
            solver(wormholes[i][2], wormholes[i][3], destinationX, destinationY, temp);
            // Entering through the back of the wormhole
            temp = distance(sourceX, sourceY, wormholes[i][2], wormholes[i][3]) + wormholes[i][4] + cost;
            solver(wormholes[i][0], wormholes[i][1], destinationX, destinationY, temp);

            visited[i] = false;
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

    cin >> numberOfWormholes;

    int sourceX, sourceY, destinationX, destinationY;

    cin >> sourceX >> sourceY >> destinationX >> destinationY;

    for(int i = 0; i < numberOfWormholes; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            cin >> wormholes[i][j];
        }
    }

    answer = INT_MAX;

    solver(sourceX, sourceY, destinationX, destinationY, 0);

    cout << answer << endl;

    return 0;
}

/*

5
0 0 100 100
4 5 10 12 4
15 16 25 30 10
34 35 42 46 14
50 50 57 58 4
72 78 92 92 20

*/
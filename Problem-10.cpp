#include <bits/stdc++.h>
using namespace std;

#define lim 100

int numberOfRows;
int grid[lim][5];
int maxCoins;
bool isBombUsed = false;

void goTo(int i, int j, int coins)
{
    if(j < 0 || j >= 5)
        return;     // Went out of board
    
    if(i == numberOfRows)
    {
        // Reached the end of grid
        if(coins > maxCoins)
            maxCoins = coins;
        return;
    }

    bool flag = false;
    int ptr = 0;
    int enemyCoordinates[25][2];

    if(grid[i][j] == 2)
    {
        if(isBombUsed)
        {
            // Game over here
            if(coins > maxCoins)
                maxCoins = coins;
            return;
        }
        else
        {
            // Use the bomb now
            isBombUsed = true;
            flag = true;
            for(int x = i; x < min(i + 5, numberOfRows); x++)
            {
                for(int y = 0; y < 5; y++)
                {
                    if(grid[x][y] == 2)
                    {
                        enemyCoordinates[ptr][0] = x;
                        enemyCoordinates[ptr++][1] = y;
                        grid[x][y] = 0;
                    }
                }
            }
        }
    }
    else if(grid[i][j] == 1)
        coins = coins + 1;
    
    goTo(i + 1, j + 1, coins);
    goTo(i + 1, j, coins);
    goTo(i + 1, j - 1, coins);

    if(flag)
    {
        for(int k = 0; k < ptr; k++)
        {
            int x = enemyCoordinates[k][0];
            int y = enemyCoordinates[k][1];
            grid[x][y] = 2;
        }
    }

    return;
}

int main()
{
    cin >> numberOfRows;

    int a, b, c, d, e;

    for(int i = 0; i < numberOfRows; i++)
    {
        cin >> a >> b >> c >> d >> e;

        grid[numberOfRows - 1 - i][0] = a;
        grid[numberOfRows - 1 - i][1] = b;
        grid[numberOfRows - 1 - i][2] = c;
        grid[numberOfRows - 1 - i][3] = d;
        grid[numberOfRows - 1 - i][4] = e;
    }

    maxCoins = 0;

    goTo(0, 1, 0);
    goTo(0, 2, 0);
    goTo(0, 3, 0);

    cout << endl << "Max coins: " << maxCoins << endl;

    return 0;
}
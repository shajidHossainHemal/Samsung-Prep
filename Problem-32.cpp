#include <bits/stdc++.h>
using namespace std;

int numberOfFishingSpots, minimum = INT_MAX;
int fishingSpots[100];
int gatePositions[4], fishermanNumberInEachGate[4], results[4];
bool visited[100] = {false};

int solver()
{
    int spots[numberOfFishingSpots + 1];

    memset(spots, 0, sizeof(spots));

    int start = results[1];
    int distances = 0;
    for (int i = start; i <= (start + fishermanNumberInEachGate[1] - 1) and i <= numberOfFishingSpots; i++)
    {
        spots[i] = 1;
        distances += (abs(i - gatePositions[1]) + 1);
    }

    start = results[2];
    for(int i = start; i <= (start + fishermanNumberInEachGate[2] - 1) and i <= numberOfFishingSpots; i++)
    {
        spots[i] = 2;
        distances += (abs(i - gatePositions[2]) + 1);
    }

    start = results[3];
    for(int i = start; i <= (start + fishermanNumberInEachGate[3] - 1) and i <= numberOfFishingSpots; i++)
    {
        spots[i] = 3;
        distances += (abs(i - gatePositions[3]) + 1);
    }

    int counter = 0;
    for(int i = 1; i <= numberOfFishingSpots; i++)
    {
        if(spots[i])
            counter++;
    }

    if(counter == (fishermanNumberInEachGate[1] + fishermanNumberInEachGate[2] + fishermanNumberInEachGate[3]))
        return distances;
    
    return INT_MAX;
}

void dfs(int nodes)
{
    if(nodes == 3)
    {
        int tempIndex = 1;
        for(int i = 1; i <= numberOfFishingSpots; i++)
        {
            if(visited[i])
            {
                results[tempIndex++] = fishingSpots[i];
            }
        }
        int value = solver();
        minimum = min(minimum, value);
    }

    for(int i = 1; i <= numberOfFishingSpots; i++)
    {
        if(!visited[i])
        {
            visited[i] = true;
            dfs(nodes + 1);
            
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

    cin >> numberOfFishingSpots;

    for(int i = 1; i <= numberOfFishingSpots; i++)
        fishingSpots[i] = i;
    
    cin >> gatePositions[1] >> gatePositions[2] >> gatePositions[3];
    cin >> fishermanNumberInEachGate[1] >> fishermanNumberInEachGate[2] >> fishermanNumberInEachGate[3];

    dfs(0);

    cout << minimum << endl;

    return 0;
}

/*

Input:
2
10
4 6 10
5 2 2
10
8 9 10
5 1 2
Output:
18
25

*/
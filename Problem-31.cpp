#include <bits/stdc++.h>
using namespace std;

int main()
{
    // int testCase;

    // cin >> testCase;

    // while(testCase--)
    // {

    // }

    int nodes, edges, time, startingNode;

    cin >> nodes >> edges >> time;

    int adjacencyMatrix[nodes][nodes];

    memset(adjacencyMatrix, 0, sizeof(adjacencyMatrix));
    
    int from, to;
    float probability;
    for(int i = 0; i < edges; i++)
    {
        cin >> from >> to >> probability;

        adjacencyMatrix[from][to] = probability;
    }

    cin >> startingNode;

    int numberOfTraversals = time/10;
    int currentNode = startingNode;
    while(numberOfTraversals > 0)
    {
        int nextNode = -1;
        float maximumProbability = -1;

        for(int i = 0; i < nodes; i++)
        {
            if(adjacencyMatrix[currentNode][i] > maximumProbability)
            {
                maximumProbability = adjacencyMatrix[currentNode][i];
                nextNode = i;
            }
        }

        if(nextNode == -1)
        {
            cout << "Exited the last lab" << endl;
            return 0;
        }

        currentNode = nextNode;
        numberOfTraversals--;
    }

    cout << "After " << time << " minutes, the doctor is at node : " << currentNode << endl;

    return 0;
}

/*

4 6 25
0 1 75
0 2 25
1 2 100
2 0 45
2 3 55
3 3 100
0

3 3 14
0 1 25
1 2 40
2 1 35
0

*/
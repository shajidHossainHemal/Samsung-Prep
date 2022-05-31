#include <bits/stdc++.h>
using namespace std;

#define INF 999

int vertex, start, cost[100][100], dist[100], parent[100];
bool visited[100] = {false};

void initialize()
{
    for(int i = 0; i < vertex; i++)
    {
        parent[i] = i;
        dist[i] = INF;
    }
    dist[start] = 0;
}

int getNearest()
{
    int minimumValue = INF;
    int minimumNode = 0;

    for(int i = 0; i < vertex; i++)
    {
        if(!visited[i] and dist[i] < minimumValue)
        {
            minimumValue = dist[i];
            minimumNode = i;
        }
    }
    return minimumNode;
}

void dijkstra()
{
    for(int i = 0; i < vertex; i++)
    {
        int nearest = getNearest();
        visited[nearest] = true;

        for(int adj = 0; adj < vertex; adj++)
        {
            if(cost[nearest][adj] != INF and dist[adj] > dist[nearest] + cost[nearest][adj])
            {
                dist[adj] = dist[nearest] + cost[nearest][adj];
                parent[adj] = nearest;
            }
        }
    }
}

void display()
{
    cout << "Node:\t\t\tCost:\t\t\tPath";
    cout << endl;

    for(int i = 0; i < vertex; i++)
    {
        cout << i << "\t\t\t" << dist[i] << "\t\t\t" << ' ' << i << ' ';

        int parentNode = parent[i];
        while(parentNode != start)
        {
            cout << " <- " << parentNode << ' ';
            parentNode = parent[parentNode];
        }
        cout << " <- " << start << endl;
    }
}

int main()
{
    cout << "Enter the number of vertices: ";
    cin >> vertex;

    cout << endl << "Enter the cost matrix:" << endl << endl;
    for(int i = 0; i < vertex; i++)
    {
        for(int j = 0; j < vertex; j++)
        {
            cin >> cost[i][j];
        }
    }

    cout << endl << "Enter the starting vertex: ";
    cin >> start;

    initialize();
    dijkstra();
    
    cout << endl;
    display();

    return 0;
}

/*

Enter the number of vertices: 9

Input cost matrix :

0   4   999   999   999   999   999   8   999
4   0   8     999   999   999   999   8   999
999 8   0       7   999   4     999   999   2
999 999 7       0   9     14    999   999 999
999 999 999     9   0     10    999   999 999
999 999   4    14   10    0     2     999 999
999 999 999   999   999   2     0     1   6
8   11  999   999   999   999   1     0   7
999 999   2   999   999   999   6     7   0

Enter the starting vertex: 1

*/
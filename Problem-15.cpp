#include <bits/stdc++.h>
using namespace std;

int n, minimum;
bool visited[15] = { false };
pair<int, int> office, home, customers[15];

int distance(pair<int, int> a, pair<int, int> b)
{
    return abs(a.first - b.first) + abs(a.second - b.second);
}

void optimalPath(pair<int, int> currentLocation, int cost, int count)
{
    if(count == n)
    {
        cost += distance(currentLocation, home);
        minimum = min(cost, minimum);
        return;
    }

    for(int i = 0; i < n; i++)
    {
        if(!visited[i])
        {
            visited[i] = true;
            optimalPath(customers[i], cost + distance(currentLocation, customers[i]), count + 1);

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

    cin >> n;
    cin >> office.first >> office.second;
    cin >> home.first >> home.second;

    for(int i = 0; i < n; i++)
        cin >> customers[i].first >> customers[i].second;
    
    minimum = INT_MAX;

    optimalPath(office, 0, 0);

    cout << minimum << endl;

    return 0;
}
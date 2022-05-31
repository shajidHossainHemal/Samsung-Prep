#include <bits/stdc++.h>
using namespace std;

int n, minimum, visited[15];
pair<int, int> office, home, customers[15];

int distance(pair<int, int> a, pair<int, int> b)
{
    return abs(a.first - b.first) + abs(a.second - b.second);
}

void optimalPath(pair<int, int> current, int cost, int count)
{
    if(count == n)
    {
        cost += distance(current, home);
        minimum = min(cost, minimum);
        return;
    }

    for(int i = 0; i < n; i++)
    {
        if(visited[i] == 0)
        {
            visited[i] = 1;
            optimalPath(customers[i], cost + distance(current, customers[i]), count + 1);

            visited[i] = 0;
        }
    }
}

int main()
{
    int testCase;

    // cin >> testCase;

    // while(testCase--)
    // {
        
    // }

    cin >> n;
    cin >> office.first >> office.second;
    cin >> home.first >> home.second;

    minimum = INT_MAX;
    memset(visited, 0, sizeof(visited));

    for (int i = 0; i < n; i++)
        cin >> customers[i].first >> customers[i].second;

    optimalPath(office, 0, 0);

    cout << minimum << endl;

    return 0;
}
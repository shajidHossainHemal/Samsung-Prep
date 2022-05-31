#include <bits/stdc++.h>
using namespace std;

int main()
{
    int numberOfStalls;

    cin >> numberOfStalls;

    string stalls(numberOfStalls, '_');
    queue<pair<int, int>> q;

    q.push({0, numberOfStalls - 1});

    while(!q.empty())
    {
        int left = q.front().first;
        int right = q.front().second;

        q.pop();

        int mid = left + (right - left) / 2;

        stalls[mid] = 'X';

        if(left <= mid - 1)
        {
            q.push({left, mid - 1});
        }
        if(mid + 1 <= right)
        {
            q.push({mid + 1, right});
        }

        cout << stalls << endl;
    }

    return 0;
}
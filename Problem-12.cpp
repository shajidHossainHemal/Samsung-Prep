#include <bits/stdc++.h>
using namespace std;

const int MAX = 100005;

int utility(int pos, int a, int b)
{
    if (pos == 1)
        return a + b;
    else if (pos == 2)
        return a - b;
    else if (pos == 3)
        return a * b;
    else
    {
        if (b == 0 or a % b != 0)
            return -1;
        return a / b;
    }
    return -1;
}

void solve()
{
    int n, m, o;

    cin >> n >> m >> o;

    bool digits[10];

    memset(digits, false, sizeof(digits));

    int temp;

    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        digits[temp] = true;
    }

    vector<int> operations;

    for (int i = 0; i < m; i++)
    {
        cin >> temp;
        operations.push_back(temp);
    }

    int target;

    cin >> target;

    queue<pair<int, int>> Q;

    for (int i = 0; i < 10; i++)
    {
        if (digits[i])
            Q.push(make_pair(i, 1));
    }

    int count = 0;

    while (count < MAX)
    {
        int value = Q.front().first;
        int cost = Q.front().second;

        Q.pop();

        int answer;

        for (int i = 0; i < 10; i++)
        {
            if (digits[i])
            {
                answer = value * 10 + i;

                if (answer == target)
                {
                    cout << value << ' ' << i << endl;
                    cout << cost + 1 << endl;
                    return;
                }

                Q.push(make_pair(answer, cost + 1));

                for (int j = 0; j < m; j++)
                {
                    answer = utility(operations[j], value, i);

                    if (answer != -1)
                    {
                        if (answer == target)
                        {
                            cout << value << ' ' << i << endl;
                            cout << cost + 3 << endl;
                            return;
                        }
                        Q.push(make_pair(value, cost + 3));
                    }
                }
            }
        }

        count++;
    }
}

int main()
{
    // int testCase;

    // cin >> testCase;

    // while(testCase--)
    // {

    // }

    solve();

    return 0;
}
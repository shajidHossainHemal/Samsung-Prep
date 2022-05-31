#include <bits/stdc++.h>
using namespace std;

struct Decide
{
    int buy;
    int sell;
};

void stockBuySell(int prices[], int n)
{
    if (n == 1)
        return;

    int count = 0;
    Decide answer[n];
    int i = 0;

    while (i < n - 1)
    {
        while ((i < n - 1) and (prices[i + 1] <= prices[i]))
            i++;

        if (i == n - 1)
            break;

        answer[count].buy = i++;

        while ((i < n) and (prices[i] >= prices[i - 1]))
            i++;

        answer[count].sell = i - 1;

        count++;
    }

    if (count == 0)
        cout << -1 << endl;
    else
    {
        for (int i = 0; i < count; i++)
            cout << answer[i].buy << "\t" << answer[i].sell << endl;
    }
}

int main()
{
    // int testCase;

    // cin >> testCase;

    // while(testCase--)
    // {

    // }

    int n;

    cin >> n;

    int input[n];

    for (int i = 0; i < n; i++)
        cin >> input[i];

    stockBuySell(input, n);

    return 0;
}

/*

7
100 180 260 310 40 510 695

*/
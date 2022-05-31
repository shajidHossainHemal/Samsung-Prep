#include <bits/stdc++.h>
using namespace std;

int main()
{
    // int testCase;

    // cin >> testCase;

    // while(testCase--)
    // {

    // }

    int n;

    cin >> n;

    int input[507];
    int dp[505][505];

    memset(dp, 0, sizeof(dp));

    for(int i = 1; i <= n; i++)
        cin >> input[i];
    
    input[0] = input[n + 1] = 1;

    for(int window = 1; window <= n; window++) 
    {
        for(int left = 1, right = left + window - 1; left <= n - window + 1; left++, right++)
        {
            for(int i = left; i <= right; i++)
            {
                dp[left][right] = max(dp[left][right], input[i] * input[left - 1] * input[right + 1] + dp[left][i - 1] + dp[i + 1][right]);
            }
        }
    }

    cout << dp[1][n] << endl;

    return 0;
}
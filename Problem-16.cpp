#include <bits/stdc++.h>
using namespace std;

int main()
{
    // int testCase;

    // cin >> testCase;

    // while(testCase--)
    // {

    // }

    int n, k, temp;
    vector<int> O;

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cin >> temp;
        O.push_back(temp); 
    }

    cin >> k;

    sort(O.begin(), O.end());

    for(int i = n - 1; i > 0; i--)
    {
        O[i] = O[i] - O[i - 1];
    }

    sort(O.begin(), O.end());

    int answer = 0;

    for(int i = 0; i < k; i++)
    {
        answer += (O[i] * (n - i));
    }

    cout << answer << endl;

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int missingNumber(int input[], int n)
{
    int newN = 0;

    for(int i = 0; i < n; i++)
    {
        if(input[i] > 0)
            swap(input[i], input[newN++]);
    }

    for(int i = 0; i < newN; i++)
    {
        if(abs(input[i]) - 1 < newN and input[abs(input[i]) - 1] > 0)
            input[abs(input[i]) - 1] *= -1;
    }

    for(int i = 0; i < newN; i++)
    {
        if(input[i] > 0)
            return i + 1;
    }

    return newN + 1;
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

    for(int i = 0; i < n; i++)
        cin >> input[i];
    
    int answer = missingNumber(input, n);

    cout << answer << endl;

    return 0;
}
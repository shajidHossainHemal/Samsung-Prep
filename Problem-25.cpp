#include <bits/stdc++.h>
using namespace std;

vector<int> nextPermutation(vector<int> input, int n)
{
    int k = -1;

    for(int i = 0; i + 1 < n; i++)
    {
        if(input[i] < input[i + 1])
            k = i;
    }

    if(k == -1)
    {
        vector<int> temp;

        for(int i = 1; i <= n; i++)
            temp.push_back(i);
        
        return temp;
    }

    int l = -1;
    for(int i = k + 1; i < n; i++)
    {
        if(input[i] > input[k])
            l = i;
    }
    swap(input[k], input[l]);

    for(int i = k + 1, j = n - 1; i < (n + k + 1) / 2; i++, j--)
    {
        swap(input[i], input[j]);
    }

    return input;
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

    vector<int> input;

    int temp;
    for(int i = 0; i < n; i++)
    {
        cin >> temp;

        input.push_back(temp);
    }
    
    vector<int> answer = nextPermutation(input, n);

    for(int i = 0; i < answer.size(); i++)
        cout << answer[i] << ' ';
    cout << endl;

    return 0;
}
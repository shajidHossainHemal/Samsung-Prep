#include <bits/stdc++.h>
using namespace std;

vector<int> maxSubArraySum(string input, int size)
{
    if(count(input.begin(), input.end(), '1') == size)
        return {-1};
    
    int startingIndex = 0, startingTemp = 0, endingIndex = 0;
    int maxSoFar = INT_MIN, maxEndingHere = 0;

    for(int i = 0; i < size; i++)
    {
        if (input[i] == '0')
            maxEndingHere++;
        if (input[i] == '1')
            maxEndingHere--;
        if (maxSoFar < maxEndingHere)
        {
            maxSoFar = maxEndingHere;
            startingIndex = startingTemp;
            endingIndex = i;
        }
        if (maxEndingHere < 0)
        {
            maxEndingHere = 0;
            startingTemp = i + 1;
        }
    }
    return { startingIndex + 1, endingIndex + 1 };
}

int main()
{
    // int testCase;

    // cin >> testCase;

    // while(testCase--)
    // {

    // }

    string input;
    int n;

    cin >> n >> input;

    vector<int> answer = maxSubArraySum(input, n);

    cout << answer[0] << ' ' << answer[1] << endl;

    return 0;
}

/*

8
11000111

*/
#include <bits/stdc++.h>
using namespace std;

int maxSubArraySum(int input[], int size)
{
    int maxSoFar = INT_MIN;
    int maxEndingHere = 0;

    for(int i = 0; i < size; i++)
    {
        maxEndingHere += input[i];
        
        if(maxSoFar < maxEndingHere)
            maxSoFar = maxEndingHere;
        
        if(maxEndingHere < 0)
            maxEndingHere = 0;
    }
    return maxSoFar;
}

int main()
{
    int n;

    cin >> n;

    int input[n];

    for(int i = 0 ; i < n; i++)
        cin >> input[i];
    
    int maxSum = maxSubArraySum(input, n);

    cout << maxSum << endl;

    return 0;
}

/*

8
-2 -3 4 -1 -2 1 5 -3

4
-2 3 2 -1

*/
#include <bits/stdc++.h>
using namespace std;

int pow(int base, int n)
{
    int result = 1;

    for(int i = 1; i <= n; i++)
    {
        result *= base;
    }
    return result;
}

int main()
{
    int n, m, k;

    cin >> n >> m >> k;

    int matrix[n][m] = {0};

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> matrix[i][j];
    
    int size = 1;
    for(int i = 1; i <= 20; i++) 
    {
        size *= 2;
        // cout << size << " ";
    }
    // cout << endl;

    int *hash = (int *) calloc(size, sizeof(int));

    for(int i = 0; i < n; i++) 
    {
        int keyValue = 0;
        int numZeros = 0;

        for(int j = 0; j < m; j++)
        {
            keyValue += (matrix[i][j] * pow(2, j));

            if(matrix[i][j] == 0)
                numZeros += 1;
        }

        if((numZeros - k) % 2 == 0 and (numZeros - k) >= 0)
            hash[keyValue] += 1;

        // cout << keyValue << ' ' << numZeros << ' ' << hash[keyValue] << endl;
    }

    int keyWithMaxValue = 0;
    int maxValue = 0;
    for(int i = 0; i < size; i++)
    {
        if(hash[i] > maxValue)
        {
            maxValue = hash[i];
            keyWithMaxValue = i;
        }
    }
    // cout << maxValue << ' ' << keyWithMaxValue << endl;

    cout << maxValue << endl;

    return 0;
}
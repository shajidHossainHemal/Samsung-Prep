#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, k;

    cin >> n >> m >> k;

    int matrix[n][m];
    string key[n];

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
        {
            cin >> matrix[i][j];

            key[i].push_back(char(matrix[i][j] + '0'));
        }
    
    map<string, int> table;

    for(int i = 0; i < n; i++)
    {
        int count = 0;

        for(int j = 0; j < m; j++)
            if(matrix[i][j] == 0)
                count++;
        
        if((k - count) >= 0 and (k - count) % 2 == 0)
            table[key[i]]++;
    }

    int answer = 0;
    for(auto x : table)
    {
        answer = max(answer, x.second);
    }

    cout << answer << endl;

    return 0;
}

/*

3 3 2
1 0 0
1 0 1
1 0 0

3 3 3
1 0 0
1 0 1
1 0 0

*/
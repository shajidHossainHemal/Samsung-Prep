#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;

    cin >> n;

    int input[n];

    for (int i = 0; i < n; i++)
        cin >> input[i];
    
    for(int i = 0; i < n; i++)
    {
        int min_idx = i;

        for(int j = i + 1; j < n; j++)
        {
            if(input[j] < input[min_idx])
                min_idx = j;
        }

        swap(input[min_idx], input[i]);
    }

    for(int i = 0; i < n; i++)
        cout << input[i] << '\t';
    cout << endl;

    return 0;
}

/*

10
10 2 0 14 43 25 18 1 5 45

*/
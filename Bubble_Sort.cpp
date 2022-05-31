#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    
    cin >> n;

    vector<int> input;
    int temp;

    for(int i = 0; i < n; i++)
    {
        cin >> temp;
        input.push_back(temp);
    }

    for(int i = 0; i < input.size(); i++)
    {
        for(int j = i + 1; j < input.size(); j++)
        {
            if(input[i] > input[j])
            {
                temp = input[i];
                input[i] = input[j];
                input[j] = temp;
            }
        }
    }

    cout << "Sorted Element List ....\n";
    for(int i = 0; i < input.size(); i++)
    {
        cout << input[i] << '\t';
    }
    cout << endl;

    return 0;
}

/*

10
10 2 0 14 43 25 18 1 5 45

*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;

    cin >> n;

    vector<int> input;
    int temp;

    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        input.push_back(temp);
    }

    bool swapped;

    for (int i = 0; i < input.size() - 1; i++)
    {
        swapped = false;

        for (int j = 0; j < input.size() - i - 1; j++)
        {
            if (input[j] > input[j + 1])
            {
                temp = input[j];
                input[j] = input[j + 1];
                input[j + 1] = temp;
                swapped = true;
            }
        }

        if(!swapped)
            break;
    }

    cout << "Sorted Element List ....\n";
    for (int i = 0; i < input.size(); i++)
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
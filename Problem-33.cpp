#include <bits/stdc++.h>
using namespace std;

int main()
{
    // int testCase;

    // cin >> testCase;

    // while(testCase--)
    // {

    // }

    string input;

    cin >> input;

    string temp = "";

    temp.push_back(input[0]);
    for (int i = 1; i < input.size(); i++)
    {
        if (temp.back() == input[i] and input[i] == '0')
            continue;
        temp.push_back(input[i]);
    }

    int count = 0;

    for (int i = 0; i < temp.size() - 2; i++)
    {
        if (temp[i] == '1' and temp[i + 1] == '0' and temp[i + 2] == '1')
            count++;
    }

    cout << count << endl;

    return 0;
}
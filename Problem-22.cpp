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

    getline(cin, input);

    int n = input.size();

    vector<string> answer;
    string temp = "";

    for(int i = 0; i < n; i++)
    {
        if(input[i] == ':')
        {
            answer.push_back(temp);
            temp.clear();
        }
        else
        {
            if(input[i] == ' ')
                continue;
            
            temp += input[i];
        }

        if(i == n - 1)
            answer.push_back(temp);
    }

    for(auto x : answer)
        cout << x << ' ';
    cout << endl;

    return 0;
}

/*

Input : ab : cd : ef : 12 : 34 : 56

*/
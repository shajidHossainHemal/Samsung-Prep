#include <bits/stdc++.h>
using namespace std;

int main()
{
    int k;
    string input;

    cin >> k >> input;

    int level = -1;
    int sum = 0;
    for(int i = 0; i < input.size(); i++)
    {
        if(input[i] == '(')     level++;
        else if(input[i] == ')')    level--;
        else if(level == k)    sum += (input[i] - '0');
    }

    cout << sum << endl;

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main()
{
    string input;

    cin >> input;

    stack<string> output;
    string temp = "";

    for(int i = 0; i < input.length(); i++)
    {
        if(input[i] == '.')
        {
            output.push(temp);
            temp = "";
        }
        else
        {
            temp += input[i];
        }
    }

    output.push(temp);

    int size = output.size();
    for(int i = 0; i < size; i++)
    {
        cout << output.top();

        if(i != size - 1)
            cout << '.';
        
        output.pop();
    }
    cout << endl;

    return 0;
}
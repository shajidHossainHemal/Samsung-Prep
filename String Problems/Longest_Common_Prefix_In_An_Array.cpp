#include <bits/stdc++.h>
using namespace std;

string commonPrefix(string string1, string string2)
{
    int n1 = string1.length();
    int n2 = string2.length();
    string result;

    for (int j = 0, k = 0; j < n1 and k < n2; j++, k++)
    {
        if (string1[j] != string2[k])
        {
            break;
        }
        result.push_back(string1[j]);
    }

    return result;
}

int main()
{
    int n;

    cin >> n;

    string input[n];
    string temp;

    for(int i = 0; i < n; i++)
    {
        cin >> temp;
        input[i] = temp;
    }

    string prefix = input[0];

    for(int i = 1; i < n; i++)
    {
        prefix = commonPrefix(prefix, input[i]);
    }

    cout << prefix << endl;

    return 0;
}

/*

4
geeksforgeeks
geeks 
geek 
geezer

*/
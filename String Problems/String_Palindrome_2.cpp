#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string s)
{
    for(int i = 0; i < s.length(); i++)
    {
        if(s[i] != s[s.length() - i - 1])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    string input;

    cin >> input;

    if(isPalindrome(input))
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string s)
{
    string p = s;

    reverse(p.begin(), p.end());

    if(s == p)
    {
        return true;
    }
    else
    {
        return false;
    }
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
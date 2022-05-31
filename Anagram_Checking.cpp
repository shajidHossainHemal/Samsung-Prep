#include <bits/stdc++.h>
using namespace std;

bool areAnagram(string input1, string input2)
{
    if(input1.length() != input2.length())
        return false;

    sort(input1.begin(), input1.end());
    sort(input2.begin(), input2.end());

    if(input1 != input2)
        return false;

    // for(int i = 0; i < input1.length(); i++)
    //     if(input1[i] != input2[i])
    //         return false;

    return true;
}

int main()
{
    string input1, input2;

    cin >> input1 >> input2;

    if(areAnagram(input1, input2))
    {
        cout << "The two strings are anagram of each other" << endl;
    }
    else
    {
        cout << "The two strings are not anagram of each other" << endl;
    }

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

map<char, int> counter;

bool areAnagram(string input1, string input2)
{
    if(input1.length() != input2.length())
        return false;
    
    for(int i = 0; i < input1.length(); i++)
    {
        counter[input1[i]]++;
        counter[input2[i]]--;
    }

    for(int i = 0; i < input1.length(); i++)
        if(counter[input1[i]])
            return false;
    
    return true;
}

int main()
{
    string input1, input2;

    cin >> input1 >> input2;

    if(areAnagram(input1, input2))
    {
        cout << "The two strings are anagram of each other";
    }
    else 
    {
        cout << "The two strings are not anagram of each other";
    }

    return 0;
}
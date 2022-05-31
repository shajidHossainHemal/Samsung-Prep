#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;

    cin >> n;

    vector<string> input;
    string temp;

    for(int i = 0; i < n; i++)
    {
        cin >> temp;
        input.push_back(temp);
    }

    string word1, word2;

    cin >> word1 >> word2;

    int count1 = -1;
    int count2 = -1;
    int minimum = INT_MAX;
    for(int i = 0; i < n; i++)
    {
        if(input[i] == word1)
            count1 = i;
        else if(input[i] == word2)
            count2 = i;

        if(count1 != -1 and count2 != -1)
            minimum = min(minimum, abs(count1 - count2));
    }

    cout << minimum << endl;

    return 0;
}

/*

5
the quick brown fox quick
the fox

5
geeks for geeks contribute practice
geeks practice

*/
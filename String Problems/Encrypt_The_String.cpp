#include <bits/stdc++.h>
using namespace std;

int main()
{
    map<int, char> mp;

    mp[0] = '0';
    mp[1] = '1';
    mp[2] = '2';
    mp[3] = '3';
    mp[4] = '4';
    mp[5] = '5';
    mp[6] = '6';
    mp[7] = '7';
    mp[8] = '8';
    mp[9] = '9';
    mp[10] = 'a';
    mp[11] = 'b';
    mp[12] = 'c';
    mp[13] = 'd';
    mp[14] = 'e';
    mp[15] = 'f';

    string input;

    cin >> input;

    int counter = 1;
    int sum = 0;
    string output = "";

    for(int i = 0; i < input.size(); i++)
    {
        if(input[i] == input[i + 1])
        {
            counter++;
            cout << counter << endl;
            continue;
        }

        output.push_back(input[i]);
        
        while(counter > 0)
        {
            sum = counter % 16;
            output += mp[sum];
            counter = floor(counter / 16.0);
        }

        counter = 1;
    }

    cout << output << "\t";
    reverse(output.begin(), output.end());
    cout << output << endl;

    return 0;
}
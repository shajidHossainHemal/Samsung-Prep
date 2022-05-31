#include <bits/stdc++.h>
using namespace std;

int isDivisibleBySeven(string input)
{
    int n = input.length();
    int gSum = 0;

    if(n == 0)
        return 1;
    
    if(n % 3 == 1)
    {
        input = "00" + input;
        n += 2;
    }
    else if(n % 3 == 2)
    {
        input = "0" + input;
        n++;
    }

    int t, p = 1;
    for(int i = n - 1; i >= 0; i--)
    {
        int group = 0;
        group += input[i--] - '0';
        group += (input[i--] - '0') * 10;
        group += (input[i] - '0') * 100;

        gSum = gSum + group * p;

        p *= (-1);
    }

    return (gSum % 7 == 0);
}

int main()
{
    string input;

    cin >> input;

    if(isDivisibleBySeven(input))
    {
        cout << "Divisible by 7" << endl;
    }
    else
    {
        cout << "Not Divisible by 7" << endl;
    }

    return 0;
}

/*

8955795758

1000

*/
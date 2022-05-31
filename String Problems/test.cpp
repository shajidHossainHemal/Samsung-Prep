#include <bits/stdc++.h>
using namespace std;

int main()
{
    int input;

    cin >> input;

    string symbols[] = { "I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M" };
    int numbers[] = { 1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000 };

    int i = 12;
    while(input > 0)
    {
        int quotient = input / numbers[i];
        input = input % numbers[i];

        while(quotient--)
        {
            cout << symbols[i];
        }
        i--;
    }
    cout << endl;

    return 0;
}
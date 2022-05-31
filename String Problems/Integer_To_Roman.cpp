#include <bits/stdc++.h>
using namespace std;

int main()
{
    int input;

    cin >> input;

    string symbol[] = { "I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M" };
    int number[] = { 1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000 };

    // pair<int, string> lookUpTable[13];

    // lookUpTable[0] = make_pair(1, "I");
    // lookUpTable[1] = make_pair(4, "IV");
    // lookUpTable[2] = make_pair(5, "V");
    // lookUpTable[3] = make_pair(9, "IX");
    // lookUpTable[4] = make_pair(10, "X");
    // lookUpTable[5] = make_pair(40, "XL");
    // lookUpTable[6] = make_pair(50, "L");
    // lookUpTable[7] = make_pair(90, "XC");
    // lookUpTable[8] = make_pair(100, "C");
    // lookUpTable[9] = make_pair(400, "CD");
    // lookUpTable[10] = make_pair(500, "D");
    // lookUpTable[11] = make_pair(900, "CM");
    // lookUpTable[12] = make_pair(1000, "M");

    int i = 12;
    while(input > 0)
    {
        int quotient = input / number[i];
        input = input % number[i];

        while(quotient--)
        {
            cout << symbol[i];
        }
        i--;
    }

    return 0;
}

/*

3549
1904

*/
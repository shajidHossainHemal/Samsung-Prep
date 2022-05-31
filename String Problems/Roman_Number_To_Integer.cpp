#include <bits/stdc++.h>
using namespace std;

int getValue(char symbol)
{
    if(symbol == 'I')   return 1;
    else if(symbol == 'V')   return 5;
    else if(symbol == 'X')   return 10;
    else if(symbol == 'L')   return 50;
    else if(symbol == 'C')   return 100;
    else if(symbol == 'D')   return 500;
    else if(symbol == 'M')   return 1000;
    
    return -1;
}

int main()
{
    int testCase;

    cin >> testCase;

    while(testCase--)
    {
        string input;

        cin >> input;

        int result = 0;

        for (int i = 0; i < input.length(); i++)
        {
            int s1 = getValue(input[i]);

            if (i + 1 < input.length())
            {
                int s2 = getValue(input[i + 1]);

                if (s1 >= s2)
                {
                    result += s1;
                }
                else
                {
                    result += (s2 - s1);
                    i++;
                }
            }
            else
            {
                result += s1;
            }
        }

        cout << result << endl;
    }

    return 0;
}

/*

14
I IV V IX X XL L XC C CD D CM M MCMIV

*/
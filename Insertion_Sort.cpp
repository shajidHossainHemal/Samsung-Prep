#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;

    cin >> n;

    vector<int> input;
    int temp;

    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        input.push_back(temp);
    }

   for(int i = 1; i < input.size(); i++)
   {
       int key = input[i];
       int j = i - 1;

       while(key < input[j] and j >= 0)
       {
           input[j + 1] = input[j];
           --j;
       }
       input[j + 1] = key;
   }

    cout << "Sorted Element List ....\n";
    for (int i = 0; i < input.size(); i++)
    {
        cout << input[i] << '\t';
    }
    cout << endl;

    return 0;
}

/*

10
10 2 0 14 43 25 18 1 5 45

*/
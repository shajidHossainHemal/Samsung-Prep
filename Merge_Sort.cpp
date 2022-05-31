#include <bits/stdc++.h>
using namespace std;

void merge(int input[], int p, int q, int r)
{
    int n1 = q - p + 1;
    int n2 = r - q;

    int L[n1], M[n2];

    for(int i = 0; i < n1; i++)
    {
        L[i] = input[p + i];
    }
    for(int j = 0; j < n2; j++)
    {
        M[j] = input[q + 1 + j];
    }

    int i, j, k;
    i = 0;
    j = 0;
    k = p;

    while(i < n1 and j < n2)
    {
        if(L[i] <= M[j])
        {
            input[k] = L[i];
            i++;
        }
        else
        {
            input[k] = M[j];
            j++;
        }
        k++;
    }

    while(i < n1)
    {
        input[k] = L[i];
        i++;
        k++;
    }

    while(j < n2)
    {
        input[k] = M[j];
        j++;
        k++;
    }
}

void mergeSort(int input[], int start, int end)
{
    if(start < end) 
    {
        int mid = start + (end - start) / 2;

        mergeSort(input, start, mid);
        mergeSort(input, mid + 1, end);

        merge(input, start, mid, end);
    }
}

int main()
{
    int n;

    cin >> n;

    int input[n];

    for(int i = 0; i < n; i++)
    {
        cin >> input[i];
    }

    mergeSort(input, 0, n - 1);

    for(int i = 0; i < n; i++)
        cout << input[i] << '\t';
    cout << endl;

    return 0;
}

/*

10
10 2 0 14 43 25 18 1 5 45

*/
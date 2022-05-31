#include <bits/stdc++.h>
using namespace std;

int partition(int input[], int start, int end)
{
    int pivot = input[start];

    int count = 0;
    for(int i = start + 1; i <= end; i++)
    {
        if(input[i] <= pivot)
            count++;
    }

    int pivotIndex = start + count;
    swap(input[pivotIndex], input[start]);

    int i = start, j = end;
    while(i < pivotIndex and j > pivotIndex)
    {
        while(input[i] <= pivot) {
            i++;
        }

        while(input[j] > pivot) {
            j--;
        }

        if(i < pivotIndex and j > pivotIndex) {
            swap(input[i++], input[j--]);
        }
    }

    return pivotIndex;
}

void quickSort(int input[], int start, int end)
{
    if(start >= end)
        return;
    
    int pivot = partition(input, start, end);

    for (int i = 0; i < 10; i++)
    {
        cout << input[i] << '\t';
    }
    cout << endl;

    quickSort(input, start, pivot - 1);
    quickSort(input, pivot + 1, end);
}

int main()
{
    int n;

    cin >> n;

    int input[n];
    int temp;

    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
    }

    quickSort(input, 0, n - 1);

    cout << endl;
    for (int i = 0; i < n; i++)
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
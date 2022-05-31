#include <bits/stdc++.h>
using namespace std;

void heapify(int input[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if(left < n and input[left] > input[largest])
        largest = left;
    if(right < n and input[right] > input[largest])
        largest = right;
    
    if(largest != i)
    {
        swap(input[i], input[largest]);
        heapify(input, n, largest);
    }
}

void heapSort(int input[], int n)
{
    for(int i = n / 2 - 1; i >= 0; i--)
        heapify(input, n, i);

    for(int i = n - 1; i >= 0; i--)
    {
        swap(input[0], input[i]);

        heapify(input, i, 0);
    }
}

void printArray(int input[], int n)
{
    for(int i = 0; i < n; i++)
        cout << input[i] << '\t';
    cout << endl;
}

int main()
{
    int n;

    cin >> n;

    int input[n];

    for(int i = 0; i < n; i++)
        cin >> input[i];
    
    heapSort(input, n);

    cout << "Sorted array is: ";
    printArray(input, n);

    return 0;
}

/*

10
10 2 0 14 43 25 18 1 5 45

*/
#include <bits/stdc++.h>
using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(vector<int> &heapTree, int i)
{
    int size = heapTree.size();
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if(left < size and heapTree[left] > heapTree[largest])
        largest = left;
    if(right < size and heapTree[right] > heapTree[largest])
        largest = right;
    
    if(largest != i)
    {
        swap(&heapTree[i], &heapTree[largest]);
        heapify(heapTree, largest);
    }
}

void insert(vector<int> &heapTree, int newNum)
{
    int size = heapTree.size();

    if(size == 0)
    {
        heapTree.push_back(newNum);
    }
    else
    {
        heapTree.push_back(newNum);
        
        for(int i = size / 2 - 1; i >= 0; i--)
        {
            heapify(heapTree, i);
        }
    }
}

void deleteNode(vector<int> &heapTree, int num)
{
    int size = heapTree.size();
    int i = 0;

    for(i = 0; i < size; i++)
    {
        if(num == heapTree[i])
            break;
    }
    swap(&heapTree[i], &heapTree[size - 1]);

    heapTree.pop_back();

    for(int j = size - 1 / 2; j >= 0; j--)
    {
        heapify(heapTree, j);
    }
}

void printArray(vector<int> &heapTree)
{
    for(int i = 0; i < heapTree.size(); i++)
        cout << heapTree[i] << '\t';
    cout << endl;
}

int main()
{
    vector<int> heapTree;

    insert(heapTree, 3);
    insert(heapTree, 4);
    insert(heapTree, 9);
    insert(heapTree, 5);
    insert(heapTree, 2);

    cout << "Max-Heap array: ";
    printArray(heapTree);

    deleteNode(heapTree, 4);

    cout << "After deleting an element: ";
    printArray(heapTree);

    return 0;
}
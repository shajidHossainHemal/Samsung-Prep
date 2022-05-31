#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

void insert(struct Node **headRef, int newData)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    struct Node *last = *headRef;

    newNode->data = newData;
    newNode->next = NULL;

    if(*headRef == NULL)
    {
        *headRef = newNode;
        return;
    }

    while(last->next != NULL)
        last = last->next;
    
    last->next = newNode;

    return;
}

void deleteNode(struct Node **headRef, int key)
{
    struct Node *temp = *headRef, *prev;

    if(temp != NULL and temp->data == key)
    {
        *headRef = temp->next;
        free(temp);
        return;
    }

    while(temp->next != NULL and temp->data != key)
    {
        prev = temp;
        temp = temp->next;
    }

    if(temp == NULL)
        return;
    
    prev->next = temp->next;

    free(temp);
}

void printList(struct Node *node)
{
    while(node != NULL)
    {
        cout << node->data << ' ';
        node = node->next;
    }
}

int main()
{
    // int testCase;

    // cin >> testCase;

    // while(testCase--)
    // {

    // }

    struct Node *head = NULL;

    int n, temp, nodeToBeDeleted;

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cin >> temp;
        insert(&head, temp);
    }

    cin >> nodeToBeDeleted;

    deleteNode(&head, nodeToBeDeleted);

    printList(head);

    return 0;
}
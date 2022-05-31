#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node() {
        data = 0;
        left = NULL;
        right = NULL;
    }

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};

Node* insert(Node *root, int newData)
{
    if(root == NULL)
    {
        Node *newNode = new Node(newData);
        root = newNode;
    }
    else if(root->data >= newData)
    {
        root->left = insert(root->left, newData);
    }
    else
    {
        root->right = insert(root->right, newData);
    }

    return root;
}

void kthLargestValue(Node *root, int k, int &counter)
{
    if(root == NULL or counter >= k)
        return;

    kthLargestValue(root->right, k, counter);

    counter++;
    if(counter == k)
    {
        cout << "K'th largest element is: " << root->data << endl;
        return;
    }

    kthLargestValue(root->left, k, counter);
}

int main()
{
    // int testCase;

    // cin >> testCase;

    // while(testCase--)
    // {

    // }

    int n;
    struct Node *root = new Node();

    cin >> n;

    int temp;
    for(int i = 0; i < n; i++)
    {
        cin >> temp;
        root = insert(root, temp);
    }

    int k;

    cin >> k;

    int counter = 0;

    kthLargestValue(root, k, counter);

    return 0;
}
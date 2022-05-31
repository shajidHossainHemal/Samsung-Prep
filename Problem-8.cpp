#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* next;
};

void insertAtBeginning(struct Node **head_ref, int new_data)
{
    // Allocate memory to a node
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));

    // Insert the data
    new_node->data = new_data;
    new_node->next = (*head_ref);

    // Move head to new node
    (*head_ref) = new_node;
}

// Insert a node after a node
void insertAfter(struct Node *prev_node, int new_data)
{
    if (prev_node == NULL)
    {
        cout << "The given previous node cannot be NULL" << endl;
        return;
    }

    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

// Insert at the end
void insertAtEnd(struct Node **head_ref, int new_data)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    struct Node *last = *head_ref;

    new_node->data = new_data;
    new_node->next = NULL;

    if (*head_ref == NULL)
    {
        *head_ref = new_node;
        return;
    }

    while (last->next != NULL)
        last = last->next;

    last->next = new_node;

    return;
}

bool detectLoop(struct Node* head)
{
    unordered_set<Node*> set;

    while(head != NULL)
    {
        if(set.find(head) != set.end())   return true;

        set.insert(head);
        head = head->next;
    }
    return false;
}

int main()
{
    int testCase;

    // cin >> testCase;

    // while(testCase--)
    // {

    // }

    int n;
    
    cin >> n;

    int input;
    struct Node* head = NULL;

    for(int i = 0; i < n; i++)
    {
        cin >> input;
        insertAtBeginning(&head, input);
    }

    head->next->next->next->next = head;

    if(detectLoop(head))
        cout << "Loop found" << endl;
    else
        cout << "There is no loop" << endl;

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

class Graph {
    // No. of vertices
    int V;

    // Pointer to an array containing 
    // adjacency lists
    list<int>* adj;

    public:
    // Constructor
    Graph(int V);

    // Function to add an edge to graph
    void addEdge(int u, int v);

    // Prints a Topological Sort of
    // the complete graph
    void topologicalSort();
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int u, int v)
{
    adj[u].push_back(v);
}

// The Function to do Topological Sort.
void Graph::topologicalSort()
{
    // Create a vector to store indegrees of all
    // vertices. Initialize all indegrees as 0.
    vector<int> inDegree(V, 0);

    // Traverse adjacency lists to fill indegrees
    // of vertices. This step takes O(V + E) time
    for(int u = 0; u < V; u++)
    {
        list<int>::iterator itr;

        for(itr = adj[u].begin(); itr != adj[u].end(); itr++)
            inDegree[*itr]++;
    }

    // Create an queue and enqueue all vertices with indegree 0
    queue<int> q;
    for(int i = 0; i < V; i++)
        if(inDegree[i] == 0)
            q.push(i);
    
    // Initialize count of visited vertices
    int count = 0;

    // Create a vector to store result (A topological 
    // ordering of the vertices)
    vector<int> topOrder;

    // One by one dequeue vertices from queue and enqueue
    // adjacents if indegree of adjacent becomes 0
    while(!q.empty())
    {
        // Extract front of queue and add it to the 
        // topological order.
        int u = q.front();
        q.pop();
        topOrder.push_back(u);

        // Iterate through all its neighboring nodes of 
        // dequeued node u and decrease their in-degree by 1
        list<int>::iterator itr;
        for(itr = adj[u].begin(); itr != adj[u].end(); itr++)
        {
            // If in-degree becomes zero add it to queue
            if(--inDegree[*itr] == 0)
                q.push(*itr);
        }

        count++;
    }

    // Check if there was a cycle
    if(count != V)
    {
        cout << "There exist a cycle in the graph" << endl;
        return;
    }

    // Print topological order
    for(int i = 0; i < topOrder.size(); i++)
        cout << topOrder[i] << ' ';
    cout << endl;
}

int main()
{
    int nodes, edges;

    cin >> nodes >> edges;

    Graph g(nodes);

    int from, to;
    for(int i = 0; i < edges; i++)
    {
        cin >> from >> to;

        g.addEdge(from, to);
    }

    cout << "Following is a Topological Sort using Kahn's algorithm: ";
    g.topologicalSort();

    return 0;
}

/*

6 6
5 2
5 0
4 0
4 1
2 3
3 1

*/
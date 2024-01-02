// Adjacency List in Graph

#include <bits/stdc++.h>
using namespace std;

// Function for Adding Edges
void addEdge(vector<int> adj[], int s, int d)
{
    adj[s].push_back(d);
    adj[d].push_back(s);
}

// Function for printing graph
void printGraph(vector<int> adj[], int v)
{
    for (int i = 0; i < v; i++)
    {
        cout << "Vertex " << i << ":";
        for (int x : adj[i])
            cout << "-> " << x;
        cout << endl;
    }
}

// Main Function
int main()
{
    int V, s, d;
    cout << "How many Edges you want?: ";
    cin >> V;

    // Create Graph
    vector<int> adj[V];

    for (int i = 0; i < V-1; i++)
    {
        cout << "Enter Source: ";
        cin >> s;
        cout << "Enter Destination: ";
        cin >> d;
        addEdge(adj, s, d);
        cout << endl;
    }

    printGraph(adj, V);
}
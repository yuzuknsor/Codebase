#include <bits/stdc++.h>
using namespace std;

vector<int> adj[10];
bool visited[10];
stack<int> st;

void addEdge(int u, int v)
{
    adj[u].push_back(v);
}

void topologicalSortUtil(int v)
{
    visited[v] = true;
    for (int u : adj[v])
    {
        if (!visited[u])
        {
            topologicalSortUtil(u);
        }
    }
    st.push(v);
}

void topologicalSort(int V)
{
    memset(visited, false, sizeof(visited));
    for (int v = 0; v < V; v++)
    {
        if (!visited[v])
        {
            topologicalSortUtil(v);
        }
    }
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
}

int main()
{
    int V = 6;
    addEdge(5, 2);
    addEdge(5, 0);
    addEdge(4, 0);
    addEdge(4, 1);
    addEdge(2, 3);
    addEdge(3, 1);
    cout << "Topological Sort of the given graph is \n";
    topologicalSort(V);
    return 0;
}
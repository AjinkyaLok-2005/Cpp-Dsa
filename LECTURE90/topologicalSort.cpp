#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
#include<stack>
using namespace std;

void topSort(int node, unordered_map<int, list<int>> &adj, stack<int> &s, unordered_map<int, bool> &visited)
{
    visited[node] = true;
    for(auto neighbour : adj[node])
    {
        if(!visited[neighbour])
        {
            topSort(neighbour, adj, s, visited);
        }
    }

    s.push(node);
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)
{
    //adj list
    unordered_map<int, list<int>> adj;

    for(int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
    }

    unordered_map<int, bool> visited;
    stack<int> s;

    for(int i = 0; i < v; i++)
    {
        if(!visited[i])
        {
            topSort(i, adj, s, visited);
        }
    }

    vector<int> ans;

    while(!s.empty())
    {
        ans.push_back(s.top());
        s.pop();
    }

    return ans;
}

int main()
{

    cout << "Test Case: " << endl;
    int v = 4, e = 4;

    vector<vector<int>> edges = {
        {0, 1},
        {0, 2},
        {1, 3},
        {2, 3}
    };
    vector<int> result = topologicalSort(edges, v, e);
    cout << "Topological Order: ";

    for( int node: result)
    {
        cout << node << " ";
    } 

    cout << endl << endl;

    return 0;
}
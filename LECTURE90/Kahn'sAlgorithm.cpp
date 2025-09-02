#include<iostream>
#include<vector>
#include<list>
#include<queue>
#include<unordered_map>
using namespace std;

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)
{
    unordered_map<int, list<int>> adj;
    
    for(int i = 0; i < e; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
    }

    //find all indegrees
    vector<int> indegree(v, 0);  // Added initialization with zeros

    for(int i = 0; i < v; i++)
    {
        for(auto j : adj[i])
        {
            indegree[j]++;
        }
    }

    queue<int> q;

    for(int i = 0; i < v; i++)
    {
        if(indegree[i] == 0)
        {
            q.push(i);
        }
    }

    //do BFS
    vector<int> ans;

    while(!q.empty())
    {
        int front = q.front();
        q.pop();
        ans.push_back(front);

        //neighbour indegree update
        for(auto neighbour : adj[front])
        {
            indegree[neighbour]--;
            if(indegree[neighbour] == 0)
            {
                q.push(neighbour);
            }
        }
    }

    return ans;
}

int main()
{
    // Test Case 1: Simple linear dependency
    cout << "Test Case 1: Linear dependency (0->1->2->3)" << endl;
    int v1 = 4, e1 = 3;
    vector<vector<int>> edges1 = {{0, 1}, {1, 2}, {2, 3}};
    
    vector<int> result1 = topologicalSort(edges1, v1, e1);
    cout << "Topological order: ";
    for(int node : result1) {
        cout << node << " ";
    }
    cout << endl << endl;

    // Test Case 2: Multiple dependencies
    cout << "Test Case 2: Multiple dependencies" << endl;
    int v2 = 6, e2 = 6;
    vector<vector<int>> edges2 = {
        {5, 2}, {5, 0},
        {4, 0}, {4, 1},
        {2, 3}, {3, 1}
    };
    
    vector<int> result2 = topologicalSort(edges2, v2, e2);
    cout << "Topological order: ";
    for(int node : result2) {
        cout << node << " ";
    }
    cout << endl << endl;

    // Test Case 3: Star pattern
    cout << "Test Case 3: Star pattern (0->1, 0->2, 0->3)" << endl;
    int v3 = 4, e3 = 3;
    vector<vector<int>> edges3 = {{0, 1}, {0, 2}, {0, 3}};
    
    vector<int> result3 = topologicalSort(edges3, v3, e3);
    cout << "Topological order: ";
    for(int node : result3) {
        cout << node << " ";
    }
    cout << endl << endl;

    // Test Case 4: Empty graph
    cout << "Test Case 4: Empty graph (no edges)" << endl;
    int v4 = 3, e4 = 0;
    vector<vector<int>> edges4 = {};
    
    vector<int> result4 = topologicalSort(edges4, v4, e4);
    cout << "Topological order: ";
    for(int node : result4) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;

vector<int> bfsTraversal(int n, vector<vector<int>> &adj)
{
    vector<int> ans;
    unordered_map<int, bool> visited;
    queue<int> q;

    if(n > 0)
    {
        q.push(0);
        visited[0] = true;
    }

    while(!q.empty())
    {
        int frontNode = q.front();
        q.pop();
        ans.push_back(frontNode);

        for(auto neighbour : adj[frontNode])
        {
            if(!visited[neighbour])
            {
                q.push(neighbour);
                visited[neighbour] = true;
            }
        }
    }

    return ans;
}

int main()
{
    int n1 = 4;
    vector<vector<int>> adj1 = {
        {1, 2},
        {2},
        {0, 3},
        {3}
    };

    vector<int> result1 = bfsTraversal(n1, adj1);
    cout << "Example 1 BFS: ";
    for(int node : result1)
    {
        cout << node << " ";
    }

    cout << endl;

    return 0;
}
#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <set>
#include <climits>
using namespace std;

vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    // Create adjacency list
    unordered_map<int, list<pair<int, int>>> adj;

    for(int i = 0; i < edges; i++) {
        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];

        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }

    // Initialize distance vector with infinity
    vector<int> dist(vertices, INT_MAX);
    dist[source] = 0;

    // Set to store (distance, node) pairs
    set<pair<int, int>> st;
    st.insert(make_pair(0, source));

    while(!st.empty()) {
        auto top = *(st.begin());
        int nodeDistance = top.first;
        int topNode = top.second;

        st.erase(st.begin());

        // Traverse all neighbors
        for(auto neighbour : adj[topNode]) {
            if(nodeDistance + neighbour.second < dist[neighbour.first]) {
                // Check if the node already exists in the set
                auto record = st.find(make_pair(dist[neighbour.first], neighbour.first));
                
                // If found, erase it
                if(record != st.end()) {
                    st.erase(record);
                }

                // Update distance
                dist[neighbour.first] = nodeDistance + neighbour.second;
                
                // Insert updated distance
                st.insert(make_pair(dist[neighbour.first], neighbour.first));
            }
        }
    }

    return dist;
}

int main() {
    // Test case 1
    int vertices = 5;
    int edges = 7;
    int source = 0;
    
    vector<vector<int>> graph = {
        {0, 1, 7},
        {0, 2, 1},
        {0, 3, 2},
        {1, 2, 3},
        {1, 3, 5},
        {1, 4, 1},
        {3, 4, 7}
    };

    vector<int> distances = dijkstra(graph, vertices, edges, source);

    cout << "Shortest distances from node " << source << " to all other nodes:" << endl;
    for(int i = 0; i < vertices; i++) {
        cout << "Node " << i << ": ";
        if(distances[i] == INT_MAX) {
            cout << "Unreachable";
        } else {
            cout << distances[i];
        }
        cout << endl;
    }

    cout << "\n" << string(40, '-') << "\n" << endl;

    // Test case 2 - Disconnected graph
    int vertices2 = 4;
    int edges2 = 3;
    int source2 = 0;
    
    vector<vector<int>> graph2 = {
        {0, 1, 1},
        {1, 2, 2},
        {2, 3, 3}
        // Node 0 is connected, but what about other nodes?
    };

    vector<int> distances2 = dijkstra(graph2, vertices2, edges2, source2);

    cout << "Shortest distances from node " << source2 << " to all other nodes:" << endl;
    for(int i = 0; i < vertices2; i++) {
        cout << "Node " << i << ": ";
        if(distances2[i] == INT_MAX) {
            cout << "Unreachable";
        } else {
            cout << distances2[i];
        }
        cout << endl;
    }

    return 0;
}
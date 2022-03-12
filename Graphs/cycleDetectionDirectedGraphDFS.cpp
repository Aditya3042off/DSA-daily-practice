// Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, check whether it contains any cycle or not.

// https://www.youtube.com/watch?v=uzVUw90ZFIg&list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw&index=12
// https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1#

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to detect cycle in a directed graph.

    bool checkCyclic(vector<int> adj[], vector<int> &visited, vector<int> &path, int k)
    {
        visited[k] = 1;
        path[k] = 1;

        for (int i : adj[k])
        {
            if (path[i])
                return true;
            if (visited[i])
                continue;

            if (checkCyclic(adj, visited, path, i))
                return true;
        }
        path[k] = 0;
        return false;
    }

    bool isCyclic(int v, vector<int> adj[])
    {
        // code here
        vector<int> visited(v, 0);
        vector<int> path(v, 0);

        for (int i = 0; i < v; i++)
        {
            if (visited[i])
                continue;

            if (checkCyclic(adj, visited, path, i))
                return true;
        }
        return false;
    }
};

// { Driver Code Starts.

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
// } Driver Code Ends
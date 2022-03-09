// https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1#
// https://www.youtube.com/watch?v=A8ko93TyOns&list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw&index=8

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    bool bfs(vector<int> &visited, vector<int> adj[], int k)
    {
        queue<pair<int, int>> q;
        visited[k] = 1;
        q.push({k, -1});

        while (!q.empty())
        {
            auto node = q.front();
            q.pop();

            for (int i : adj[node.first])
            {
                if (i != node.second and visited[i])
                    return true;
                if (visited[i])
                    continue;

                visited[i] = 1;
                q.push({i, node.first});
            }
        }
        return false;
    }

    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[])
    {
        // Code here
        vector<int> visited(V, 0);

        for (int i = 0; i < V; i++)
        {
            if (visited[i])
                continue;
            if (bfs(visited, adj, i))
                return true;
        }
        return false;
    }
};

// { Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
} // } Driver Code Ends
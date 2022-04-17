// https://www.geeksforgeeks.org/check-given-graph-tree/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;
// if this returns false that means there is no cycle
bool solve(vector<vector<int>> &adj, int k, int parent, vector<int> &visited)
{
    visited[k] = 1;
    for (auto neibr : adj[k])
    {
        if (visited[neibr] and neibr != parent)
            return true;
        if (visited[neibr]) // if parent we donot do anything
            continue;
        if (solve(adj, neibr, k, visited))
            return true;
    }
    return false;
}

bool isTree(vector<vector<int>> &adj, int v)
{
    // Write your code here.
    vector<int> visited(v, 0);
    // checks for cycle
    if (solve(adj, 0, -1, visited))
        return false;
    // checks if tree is connect
    for (bool i : visited)
        if (!i)
            return false;
    return true;
}

// Do not change this part of the code. You only need to complete the isTree function above.
int main()
{
    int v, e;
    cin >> v >> e;

    vector<vector<int>> adj(v);

    for (int i = 0, a, b; i < e; ++i)
    {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    if (isTree(adj, v))
    {
        cout << "True";
    }
    else
    {
        cout << "False";
    }

    return 0;
}
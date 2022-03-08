#include <bits/stdc++.h>
using namespace std;

void dfs(vector<int> &visited, vector<int> &dfsAns, vector<int> list[], int k)
{
    visited[k] = 1;
    dfsAns.push_back(k);

    for (auto i : list[k])
    {
        if (visited[i])
            continue;
        dfs(visited, dfsAns, list, i);
    }
    return;
}

int main()
{
    int N, E;
    cout << "Enter the Number of nodes and edges:  ";
    cin >> N >> E;
    vector<int> list[N + 1];

    cout << "Enter the edges: " << endl;
    for (int i = 0; i < E; i++)
    {
        int a, b;
        cin >> a >> b;
        list[a].push_back(b);
        list[b].push_back(a);
    }

    vector<int> visited(N + 1, 0);
    vector<int> dfsAns;

    // map may have multiple components
    for (int i = 1; i < N + 1; i++)
    {
        if (visited[i])
            continue;

        dfs(visited, dfsAns, list, i);
    }

    for (auto i : dfsAns)
        cout << i << " ";
}
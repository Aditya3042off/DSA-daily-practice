#include <bits/stdc++.h>
using namespace std;

void bfs(vector<int> &bfsAns, vector<int> &visited, vector<int> list[], int k)
{
    queue<int> q;
    q.push(k);
    visited[k] = 1;

    while (!q.empty())
    {
        int curr = q.front();
        bfsAns.push_back(curr);
        q.pop();
        for (int i : list[curr])
        {
            if (visited[i])
                continue;

            visited[i] = 1;
            q.push(i);
        }
    }
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
    vector<int> bfsAns;

    // graph may have multiple components
    for (int i = 1; i < N + 1; i++)
    {
        if (visited[i])
            continue;

        bfs(bfsAns, visited, list, i);
    }
    for (auto i : bfsAns)
        cout << i << " ";
}
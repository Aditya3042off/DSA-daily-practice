#include <bits/stdc++.h>
using namespace std;

void topoSort(vector<int> list[], int v, vector<int> &indegree, vector<int> &topo)
{
    queue<int> q;
    for (int i = 0; i < v; i++)
        if (indegree[i] == 0)
            q.push(i);

    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        topo.push_back(curr);

        for (int adj : list[curr])
        {
            indegree[adj]--;
            if (!indegree[adj])
                q.push(adj);
        }
    }
}

int main()
{
    int v = 6;
    vector<int> list[6] = {{}, {}, {3}, {1}, {0, 1}, {0, 2}};

    vector<int> indegree(v, 0);
    vector<int> topo;

    for (int i = 0; i < v; i++)
    {
        for (auto j : list[i])
            indegree[j]++;
    }

    topoSort(list, v, indegree, topo);

    for (int i : topo)
        cout << i << " ";
}
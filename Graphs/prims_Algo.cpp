#include <bits/stdc++.h>
using namespace std;

void prims(vector<pair<int, int>> graph[], vector<int> &parent, int v)
{
    vector<int> dist(v, 1e9);
    vector<bool> inMst(v, false);

    inMst[0] = true;
    int temp = INT_MAX;
    int idx;
    v = v - 1;

    while (v--)
    {
        for (int i = 0; i < v; i++)
        {
            if (inMst[i])
            {
                for (auto neighbour : graph[i])
                {
                    if (dist[neighbour.first] > neighbour.second and !inMst[neighbour.first])
                    {
                        dist[neighbour.first] = neighbour.second;
                        parent[neighbour.first] = i;
                    }
                }
            }
            else
            {
                if (temp < dist[i])
                    continue;
                idx = i;
                temp = dist[i];
            }
        }
        inMst[idx] = true;
    }
}

int main()
{
    int v = 5;
    vector<int> parent(v, -1);
    vector<pair<int, int>> graph[v] = {{{1, 2}, {3, 6}},
                                       {{0, 2}, {2, 3}, {3, 8}, {4, 5}},
                                       {{1, 3}, {4, 7}},
                                       {{0, 6}, {1, 8}},
                                       {{1, 5}, {2, 7}}};
    prims(graph, parent, v);
    for (int i = 1; i < v; i++)
        cout << parent[i] << "->" << i << " ";
}
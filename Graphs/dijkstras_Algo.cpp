#include <bits/stdc++.h>
using namespace std;

void dijkstra(vector<pair<int, int>> graph[], vector<int> &dist, int src)
{
    pair<int, int> temp;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0});

    while (!pq.empty())
    {
        temp = pq.top();
        pq.pop();

        for (auto i : graph[temp.second])
        {
            if (dist[i.first] > temp.first + i.second)
            {
                dist[i.first] = temp.first + i.second;
                pq.push({temp.first + i.second, i.first});
            }
        }
    }
    return;
}

int main()
{
    vector<pair<int, int>> graph[] = {{{1, 4}, {7, 8}},
                                      {{0, 4}, {2, 8}, {7, 11}},
                                      {{1, 8}, {3, 7}, {5, 4}, {8, 2}},
                                      {{2, 7}, {4, 9}, {5, 14}},
                                      {{3, 9}, {5, 10}},
                                      {{2, 4}, {3, 14}, {4, 10}, {6, 2}},
                                      {{5, 2}, {7, 1}, {8, 6}},
                                      {{0, 8}, {1, 11}, {6, 1}, {8, 7}},
                                      {{2, 2}, {6, 6}, {7, 7}}};

    vector<int> dist(9, 1e9);
    dist[0] = 0;

    dijkstra(graph, dist, 0);

    for (int i : dist)
        cout << i << " ";
}
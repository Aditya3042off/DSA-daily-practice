#include <bits/stdc++.h>
using namespace std;

void dijkstra(vector<pair<int, int>> list[], int src, vector<int> &dist, vector<int> &parent)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src});

    while (!pq.empty())
    {
        int distance = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for (auto edge : list[node])
        {
            if (dist[edge.first] > distance + edge.second)
            {
                dist[edge.first] = distance + edge.second;
                pq.push({dist[edge.first], edge.first});
                parent[edge.first] = node;
            }
        }
    }
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

    vector<int> dist(9, 1e9), parent(9, -1);
    dist[0] = 0;
    parent[0] = 0;

    int destination = 4;

    dijkstra(graph, 0, dist, parent);

    // struggle to print path

    vector<int> path;

    int temp = destination;

    while (temp != parent[temp])
    {
        path.push_back(temp);
        temp = parent[temp];
    }

    path.push_back(0);

    reverse(path.begin(), path.end());

    for (int i : path)
    {
        cout << " -> " << i;
    }
}
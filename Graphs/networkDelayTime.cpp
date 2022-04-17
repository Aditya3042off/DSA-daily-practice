// You are given a network of n nodes, labeled from 1 to n. You are also given times, a list of travel times as directed edges times[i] = (ui, vi, wi), where ui is the source node, vi is the target node, and wi is the time it takes for a signal to travel from source to target.

// We will send a signal from a given node k. Return the time it takes for all the n nodes to receive the signal. If it is impossible for all the n nodes to receive the signal, return -1.

// Input: times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2
// Output: 2
// Example 2:

// Input: times = [[1,2,1]], n = 2, k = 1
// Output: 1
// Example 3:

// Input: times = [[1,2,1]], n = 2, k = 2
// Output: -1

// https://www.youtube.com/watch?v=EaphyqKU4PQ&list=PLot-Xpze53ldBT_7QA8NVot219jFNr_GI&index=8
class Solution
{
public:
    int findTime(vector<pair<int, int>> list[], int n, int k, vector<int> &dist)
    {
        priority_queue<pair<int, int>> pq;
        pq.push({0, k});

        while (!pq.empty())
        {
            int time = pq.top().first;
            int src = pq.top().second;
            pq.pop();

            for (auto adj : list[src])
            {
                if (time + adj.second < dist[adj.first])
                {
                    dist[adj.first] = time + adj.second;
                    pq.push({dist[adj.first], adj.first});
                }
            }
        }
        int Time = INT_MIN;
        for (int i = 0; i < n + 1; i++)
        {
            if (i != 0 and dist[i] == 1e9)
                return -1;
            if (i != 0)
                Time = max(Time, dist[i]);
        }
        return Time;
    }

    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        vector<pair<int, int>> list[n + 1];

        for (auto node : times)
        {
            list[node[0]].push_back({node[1], node[2]});
        }

        vector<int> dist(n + 1, 1e9);
        dist[k] = 0;

        return findTime(list, n, k, dist);
    }
};
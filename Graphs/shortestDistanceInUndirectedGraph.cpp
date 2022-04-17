#include <bits/stdc++.h>
using namespace std;

class Solution
{

    int solve(vector<int> &visited, vector<int> &dist, vector<int> list[], int k)
    {
        queue<pair<int, int>> q;
        pair<int, int> temp;
        q.push({k, 0});
        visited[k] = 1;

        while (!q.empty())
        {
            temp = q.front();
            q.pop();

            for (int i : list[k])
            {
                if (visited[i])
                {
                    if (dist[i] < temp.second + 1)
                        continue;
                }
                dist[i] = temp.second + 1;
                q.push({i, dist[i]});
                visited[i] = 1;
            }
        }
    }

    int getShortestPath(vector<int> list[], int v)
    {
        vector<int> visited(v, 0);
        vector<int> dist(v, INT_MAX);

        for (int i = 0; i < v; i++)
        {
            solve(visited, dist, list, i);
        }
    }
};

int main()
{
}
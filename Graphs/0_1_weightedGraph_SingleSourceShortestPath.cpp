#include <bits/stdc++.h>
using namespace std;

struct node
{
    int graphnode;
    int dist;
    node(int _graphnode, int _dist)
    {
        graphnode = _graphnode;
        dist = _dist;
    }
};

void findShortestPath(vector<pair<int, int>> adjList[], int numOfNodes, int src)
{
    deque<node> dq;
    vector<int> distances(numOfNodes, 1e9);
    distances[src] = 0;

    dq.push_back(node(src, 0));

    while (!dq.empty())
    {
        int currNode = dq.front().graphnode;
        int dist = dq.front().dist;

        dq.pop_front();

        for (pair<int, int> adj : adjList[currNode])
        {
            int adjNode = adj.first;
            int adjNodeDistance = adj.second;

            if (dist + adjNodeDistance >= distances[adjNode])
                continue;

            distances[adjNode] = dist + adjNodeDistance;
            if (adjNodeDistance == 0)
                dq.push_front(node(adjNode, distances[adjNode]));
            else
                dq.push_back(node(adjNode, distances[adjNode]));
        }
    }
}

int main()
{
}
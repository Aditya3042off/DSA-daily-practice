// // https://www.youtube.com/watch?v=7K4qjtDwOQo&list=PLN4aKSfpk8TQwHTE3ZAz6felbFY2UcLYR&index=4&t=4432s
// // https://www.lintcode.com/problem/788/description

// here is a ball in a maze with empty spaces and walls.
// The ball can go through empty spaces by rolling up, down, left or right, but it won't stop rolling
// until hitting a wall. When the ball stops, it could choose the next direction.

// Given the ball's start position, the destination and the maze, find the shortest distance
// for the ball to stop at the destination. The distance is defined by the number of empty spaces
// traveled by the ball from the start position (excluded) to the destination (included).
// If the ball cannot stop at the destination, return -1.

// The maze is represented by a binary 2D array. 1 means the wall and 0 means the empty space.
// You may assume that the borders of the maze are all walls. The start and destination coordinates
// are represented by row and column indexes.

#include <bits/stdc++.h>
class Solution
{
public:
    int shortestDistance(vector<vector<int>> &maze, vector<int> &start, vector<int> &destination)
    {
        // write your code here
        int startx = start[0];
        int starty = start[1];
        int endx = destination[0];
        int endy = destination[1];

        int n = maze.size();
        int m = maze[0].size();

        vector<int> distances(n * m + 1, 1e9);
        distances[startx * m + starty] = 0;

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({0, {startx, starty}});

        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};

        while (!pq.empty())
        {
            int dist = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();

            for (int i = 0; i < 4; i++)
            {
                int newx = x;
                int newy = y;
                int cellsCovered = 0;
                while (newx + dx[i] >= 0 and newx + dx[i] <= n - 1 and newy + dy[i] >= 0 and newy + dy[i] <= m - 1 and maze[newx + dx[i]][newy + dy[i]] == 0)
                {
                    newx += dx[i];
                    newy += dy[i];
                    cellsCovered++;
                }

                if (distances[newx * m + newy] <= dist + cellsCovered)
                    continue;
                distances[newx * m + newy] = dist + cellsCovered;

                pq.push({distances[newx * m + newy], {newx, newy}});
            }
        }

        if (distances[endx * m + endy] == 1e9)
            return -1;
        return distances[endx * m + endy];
    }
};

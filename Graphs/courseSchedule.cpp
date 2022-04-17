// There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

// For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
// Return true if you can finish all courses. Otherwise, return false.

// Example 1:

// Input: numCourses = 2, prerequisites = [[1,0]]
// Output: true
// Explanation: There are a total of 2 courses to take.
// To take course 1 you should have finished course 0. So it is possible.
// Example 2:

// Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
// Output: false
// Explanation: There are a total of 2 courses to take.
// To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.

// https://www.youtube.com/watch?v=EgI5nU9etnU&list=PLot-Xpze53ldBT_7QA8NVot219jFNr_GI&index=2

// According to question we able to take courses according to given prerequisites is similar to given a graph
// we able to write its topo sort or not.

// For toposort to be possible there should be no cycles. so here in this problem we are just checking for cycles

class Solution
{
public:
    bool checkCycle(vector<int> &visited, vector<int> &path, vector<int> list[], int node)
    {
        visited[node] = 1;
        path[node] = 1;

        for (int adj : list[node])
        {
            if (path[adj])
                return true;
            if (visited[adj])
                continue;

            if (checkCycle(visited, path, list, adj))
                return true;
        }
        path[node] = 0;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<int> list[numCourses];
        vector<int> visited(numCourses, 0);
        vector<int> path(numCourses, 0);

        for (auto node : prerequisites)
        {
            list[node[1]].push_back(node[0]);
        }

        for (int i = 0; i < numCourses; i++)
        {
            if (visited[i])
                continue;

            if (checkCycle(visited, path, list, i))
                return false;
        }
        return true;
    }
};
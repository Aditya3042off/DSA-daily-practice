// Given a matrix cost of size n where cost[i][j] denotes the cost of moving from city i to city j. Your task is to complete a tour from the city 0 (0 based index) to all other cities such that you visit each city atmost once and then at the end come back to city 0 in min cost.

// Example 1:

// Input: cost = {{0,111},{112,0}}
// Output: 223
// Explanation: We can visit 0->1->0 and
// cost = 111 + 112.
// Example 2:

// Input: cost = {{0,1000,5000},{5000,0,1000},
// {1000,5000,0}}
// Output: 3000
// Explanation: We can visit 0->1->2->0 and cost
// = 1000+1000+1000 = 3000

// Your Task:
// You don't need to read or print anyhting. Your task is to complete the function total_cost() which takes cost as input parameter and returns the total cost to visit each city exactly once starting from city 0 and again comback to city 0.

// Expected Time Complexity: O(2n * n2)
// Expected Space Compelxity: O(2n * n)

// Constraints:
// 1 <= n <= 10
// 1 <= cost[i][j] <= 103

// https://practice.geeksforgeeks.org/problems/travelling-salesman-problem2732/1#
// https://www.youtube.com/watch?v=QukpHtZMAtM&list=PLb3g_Z8nEv1icFNrtZqByO1CrWVHLlO5g&index=4

// { Driver Code Starts

// in mask 0 bit means city already visited,1 bit means city yet to be visited

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    int findCost(vector<vector<int>> &cost, vector<vector<int>> &dp, int currCity, int remCitiesMask)
    {
        int n = cost.size();
        if (remCitiesMask == 0)
            return cost[currCity][0];
        if (dp[currCity][remCitiesMask] != -1)
            return dp[currCity][remCitiesMask];

        int answer = INT_MAX;

        for (int i = 0; i < n; i++)
        {
            if (remCitiesMask & (1 << i))
                answer = min(answer, cost[currCity][i] + findCost(cost, dp, i, remCitiesMask & ~(1 << i)));
        }

        return dp[currCity][remCitiesMask] = answer;
    }

    int total_cost(vector<vector<int>> cost)
    {
        // Code here
        int n = cost.size();

        vector<vector<int>> dp(n, vector<int>((1 << n) - 1, -1));

        return findCost(cost, dp, 0, (1 << n) - 2);
    }
};

// { Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        vector<vector<int>> cost(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> cost[i][j];
        Solution obj;
        int ans = obj.total_cost(cost);
        cout << ans << "\n";
    }
    return 0;
} // } Driver Code Ends
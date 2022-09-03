// Problem Statement

// Let there be N workers and N jobs. Any worker can be assigned to perform any job, incurring some cost that may vary depending on the work-job assignment. It is required to perform all jobs by assigning exactly one worker to each job and exactly one job to each agent in such a way that the total cost of the assignment is minimized.

// Input Format
// Number of workers and job: N
// Cost matrix C with dimension N*N where C(i,j) is the cost incurred on assigning ith Person to jth Job.

// Sample Input
// 4

// [
// 9 2 7 8
// 6 4 3 7
// 5 8 1 8
// 7 6 9 4
// ]

// Sample Output
// 13

// Constraints
// N <= 20

// i am using Dp to store the min cost
// using bit mask dp
//

// let us assume we have 7 people and 7 jobs
// initial mask is 0000000
// 0 -> means that person is not assigned to any Job
// 1 -> means that person is assigned to one Job
// so my dp will be a array

// jobs are assigned sequentially that means 1st job -> 2nd job -> 3rd job -> 4th job -> 5th job -> 6th job -> 7th job like that
// length of dp array will be (1<<7)
// 0001101 -> this says person 1,3,4 have been assigned job and jobs are assigned sequentially
// so dp[0001101] will be an overlapping subproblem which doesnot depend on which persons got which job perviously
// like it doesn't care if 1st job is assigned to 1st person or 3rd or 4th
// it doesnt care how we achieved that state

// now in a dp cell like dp[0001101] what we store is => the min cost of assigning the remaining jobs which are
// job4-job7 to people which are left that are p7,6,5,2
// our final ans will be in dp[0000000] which is the min cost of assigining all jobs to all rem people

#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &dp, vector<vector<int>> &costs, int idx, int mask, int n)
{
    if (idx == n)
        return 0;

    if (dp[mask] != -1)
        return dp[mask];

    int temp = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        if ((mask & (1 << i)) == 0)
            temp = min(temp, costs[i][idx] + solve(dp, costs, idx + 1, mask | (1 << i), n));
    }

    return dp[mask] = temp;
}

int main()
{
    vector<vector<int>> costs = {
        {9, 2, 7, 8},
        {6, 4, 3, 7},
        {5, 8, 1, 8},
        {7, 6, 9, 4}};

    int n = 4;
    vector<int> dp(1 << 4, -1);

    cout << solve(dp, costs, 0, 0, n);
}
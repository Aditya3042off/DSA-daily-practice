// Ninja is planing this ‘N’ days-long training schedule. Each day, he can perform any one of these three activities. (Running, Fighting Practice or Learning New Moves). Each activity has some merit points on each day. As Ninja has to improve all his skills, he can’t do the same activity in two consecutive days. Can you help Ninja find out the maximum merit points Ninja can earn?
// You are given a 2D array of size N*3 ‘POINTS’ with the points corresponding to each day and activity. Your task is to calculate the maximum number of merit points that Ninja can earn.
// For Example
// If the given ‘POINTS’ array is [[1,2,5], [3 ,1 ,1] ,[3,3,3] ],the answer will be 11 as 5 + 3 + 3.
// Input Format:
// The first line of the input contains an integer, 'T,’ denoting the number of test cases.

// The first line of each test case contains a single integer,' N’, denoting the number of days.

// The next ‘N’ lines of each test case have 3 integers corresponding to POINTS[i].
// Output Format:
// For each test case, return an integer corresponding to the maximum coins  Ninja can collect.
// Note:
// You do not need to print anything. It has already been taken care of. Just implement the given function.

// https://www.youtube.com/watch?v=AE39gJYuRog&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=8&t=1927s

#include <bits/stdc++.h>
using namespace std;

int solve(vector<vector<int>> &points, vector<vector<int>> &arr, int day, int last)
{
    if (day < 0)
        return 0;

    if (day != 0 and arr[day][last] != -1)
        return arr[day][last];

    int ans = INT_MIN;
    for (int i = 0; i < 3; i++)
    {
        if (i != last)
        {
            int temp = solve(points, arr, day - 1, i) + points[day][i];
            ans = max(ans, temp);
        }
    }
    return arr[day][last] = ans;
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    vector<vector<int>> arr(n, vector<int>(4, -1));

    arr[0][0] = points[0][0];
    arr[0][1] = points[0][1];
    arr[0][2] = points[0][2];
    return solve(points, arr, n - 1, 3);
}
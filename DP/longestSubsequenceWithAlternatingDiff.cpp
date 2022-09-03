// Given a list of integers nums, return the length of the longest subsequence where the difference
// between consecutive numbers alternate between positive and negative.
// The first difference may be either positive or negative.

// Constraints

// n ≤ 5,000 where n is the length of nums

// Example 1
// Input
// nums = [5, 9, 3, 1, 2, 8, 3, 6]
// Output
// 6
// Explanation
// One possible longest alternating subsequence is [5, 9, 1, 8, 3, 6]
// and the differences are [4, -8, 7, -5, 3] which alternate.

#include <bits/stdc++.h>
using namespace std;

// 1-> prev diff is -ve
// 2->pre diff +ve
// 0-> just given to handle case for first index element or also used for 0 diff

int solve(vector<int> &nums)
{
    int n = nums.size();
    if (n == 0)
        return 0;
    vector<int> next(3, 0), curr(3);

    next[0] = next[1] = next[2] = 1;

    for (int idx = n - 2; idx >= 0; idx--)
    {
        for (int prev = 2; prev >= 0; prev--)
        {
            int maxi = INT_MIN;

            int diff = nums[idx] - nums[idx + 1];

            if (diff > 0 and prev != 2)
                maxi = max(maxi, 1 + next[2]);
            else if (diff < 0 and prev != 1)
                maxi = max(maxi, 1 + next[1]);
            maxi = max(maxi, next[prev]);

            curr[prev] = maxi;
        }
        next = curr;
    }
    return next[0];
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
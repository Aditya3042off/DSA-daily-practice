// Given an array of distinct integers candidates and a target integer target,
// return a list of all unique combinations of candidates where the chosen numbers sum to target.
// You may return the combinations in any order.

// The same number may be chosen from candidates an unlimited number of times.
// Two combinations are unique if the frequency of at least one of the chosen numbers is different.

// It is guaranteed that the number of unique combinations that sum up to target is less than 150 combinations
// for the given input.

// Example 1:

// Input: candidates = [2,3,6,7], target = 7
// Output: [[2,2,3],[7]]
// Explanation:
// 2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
// 7 is a candidate, and 7 = 7.
// These are the only two combinations.
// Example 2:

// Input: candidates = [2,3,5], target = 8
// Output: [[2,2,2,2],[2,3,3],[3,5]]
// Example 3:

// Input: candidates = [2], target = 1
// Output: []

// https://www.youtube.com/watch?v=OyZFFqQtu98&list=PLgUwDviBIf0rGlzIn_7rsaR2FQ5e6ZOL9&index=8&t=1259s
// https://leetcode.com/problems/combination-sum-ii/discuss/1277764/Combination-Sum-I-II-and-III-%2B-Subsets-I-and-II-%2B-Permutations-I-and-II%3A-One-stop-C%2B%2B-solutions

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void Solve(vector<vector<int>> &ans, vector<int> &temp, vector<int> &candidates, int idx, int target)
    {
        if (idx == candidates.size())
        {
            if (target != 0)
                return;

            ans.push_back(temp);
            return;
        }

        if (target == 0)
        {
            ans.push_back(temp);
            return;
        }
        if (target < 0)
            return;

        // picking the number
        temp.push_back(candidates[idx]);
        Solve(ans, temp, candidates, idx, target - candidates[idx]);

        temp.pop_back();

        // not picking
        Solve(ans, temp, candidates, idx + 1, target);

        return;
    }

    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {

        vector<vector<int>> ans;
        vector<int> temp;
        Solve(ans, temp, candidates, 0, target);
        return ans;
    }
};
// Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

// Each number in candidates may only be used once in the combination.

// Note: The solution set must not contain duplicate combinations.

// Example 1:

// Input: candidates = [10,1,2,7,6,1,5], target = 8
// Output:
// [
// [1,1,6],
// [1,2,5],
// [1,7],
// [2,6]
// ]
// Example 2:

// Input: candidates = [2,5,2,1,2], target = 5
// Output:
// [
// [1,2,2],
// [5]
// ]

// https://www.youtube.com/watch?v=G1fRTGRxXU8&list=PLgUwDviBIf0rGlzIn_7rsaR2FQ5e6ZOL9&index=9
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
            if (target == 0)
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

        // picking the element
        temp.push_back(candidates[idx]);
        Solve(ans, temp, candidates, idx + 1, target - candidates[idx]);
        temp.pop_back();

        // not picking element
        while (idx + 1 < candidates.size() && candidates[idx + 1] == candidates[idx])
            idx++;
        Solve(ans, temp, candidates, idx + 1, target);
        return;
    }

    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> temp;
        Solve(ans, temp, candidates, 0, target);
        return ans;
    }
};
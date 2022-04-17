// Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

// Example 1:

// Input: nums = [1,2,3,1]
// Output: true
// Example 2:

// Input: nums = [1,2,3,4]
// Output: false
// Example 3:

// Input: nums = [1,1,1,3,3,4,3,2,4,2]
// Output: true

// https://www.youtube.com/watch?v=3OamzN90kPg&list=PLot-Xpze53ldVwtstag2TL4HQhAnC8ATf&index=3&t=342s

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        unordered_set<int> st;
        for (int i : nums)
        {
            if (st.find(i) != st.end())
                return true;
            st.insert(i);
        }
        return false;
    }
};
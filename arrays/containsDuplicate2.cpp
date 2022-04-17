// Given an integer array nums and an integer k, return true if there are two distinct indices i and j in the array such that nums[i] == nums[j] and abs(i - j) <= k.

// Example 1:

// Input: nums = [1,2,3,1], k = 3
// Output: true
// Example 2:

// Input: nums = [1,0,1,1], k = 1
// Output: true
// Example 3:

// Input: nums = [1,2,3,1,2,3], k = 2
// Output: false

// https://www.youtube.com/watch?v=279hDrM3BiE

class Solution
{
public:
    bool containsNearbyDuplicate(vector<int> &arr, int k)
    {
        unordered_map<int, int> mp;

        for (int i = 0; i < arr.size(); i++)
        {
            if (mp.find(arr[i]) == mp.end())
                mp[arr[i]] = i;
            else
            {
                if (abs(mp[arr[i]] - i) <= k)
                    return true;
                mp[arr[i]] = i;
            }
        }
        return false;
    }
};
// leetcode contest 286

// Given two 0-indexed integer arrays nums1 and nums2, return a list answer of size 2 where:

// answer[0] is a list of all distinct integers in nums1 which are not present in nums2.
// answer[1] is a list of all distinct integers in nums2 which are not present in nums1.
// Note that the integers in the lists may be returned in any order.

// Example 1:

// Input: nums1 = [1,2,3], nums2 = [2,4,6]
// Output: [[1,3],[4,6]]
// Explanation:
// For nums1, nums1[1] = 2 is present at index 0 of nums2, whereas nums1[0] = 1 and nums1[2] = 3 are not present in nums2. Therefore, answer[0] = [1,3].
// For nums2, nums2[0] = 2 is present at index 1 of nums1, whereas nums2[1] = 4 and nums2[2] = 6 are not present in nums2. Therefore, answer[1] = [4,6].
// Example 2:

// Input: nums1 = [1,2,3,3], nums2 = [1,1,2,2]
// Output: [[3],[]]
// Explanation:
// For nums1, nums1[2] and nums1[3] are not present in nums2. Since nums1[2] == nums1[3], their value is only included once and answer[0] = [3].
// Every integer in nums2 is present in nums1. Therefore, answer[1] = [].

class Solution
{
public:
    vector<vector<int>> findDifference(vector<int> &nums1, vector<int> &nums2)
    {
        set<int> s1, s2;

        int size1 = nums1.size();
        int size2 = nums2.size();
        for (int i = 0; i < size1; i++)
            s1.insert(nums1[i]);
        for (int i = 0; i < size2; i++)
            s2.insert(nums2[i]);

        vector<int> ans1, ans2;

        while (!s1.empty() and !s2.empty())
        {
            if (*(s1.begin()) == *(s2.begin()))
            {
                s1.erase(s1.begin());
                s2.erase(s2.begin());
            }
            else if (*(s1.begin()) < *(s2.begin()))
            {
                ans1.push_back(*(s1.begin()));
                s1.erase(s1.begin());
            }
            else
            {
                ans2.push_back(*(s2.begin()));
                s2.erase(s2.begin());
            }
        }

        if (s1.empty() and s2.empty())
            return {ans1, ans2};
        else if (!s1.empty())
        {
            while (!s1.empty())
            {
                ans1.push_back(*(s1.begin()));
                s1.erase(s1.begin());
            }
        }
        else
        {
            while (!s2.empty())
            {
                ans2.push_back(*(s2.begin()));
                s2.erase(s2.begin());
            }
        }
        return {ans1, ans2};
    }
};
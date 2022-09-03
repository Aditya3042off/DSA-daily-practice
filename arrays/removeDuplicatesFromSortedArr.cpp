// Example 1:

// Input: nums = [1,1,2]
// Output: 2, nums = [1,2,_]
// Explanation: Your function should return k = 2, with the first two elements of nums being 1 and 2 respectively.
// It does not matter what you leave beyond the returned k (hence they are underscores).
// Example 2:

// Input: nums = [0,0,1,1,1,2,2,3,3,4]
// Output: 5, nums = [0,1,2,3,4,_,_,_,_,_]
// Explanation: Your function should return k = 5, with the first five elements of nums being 0, 1, 2, 3, and 4 respectively.
// It does not matter what you leave beyond the returned k (hence they are underscores).

// https://www.youtube.com/watch?v=Fm_p9lJ4Z_8&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=42

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int i = 0, j = 1;
        int n = nums.size();
        if (n == 1)
            return 1;

        while (j < n)
        {
            if (nums[i] == nums[j])
                j++;
            else
                nums[++i] = nums[j++];
        }
        return i + 1;
    }
};
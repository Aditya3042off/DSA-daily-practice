// Given an integer array nums where every element appears three times except for one, which appears exactly once. Find the single element and return it.

// You must implement a solution with a linear runtime complexity and use only constant extra space.

 

// Example 1:

// Input: nums = [2,2,3,2]
// Output: 3
// Example 2:

// Input: nums = [0,1,0,1,0,1,99]
// Output: 99

// https://leetcode.com/problems/single-number-ii/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> arr(32,0);
        
        for(int num : nums) {
            for(int i=0;i<32;i++)
                if(num & (1<<i)) arr[i]++;
        }
        
        int ans = 0;
        int temp = 1;
        
        for(int i=0;i<32;i++){
            if(arr[i] % 3 == 1) ans = ans | temp;
            if(i != 31) temp = temp << 1;
        }
        
        return ans;
    }
};
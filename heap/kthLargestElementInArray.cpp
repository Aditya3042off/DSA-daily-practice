// Given an integer array nums and an integer k, return the kth largest element in the array.

// Note that it is the kth largest element in the sorted order, not the kth distinct element.

// Example 1:

// Input: nums = [3,2,1,5,6,4], k = 2
// Output: 5
// Example 2:

// Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
// Output: 4

// https://www.youtube.com/watch?v=aXJ-p3Qa4TY&list=PLEJXowNB4kPyP2PdMhOUlTY6GrRIITx28&index=10

class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        priority_queue<int> pq;
        for (int i : nums)
            pq.push(i);

        for (int i = 0; i < k - 1; i++)
            pq.pop();

        return pq.top();
    }
};
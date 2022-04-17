// You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

// Return the max sliding window

// Example 1:

// Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
// Output: [3,3,5,5,6,7]
// Explanation:
// Window position                Max
// ---------------               -----
// [1  3  -1] -3  5  3  6  7       3
//  1 [3  -1  -3] 5  3  6  7       3
//  1  3 [-1  -3  5] 3  6  7       5
//  1  3  -1 [-3  5  3] 6  7       5
//  1  3  -1  -3 [5  3  6] 7       6
//  1  3  -1  -3  5 [3  6  7]      7
// Example 2:

// Input: nums = [1], k = 1
// Output: [1]

// https://www.youtube.com/watch?v=LiSdD3ljCIE&list=PLEJXowNB4kPyP2PdMhOUlTY6GrRIITx28&index=14

class Solution
{
public:
    // using deque
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        deque<pair<int, int>> dq;
        vector<int> ans;
        int i = 0, j = 0;

        while (j <= nums.size() - 1)
        {
            if (j >= k - 1)
            {
                while (!dq.empty() and dq.front().second < i)
                    dq.pop_front();
                i++;
            }
            while (!dq.empty() and dq.back().first < nums[j])
                dq.pop_back();
            dq.push_back({nums[j], j});
            if (j >= k - 1)
                ans.push_back(dq.front().first);
            j++;
        }
        return ans;
    }

    // using priority queue
    //     vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    //         priority_queue<int> pq,temp;
    //         vector<int> ans;

    //         for(int i=0;i<k;i++)
    //             pq.push(nums[i]);
    //         ans.push_back(pq.top());

    //         int j=k,i=1;

    //         while(j <= nums.size()-1){
    //             pq.push(nums[j]);
    //             temp.push(nums[i-1]);

    //             while(!temp.empty() and temp.top() == pq.top()){
    //                 temp.pop();
    //                 pq.pop();
    //             }
    //             ans.push_back(pq.top());
    //             i++;
    //             j++;
    //         }
    //         return ans;
    //     }
};
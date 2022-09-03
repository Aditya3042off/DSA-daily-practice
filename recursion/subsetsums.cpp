// Given a list arr of N integers, print sums of all subsets in it.

// Note: Return all the element is increasing order.

// Example 1:

// Input:
// N = 2
// arr[] = {2, 3}
// Output:
// 0 2 3 5
// Explanation:
// When no elements is taken then Sum = 0.
// When only 2 is taken then Sum = 2.
// When only 3 is taken then Sum = 3.
// When element 2 and 3 are taken then
// Sum = 2+3 = 5.
// Example 2:

// Input:
// N = 3
// arr = {5, 2, 1}
// Output:
// 0 1 2 3 5 6 7 8

// https://www.youtube.com/watch?v=rYkfBRtMJr8&list=PLgUwDviBIf0rGlzIn_7rsaR2FQ5e6ZOL9&index=10

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void solve(vector<int> &sums, vector<int> &arr, int sum, int idx)
    {

        if (idx == arr.size())
        {
            sums.push_back(sum);
            return;
        };

        // selecting the number
        solve(sums, arr, sum + arr[idx], idx + 1);

        // not selecting the number
        solve(sums, arr, sum, idx + 1);
        return;
    }

    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        vector<int> sums;
        solve(sums, arr, 0, 0);

        sort(sums.begin(), sums.end());
        return sums;
    }
};
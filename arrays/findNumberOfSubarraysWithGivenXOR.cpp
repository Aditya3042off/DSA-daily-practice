// Given an array of integers A and an integer B.

// Find the total number of subarrays having bitwise XOR of all elements equals to B.

// Problem Constraints
// 1 <= length of the array <= 105

// 1 <= A[i], B <= 109

// Input Format
// The first argument given is the integer array A.

// The second argument given is integer B.

// Output Format
// Return the total number of subarrays having bitwise XOR equals to B.

// Example Input
// Input 1:

//  A = [4, 2, 2, 6, 4]
//  B = 6
// Input 2:

//  A = [5, 6, 7, 8, 9]
//  B = 5

// Example Output
// Output 1:

//  4
// Output 2:

//  2

// Example Explanation
// Explanation 1:

//  The subarrays having XOR of their elements as 6 are:
//  [4, 2], [4, 2, 2, 6, 4], [2, 2, 6], [6]
// Explanation 2:

//  The subarrays having XOR of their elements as 5 are [5] and [5, 6, 7, 8, 9]

// https://www.youtube.com/watch?v=lO9R5CaGRPY&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=24

int Solution::solve(vector<int> &arr, int target)
{
    int count = 0;
    int currXor = 0;
    int n = arr.size();
    unordered_map<int, int> freq;

    for (int i = 0; i < n; i++)
    {
        currXor = currXor ^ arr[i];
        if (currXor == target)
            count++;
        if (freq.find(currXor ^ target) != freq.end())
            count += freq[currXor ^ target];
        freq[currXor]++;
    }
    return count;
}
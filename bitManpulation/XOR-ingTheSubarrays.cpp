// Given an integer array A of size N.

// You need to find the value obtained by XOR-ing the contiguous subarrays, followed by XOR-ing the values thus obtained. Determine and return this value.

// For example, if A = [3, 4, 5] :

// Subarray    Operation   Result
// 3       None            3
// 4       None            4
// 5       None            5
// 3,4   3 XOR 4         7
// 4,5   4 XOR 5         1
// 3,4,5    3 XOR 4 XOR 5   2

// Now we take the resultant values and XOR them together:

// 3 ⊕ 4 ⊕ 5 ⊕ 7 ⊕ 1⊕ 2 = 6 we will return 6.

// Problem Constraints
// 1 <= N <= 105

// 1 <= A[i] <= 108

// Input Format
// First and only argument is an integer array A.

// Output Format
// Return a single integer denoting the value as described above.

// Example Input
// Input 1:

//  A = [1, 2, 3]
// Input 2:

//  A = [4, 5, 7, 5]

// Example Output
// Output 1:

//  2
// Output 2:

//  0

// Example Explanation
// Explanation 1:

//  1 ⊕ 2 ⊕ 3 ⊕  (1 ⊕ 2 ) ⊕ (2 ⊕ 3) ⊕ (1 ⊕ 2 ⊕ 3) = 2
// Explanation 2:

//  4 ⊕ 5 ⊕ 7 ⊕ 5 ⊕ (4 ⊕ 5) ⊕ (5 ⊕ 7) ⊕ (7 ⊕ 5) ⊕ (4 ⊕ 5 ⊕ 7) ⊕ (5 ⊕ 7 ⊕ 5) ⊕ (4 ⊕ 5 ⊕ 7 ⊕ 5) = 0

// https://www.interviewbit.com/problems/xor-ing-the-subarrays/

// here we are finding the contribuiton of every element to all the subarrays
// we are finding how many times an element occurs and based on that if it occurs odd number of times
// it will be in our answer but if it occurs even number of times it wont be in our answer

int Solution::solve(vector<int> &arr)
{
    int n = arr.size();
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        int totalSubarrays = (i + 1) * (n - i); // totalSubarrays the number appears in
        if (totalSubarrays & 1)
            ans ^= arr[i];
    }

    return ans;
}

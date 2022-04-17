// You are given a 0-indexed binary string s which represents the types of buildings along a street where:

// s[i] = '0' denotes that the ith building is an office and
// s[i] = '1' denotes that the ith building is a restaurant.
// As a city official, you would like to select 3 buildings for random inspection. However, to ensure variety, no two consecutive buildings out of the selected buildings can be of the same type.

// For example, given s = "001101", we cannot select the 1st, 3rd, and 5th buildings as that would form "011" which is not allowed due to having two consecutive buildings of the same type.
// Return the number of valid ways to select 3 buildings.

// Example 1:

// Input: s = "001101"
// Output: 6
// Explanation:
// The following sets of indices selected are valid:
// - [0,2,4] from "001101" forms "010"
// - [0,3,4] from "001101" forms "010"
// - [1,2,4] from "001101" forms "010"
// - [1,3,4] from "001101" forms "010"
// - [2,4,5] from "001101" forms "101"
// - [3,4,5] from "001101" forms "101"
// No other selection is valid. Thus, there are 6 total ways.
// Example 2:

// Input: s = "11100"
// Output: 0
// Explanation: It can be shown that there are no valid selections.

// https://www.youtube.com/watch?v=-bRNr59Rjx4

class Solution
{
public:
    long long numberOfWays(string s)
    {
        int n = s.size();
        long long sum0 = 0, sum1 = 0;
        vector<int> pre0, pre1;
        int count0 = 0, count1 = 0;

        for (int i = 0; i < n; i++)
        {
            if (s[i] == '0')
                count0++;
            else
                count1++;
            pre0.push_back(count0);
            pre1.push_back(count1);
        }

        for (int i = 1; i < n - 1; i++)
        {
            if (s[i] == '0')
                sum0 += pre1[i - 1] * (pre1[n - 1] - pre1[i - 1]);
            else
                sum1 += pre0[i - 1] * (pre0[n - 1] - pre0[i - 1]);
        }
        return sum0 + sum1;
    }
};
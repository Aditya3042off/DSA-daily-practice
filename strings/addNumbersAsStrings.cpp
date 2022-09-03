// https://www.youtube.com/watch?v=7pEVjtzmL4s&list=PLjeQ9Mb66hM05uqfKysHKi3eA5HhK7QSy&index=2

// Given two non-negative integers, num1 and num2 represented as string, return the sum of num1 and num2 as a string.

// You must solve the problem without using any built-in library for handling large integers (such as BigInteger). You must also not convert the inputs to integers directly.

// Example 1:

// Input: num1 = "11", num2 = "123"
// Output: "134"
// Example 2:

// Input: num1 = "456", num2 = "77"
// Output: "533"
// Example 3:

// Input: num1 = "0", num2 = "0"
// Output: "0"

class Solution
{
public:
    string addStrings(string num1, string num2)
    {
        int carry = 0;
        int idx1 = num1.size() - 1;
        int idx2 = num2.size() - 1;
        int sum = 0;

        string ans = "";

        while (idx1 >= 0 or idx2 >= 0 or carry != 0)
        {
            sum += carry;

            if (idx1 >= 0)
                sum += (num1[idx1--] - '0');
            if (idx2 >= 0)
                sum += (num2[idx2--] - '0');

            carry = sum / 10;
            sum = 0;

            ans = to_string(sum % 10) + ans;
        }

        return ans;
    }
};
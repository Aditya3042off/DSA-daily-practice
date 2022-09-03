// https://www.youtube.com/watch?v=l0YC3876qxg&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=18

// Implement pow(x, n), which calculates x raised to the power n (i.e., xn).

// Example 1:

// Input: x = 2.00000, n = 10
// Output: 1024.00000
// Example 2:

// Input: x = 2.10000, n = 3
// Output: 9.26100
// Example 3:

// Input: x = 2.00000, n = -2
// Output: 0.25000
// Explanation: 2-2 = 1/22 = 1/4 = 0.25

class Solution
{
public:
    double myPow(double x, int n)
    {
        if (n == 0)
            return 1;
        long long newN = (long long)n;
        bool negPower = false;
        if (newN < 0)
        {
            newN = 0 - newN;
            negPower = true;
        }

        double ans = 1.0;

        while (newN > 1)
        {
            if (newN % 2 != 0)
                ans = ans * x;
            newN = newN / 2;
            x = x * x;
            cout << ans << " " << x << endl;
        }

        ans = ans * x;

        if (negPower)
            return (double)(1.0) / (double)(ans);
        return ans;
    }
};
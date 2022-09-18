// You have n robots. You are given two 0-indexed integer arrays, chargeTimes and runningCosts, both of length n. The ith robot costs chargeTimes[i] units to charge and costs runningCosts[i] units to run. You are also given an integer budget.

// The total cost of running k chosen robots is equal to max(chargeTimes) + k * sum(runningCosts), where max(chargeTimes) is the largest charge cost among the k robots and sum(runningCosts) is the sum of running costs among the k robots.

// Return the maximum number of consecutive robots you can run such that the total cost does not exceed budget.

// Example 1:

// Input: chargeTimes = [3,6,1,3,4], runningCosts = [2,1,3,4,5], budget = 25
// Output: 3
// Explanation:
// It is possible to run all individual and consecutive pairs of robots within budget.
// To obtain answer 3, consider the first 3 robots. The total cost will be max(3,6,1) + 3 * sum(2,1,3) = 6 + 3 * 6 = 24 which is less than 25.
// It can be shown that it is not possible to run more than 3 consecutive robots within budget, so we return 3.
// Example 2:

// Input: chargeTimes = [11,12,19], runningCosts = [10,8,7], budget = 19
// Output: 0
// Explanation: No robot can be run that does not exceed the budget, so we return 0.

// https://leetcode.com/contest/biweekly-contest-86/problems/maximum-number-of-robots-within-budget/

class Solution
{
public:
    bool predicateFxn(vector<int> &chargeTimes, vector<int> &runningCosts, long long &budget, long long &k)
    {
        if (k == 0)
            return true;

        long long sum = 0;
        deque<int> dq;
        int n = chargeTimes.size();
        long long temp = 0;
        for (int i = 0; i < k; i++)
        {
            while (!dq.empty() and chargeTimes[dq.back()] < chargeTimes[i])
                dq.pop_back();
            dq.push_back(i);
            temp += runningCosts[i];
        }
        sum = chargeTimes[dq.front()] + k * temp;

        for (int i = k - 1; i < n; i++)
        {
            if (sum <= budget)
                return true;
            if (i == n - 1)
                continue;
            sum += k * (runningCosts[i + 1] - runningCosts[i - k + 1]);
            sum -= chargeTimes[dq.front()];

            while (!dq.empty() and chargeTimes[dq.back()] < chargeTimes[i + 1])
                dq.pop_back();
            dq.push_back(i + 1);
            while (dq.front() <= i + 1 - k)
                dq.pop_front();

            sum += chargeTimes[dq.front()];
        }

        return false;
    }

    int maximumRobots(vector<int> &chargeTimes, vector<int> &runningCosts, long long budget)
    {
        long long low = 0, high = chargeTimes.size();

        long long middle;
        long long ans = 0;
        while (low <= high)
        {
            middle = low + (high - low) / 2;
            if (predicateFxn(chargeTimes, runningCosts, budget, middle))
            {
                low = middle + 1;
                ans = middle;
            }
            else
                high = middle - 1;
        }
        return ans;
    }
};
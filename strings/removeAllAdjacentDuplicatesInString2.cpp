// https://www.youtube.com/watch?v=U1BYtpfZFeg&list=PLjeQ9Mb66hM05uqfKysHKi3eA5HhK7QSy&index=6
// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/submissions/

// You are given a string s and an integer k, a k duplicate removal consists of choosing k adjacent
// and equal letters from s and removing them, causing the left
// and the right side of the deleted substring to concatenate together.

// We repeatedly make k duplicate removals on s until we no longer can.

// Return the final string after all such duplicate removals have been made.
// It is guaranteed that the answer is unique.

// Example 1:

// Input: s = "abcd", k = 2
// Output: "abcd"
// Explanation: There's nothing to delete.
// Example 2:

// Input: s = "deeedbbcccbdaa", k = 3
// Output: "aa"
// Explanation:
// First delete "eee" and "ccc", get "ddbbbdaa"
// Then delete "bbb", get "dddaa"
// Finally delete "ddd", get "aa"
// Example 3:

// Input: s = "pbbcggttciiippooaais", k = 2
// Output: "ps"

class Solution
{
public:
    string removeDuplicates(string s, int k)
    {
        stack<pair<char, int>> st;

        for (int i = 0; i < s.size(); i++)
        {

            if (st.empty())
            {
                st.push({s[i], 1});
                continue;
            }

            if (st.top().first != s[i])
                st.push({s[i], 1});
            else if (st.top().first == s[i] and st.top().second == k - 1)
                st.pop();
            else
                st.top().second++;
        }

        string ans = "";

        while (!st.empty())
        {
            while (st.top().second--)
                ans += st.top().first;
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};
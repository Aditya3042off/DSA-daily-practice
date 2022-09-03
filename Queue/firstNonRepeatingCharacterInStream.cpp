// https://www.youtube.com/watch?v=_gJ3to4RyeQ&list=PLDzeHZWIZsTrhXYYtx4z8-u8zA-DzuVsj&index=8
// https://practice.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream1216/1

// Given an input stream of A of n characters consisting only of lower case alphabets. T
// he task is to find the first non repeating character, each time a character is inserted to the stream.
// If there is no such character then append '#' to the answer.

// Example 1:

// Input: A = "aabc"
// Output: "a#bb"
// Explanation: For every character first non
// repeating character is as follow-
// "a" - first non-repeating character is 'a'
// "aa" - no non-repeating character so '#'
// "aab" - first non-repeating character is 'b'
// "aabc" - first non-repeating character is 'b'
// Example 2:

// Input: A = "zz"
// Output: "z#"
// Explanation: For every character first non
// repeating character is as follow-
// "z" - first non-repeating character is 'z'
// "zz" - no non-repeating character so '#'

class Solution
{
public:
    string FirstNonRepeating(string s)
    {
        queue<char> q;
        vector<int> freq(26, 0);
        string ans = "";

        for (int i = 0; i < s.size(); i++)
        {
            if (freq[s[i] - 'a']++ == 0)
                q.push(s[i]);

            while (!q.empty() and freq[q.front() - 'a'] != 1)
                q.pop();

            if (q.empty())
                ans += '#';
            else
                ans += q.front();
        }
        return ans;
    }
};
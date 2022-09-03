
// https://www.youtube.com/watch?v=Bo4oHP7c_Gc&list=PLjeQ9Mb66hM05uqfKysHKi3eA5HhK7QSy&index=1

// Given an input string s, reverse the order of the words.

// A word is defined as a sequence of non-space characters. T
// he words in s will be separated by at least one space.

// Return a string of the words in reverse order concatenated by a single space.

// Note that s may contain leading or trailing spaces or multiple spaces between two words.
// The returned string should only have a single space separating the words. Do not include any extra spaces.

// Example 1:

// Input: s = "the sky is blue"
// Output: "blue is sky the"
// Example 2:

// Input: s = "  hello world  "
// Output: "world hello"
// Explanation: Your reversed string should not contain leading or trailing spaces.
// Example 3:

// Input: s = "a good   example"
// Output: "example good a"
// Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.

class Solution
{
public:
    string reverseWords(string s)
    {
        string temp = "";
        string ans = "";

        vector<string> arr;

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == ' ' and temp == "")
                continue;
            if (s[i] == ' ')
            {
                arr.push_back(temp);
                temp = "";
            }
            else
                temp += s[i];
        }

        if (s[s.size() - 1] != ' ')
            arr.push_back(temp);

        for (int i = arr.size() - 1; i >= 0; i--)
        {
            ans += arr[i];
            if (i != 0)
                ans += ' ';
        }
        return ans;
    }
};
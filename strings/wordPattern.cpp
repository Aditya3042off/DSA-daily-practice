// Given a pattern and a string s, find if s follows the same pattern.

// Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in s.

// Example 1:

// Input: pattern = "abba", s = "dog cat cat dog"
// Output: true
// Example 2:

// Input: pattern = "abba", s = "dog cat cat fish"
// Output: false
// Example 3:

// Input: pattern = "aaaa", s = "dog cat cat dog"
// Output: false

// https://www.youtube.com/watch?v=W_akoecmCbM

class Solution
{
public:
    bool wordPattern(string pattern, string s)
    {
        unordered_map<char, string> mp;
        unordered_map<string, char> mp2;
        // to check if no of words = no of characters in pattern
        int spaceCount = 0;
        for (char i : s)
            if (i == ' ')
                spaceCount++;
        if (spaceCount + 1 != pattern.size())
            return false;

        int idx = 0, n = s.size();
        string temp = "";
        bool flag = true;

        for (int i = 0; i < pattern.size(); i++)
        {
            while (idx < n and s[idx] != ' ')
            {
                temp += s[idx];
                idx++;
            }

            if (mp.find(pattern[i]) == mp.end())
            {
                if (mp2.find(temp) != mp2.end() and mp2[temp] != pattern[i])
                {
                    flag = false;
                    break;
                }

                mp[pattern[i]] = temp;
                mp2[temp] = pattern[i];
            }
            else
            {
                if (mp[pattern[i]] != temp)
                {
                    flag = false;
                    break;
                }
            }

            temp = "";
            idx++;
        }

        return flag;
    }
};
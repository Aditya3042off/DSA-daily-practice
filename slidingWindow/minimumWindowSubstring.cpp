// Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

// The testcases will be generated such that the answer is unique.

// A substring is a contiguous sequence of characters within the string.

// Example 1:

// Input: s = "ADOBECODEBANC", t = "ABC"
// Output: "BANC"
// Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
// Example 2:

// Input: s = "a", t = "a"
// Output: "a"
// Explanation: The entire string s is the minimum window.
// Example 3:

// Input: s = "a", t = "aa"
// Output: ""
// Explanation: Both 'a's from t must be included in the window.
// Since the largest window of s only has one 'a', return empty string.

// https://www.youtube.com/watch?v=jSto0O4AJbM&list=PLot-Xpze53leOBgcVsJBEGrHPd_7x_koV&index=3&t=335s

class Solution
{
public:
    string minWindow(string s, string t)
    {
        unordered_map<char, int> pattern;
        unordered_map<char, int> window;

        for (char c : t)
        {
            pattern[c]++;
            window[c] += 0;
        }
        pair<int, int> result;

        int count = 0, ans = INT_MAX;
        int n = s.size();
        int m = pattern.size();

        int i = 0, j = 0;

        while (j < n)
        {
            if (pattern.find(s[j]) == pattern.end())
            {
                j++;
                continue;
            }

            window[s[j]]++;
            if (window[s[j]] != pattern[s[j]])
            {
                j++;
                continue;
            }

            count++;

            if (count < m)
            {
                j++;
                continue;
            }

            if (ans > j - i + 1)
            {
                ans = j - i + 1;
                result = {i, j};
            }

            while (count == m)
            {
                if (pattern.find(s[i]) != pattern.end())
                {
                    window[s[i]]--;
                    if (window[s[i]] < pattern[s[i]])
                        count--;
                    if (ans > j - i + 1)
                    {
                        ans = j - i + 1;
                        result = {i, j};
                    }
                }
                i++;
            }
            j++;
        }

        if (ans == INT_MAX)
            return "";
        string temp = "";
        for (int k = result.first; k <= result.second; k++)
            temp += s[k];
        return temp;
    }
};

// neetcode c++ code
// class Solution {
// public:
//     string minWindow(string s, string t) {
//         // count of char in t
//         unordered_map<char, int> m;
//         for (int i = 0; i < t.size(); i++) {
//             m[t[i]]++;
//         }

//         int i = 0;
//         int j = 0;

//         // # of chars in t that must be in s
//         int counter = t.size();

//         int minStart = 0;
//         int minLength = INT_MAX;

//         while (j < s.size()) {
//             // if char in s exists in t, decrease
//             if (m[s[j]] > 0) {
//                 counter--;
//             }
//             // if char doesn't exist in t, will be -'ve
//             m[s[j]]--;
//             // move j to find valid window
//             j++;

//             // when window found, move i to find smaller
//             while (counter == 0) {
//                 if (j - i < minLength) {
//                     minStart = i;
//                     minLength = j - i;
//                 }

//                 m[s[i]]++;
//                 // when char exists in t, increase
//                 if (m[s[i]] > 0) {
//                     counter++;
//                 }
//                 i++;
//             }
//         }

//         if (minLength != INT_MAX) {
//             return s.substr(minStart, minLength);
//         }
//         return "";
//     }
// };
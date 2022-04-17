// Given two strings s and t, return true if t is an anagram of s, and false otherwise.

// An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

// Example 1:

// Input: s = "anagram", t = "nagaram"
// Output: true
// Example 2:

// Input: s = "rat", t = "car"
// Output: false

// Constraints:

// 1 <= s.length, t.length <= 5 * 104
// s and t consist of lowercase English letters.

// https://www.youtube.com/watch?v=9UtInBqnCgA&list=PLot-Xpze53ldVwtstag2TL4HQhAnC8ATf&index=74

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        vector<int> arr(26, 0);

        if (s.size() != t.size())
            return false;

        for (int i = 0; i < s.size(); i++)
        {
            arr[s[i] - 'a']++;
            arr[t[i] - 'a']--;
        }
        for (int i : arr)
            if (i != 0)
                return false;
        return true;
    }
};
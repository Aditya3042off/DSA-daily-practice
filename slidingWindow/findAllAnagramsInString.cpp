// Given two strings s and p, return an array of all the start indices of p's anagrams in s. You may return the answer in any order.

// An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

// Example 1:

// Input: s = "cbaebabacd", p = "abc"
// Output: [0,6]
// Explanation:
// The substring with start index = 0 is "cba", which is an anagram of "abc".
// The substring with start index = 6 is "bac", which is an anagram of "abc".
// Example 2:

// Input: s = "abab", p = "ab"
// Output: [0,1,2]
// Explanation:
// The substring with start index = 0 is "ab", which is an anagram of "ab".
// The substring with start index = 1 is "ba", which is an anagram of "ab".
// The substring with start index = 2 is "ab", which is an anagram of "ab".
// https://www.youtube.com/watch?v=G8xtZy0fDKg&list=PLot-Xpze53leOBgcVsJBEGrHPd_7x_koV&index=5

class Solution
{
public:
    void findFreq(string s1, string s2, vector<int> &windFreq, vector<int> &tempFreq)
    {
        int n = s2.size();
        for (int i = 0; i < n; i++)
        {
            windFreq[s2[i] - 'a']++;
            tempFreq[s1[i] - 'a']++;
        }
    }

    vector<int> findAnagrams(string pat, string txt)
    {
        vector<int> ans;
        int k = txt.size();
        int n = pat.size();
        if (k > n)
            return {};

        vector<int> windFreq(26, 0);
        vector<int> tempFreq(26, 0);

        findFreq(pat, txt, windFreq, tempFreq);

        int start = 0, end = k - 1;

        while (end < n)
        {
            if (windFreq == tempFreq)
                ans.push_back(start);
            tempFreq[pat[start] - 'a']--;
            if (end < n - 1)
                tempFreq[pat[end + 1] - 'a']++;
            start++;
            end++;
        }
        return ans;
    }
};
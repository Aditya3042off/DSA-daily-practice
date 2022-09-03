// Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.

// In other words, return true if one of s1's permutations is the substring of s2.

// Example 1:

// Input: s1 = "ab", s2 = "eidbaooo"
// Output: true
// Explanation: s2 contains one permutation of s1 ("ba").
// Example 2:

// Input: s1 = "ab", s2 = "eidboaoo"
// Output: false

//  https://leetcode.com/problems/permutation-in-string/

#include <bits/stdc++.h>
using namespace std;
// Approach 2
class Solution
{
public:
    int fillFreq(string s1, string s2, vector<int> &tempFreq, vector<int> &windowFreq)
    {
        int windowSize = s2.size();

        for (int i = 0; i < windowSize; i++)
        {
            tempFreq[s1[i] - 'a']++;
            windowFreq[s2[i] - 'a']++;
        }
        int count = 0;
        for (int i = 0; i < windowSize; i++)
        {
            if (tempFreq[s1[i] - 'a'] == windowFreq[s2[i] - 'a'])
                count++;
        }
        return count;
    }

    bool checkInclusion(string s2, string s1)
    {
        int n = s1.size();
        int k = s2.size();
        if (k > n)
            return false;

        vector<int> tempFreq(26, 0);
        vector<int> windowFreq(26, 0);

        int count = fillFreq(s1, s2, tempFreq, windowFreq);

        int start = 0, end = k - 1;

        while (end < n)
        {
            if (count == 26)
                return true;

            if (tempFreq[s1[start] - 'a'] == windowFreq[s1[start] - 'a'])
                count--;
            else if (tempFreq[s1[start] - 'a'] + 1 == windowFreq[s1[start] - 'a'])
                count++;
            else
            {
            }

            tempFreq[s1[start] - 'a']--;

            if (end > n - 2)
                continue;

            if (tempFreq[s1[end + 1] - 'a'] == windowFreq[s1[end + 1] - 'a'])
                count--;
            else if (tempFreq[s1[end + 1] - 'a'] + 1 == tempFreq[s1[end + 1] - 'a'])
                count++;
            else
            {
            }

            tempFreq[s1[end + 1] - 'a']++;

            start++;
            end++;
        }
        return false;
    }
};

// Approach -2
class Solution
{
public:
    void fillFreq(string s1, string s2, vector<int> &tempFreq, vector<int> &windowFreq)
    {
        int windowSize = s2.size();

        for (int i = 0; i < windowSize; i++)
        {
            tempFreq[s1[i] - 'a']++;
            windowFreq[s2[i] - 'a']++;
        }
    }

    bool checkInclusion(string s2, string s1)
    {
        int n = s1.size();
        int k = s2.size();
        if (k > n)
            return false;

        vector<int> tempFreq(26, 0);
        vector<int> windowFreq(26, 0);

        fillFreq(s1, s2, tempFreq, windowFreq);

        int start = 0, end = k - 1;

        while (end < n)
        {
            if (tempFreq == windowFreq)
                return true;
            tempFreq[s1[start] - 'a']--;
            if (end < n - 1)
                tempFreq[s1[end + 1] - 'a']++;

            start++;
            end++;
        }
        return false;
    }
};
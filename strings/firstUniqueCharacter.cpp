// https://leetcode.com/problems/first-unique-character-in-a-string/
// Given a string s, find the first non-repeating character in it and return its index.
// If it does not exist, return -1.

// Example 1:

// Input: s = "leetcode"
// Output: 0
// Example 2:

// Input: s = "loveleetcode"
// Output: 2
// Example 3:

// Input: s = "aabb"
// Output: -1

class Solution
{
public:
    int firstUniqChar(string s)
    {
        int n = s.size();
        vector<int> idxArray(26, n);

        for (int i = 0; i < n; i++)
        {
            if (idxArray[s[i] - 'a'] == n)
                idxArray[s[i] - 'a'] = i;
            else
                idxArray[s[i] - 'a'] = -1;
        }
        int ans = INT_MAX;

        for (int i = 0; i < 26; i++)
        {
            if (idxArray[i] != -1 and idxArray[i] != n)
                ans = min(idxArray[i], ans);
        }
        if (ans == INT_MAX)
            return -1;
        return ans;
    }

    //     int firstUniqChar(string s) {
    //         unordered_map<char,int> ump;

    //         for(char ch : s) ump[ch]++;

    //         for(int i=0;i<s.size();i++){
    //             if(ump[s[i]] != 1) continue;
    //             return i;
    //         }
    //         return -1;
    //     }
};
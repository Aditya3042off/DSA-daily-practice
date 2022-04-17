// Given a string s, return true if the s can be palindrome after deleting at most one character from it.

// Example 1:

// Input: s = "aba"
// Output: true
// Example 2:

// Input: s = "abca"
// Output: true
// Explanation: You could delete the character 'c'.
// Example 3:

// Input: s = "abc"
// Output: false

// https://www.youtube.com/watch?v=JrxRYBwG6EI&t=12s

class Solution
{
public:
    // count tracks the number of mismatches
    // if mismatches is more than 1 then we return false
    bool isPalindrome(string s1, int idx1, int idx2, int count)
    {
        while (idx1 < idx2)
        {
            if (s1[idx1] == s1[idx2])
            {
                idx2--;
                idx1++;
            }
            else
            {
                if (count)
                    return false;
                return isPalindrome(s1, idx1 + 1, idx2, 1) || isPalindrome(s1, idx1, idx2 - 1, 1);
            }
        }
        return true;
    }

    bool validPalindrome(string s)
    {
        return isPalindrome(s, 0, s.size() - 1, 0);
    }
};
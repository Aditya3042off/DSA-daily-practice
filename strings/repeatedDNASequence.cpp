// The DNA sequence is composed of a series of nucleotides abbreviated as 'A', 'C', 'G', and 'T'.

// For example, "ACGAATTCCG" is a DNA sequence.
// When studying DNA, it is useful to identify repeated sequences within the DNA.

// Given a string s that represents a DNA sequence, return all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule. You may return the answer in any order.

// Example 1:

// Input: s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
// Output: ["AAAAACCCCC","CCCCCAAAAA"]
// Example 2:

// Input: s = "AAAAAAAAAAAAA"
// Output: ["AAAAAAAAAA"]

// https://www.youtube.com/watch?v=FzTYfsmtOso

class Solution
{
public:
    vector<string> findRepeatedDnaSequences(string s)
    {
        unordered_set<string> st;
        vector<string> ans;
        string temp = "";
        for (int i = 0; i < 10; i++)
            temp += s[i];
        st.insert(temp);

        for (int i = 10; i < s.size(); i++)
        {
            temp = temp.substr(1, 9) + s[i];
            if (st.find(temp) == st.end())
            {
                st.insert(temp);
                continue;
            }
            if (find(ans.begin(), ans.end(), temp) == ans.end())
                ans.push_back(temp);
        }
        return ans;
    }
};
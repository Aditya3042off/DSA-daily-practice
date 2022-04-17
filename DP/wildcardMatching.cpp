#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool solve(string &s, string &p, int idx1, int idx2)
    {
        cout << "idx1: " << idx1 << " idx2: " << idx2 << endl;
        if (idx1 == s.size() and idx2 == p.size())
            return true;
        if (idx1 != s.size() and idx2 == p.size())
            return false;

        if (p[idx2] == '?')
            return solve(s, p, idx1 + 1, idx2 + 1);
        else if (p[idx2] == '*')
        {
            if (idx2 == p.size() - 1)
                return true;
            if (p[idx2 + 1] != '*')
            {
                while (idx1 < s.size() - 1 and s[idx1 + 1] != p[idx2 + 1])
                    idx1++;
                return solve(s, p, idx1 + 1, idx2 + 1);
            }
            else
                return solve(s, p, idx1, idx2 + 1);
        }
        else
        {
            if (s[idx1] == p[idx2])
                return solve(s, p, idx1 + 1, idx2 + 1);
            return false;
        }
    }

    bool isMatch(string s, string p)
    {
        return solve(s, p, 0, 0);
    }
};

int main()
{
    string s = "adceb";
    string p = "a*b";

    Solution obj;
    cout << obj.isMatch(s, p);
}
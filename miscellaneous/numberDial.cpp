// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int n;
//     string str;
//     cin >> n >> str;
//     int ans = 0;
//     if (str == "")
//         return ans;
//     int temp;

//     ans += stoi(str[0]);
//     for (int i = 0; i < str.length(); i++)
//     {

//         if (i == str.length())
//             continue;

//         if (str[i] == str[i + 1])
//         {
//             ans += 10;
//             continue;
//         }
//         ans += min(abs(10 - stoi(str[i]) + stoi(str[i + 1])), abs(stoi(str[i]) - stoi(str[i - 1])));
//     }
//     return ans;
// }

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, ans = 0, prev = 0;
    string s;
    cin >> n;
    cin >> s;

    for (int i = 0; i < n; i++)
    {
        if ((s[i] - '0') == 0 and i == 0)
            continue;
        if (s[i] - '0' > prev)
            ans += min((s[i] - '0') - prev, 10 - (s[i] - '0') + prev);
        else if (s[i] - '0' < prev)
            ans += min(prev - (s[i] - '0'), 10 - prev + (s[i] - '0'));
        else
            ans += 10;

        prev = s[i] - '0';
    }
    cout << ans;
    return 0;
}
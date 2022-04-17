#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        // 0-> count++ 1-> couunt2+=count+1 count=0
        int count = 0, count2 = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == 0)
            {
                count++;
            }
            else if (count != 0)
            {
                count2 += count + 1;
                count = 0;
            }
        }
        cout << count2 << endl;
    }
}
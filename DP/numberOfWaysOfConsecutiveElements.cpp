#include <bits/stdc++.h>
using namespace std;

int findWays(int cur, int k, int num)
{
    if (num > ((k / 2) + 1))
        return 0;
    if (num + cur > k)
        return 0;
    if (num + cur == k)
        return 1;

    return findWays(cur + num, k, num + 1) + findWays(0, k, num + 1);
}

int main()
{
    int k;
    cout << "Enter the value for k: ";
    cin >> k;
    cout << findWays(0, k, 1);
}
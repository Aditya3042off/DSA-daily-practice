#include <bits/stdc++.h>
using namespace std;

class SparseTable
{
public:
    vector<vector<int>> table;
    vector<int> power2;
    int n;
    int m;

    SparseTable(int _n)
    {
        n = _n;
        m = log2(n) + 1;
        table.resize(n);

        for (int i = 0; i < n; i++)
            table[i].resize(m);

        power2.resize(n + 1, 0);

        for (int i = 2; i < n; i++)
            power2[i] = power2[i / 2] + 1;
    }

    void build(vector<int> arr)
    {
        for (int i = 0; i < n; i++)
            table[i][0] = arr[i];

        for (int j = 1; j < m; j++)
        {
            for (int i = 0; i < n; i++)
            {
                if (i + pow(2, j) - 1 > n - 1)
                    break;

                table[i][j] = table[i][j - 1] + table[i + pow(2, j - 1)][j - 1];
            }
        }
        return;
    }

    vector<int> powerFactorisation(int num){
        vector<int> temp;
        while(num != 0){
            temp.push_back(power2[num]);
            num -= pow(2,power2[num]);
        }
        return temp;
    }

    int query(int l, int r)
    {
        int range = r - l + 1;

        if (((range) & (range - 1)) == 0)
            return table[l][power2[range]];

        int sum = 0;
        vector<int> temp = powerFactorisation(range);

        int idx = l;
        for(int power : temp){
            sum += table[idx][power];
            idx = idx + pow(2,power);
        }
        return sum;
    }
};

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    int n = 9;
    // cin >> n;

    vector<int> arr = {10, -2, 0, -4, 5, 6, -7, 1, 9};

    // for (int i = 0; i < n; i++)
    //     cin >> arr[i];

    int l = 0, r = 8;
    // cin >> l >> r;

    SparseTable sparseTable = SparseTable(n);
    sparseTable.build(arr);
    cout << sparseTable.query(l, r);
}
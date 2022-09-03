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

        for (int i = 2; i <= n; i++)
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

                table[i][j] = min(table[i][j - 1], table[i + pow(2, j - 1)][j - 1]);
            }
        }
        return;
    }

    int query(int l, int r)
    {
        int range = r - l + 1;

        if (((range) & (range - 1)) == 0)
            return table[l][power2[range]];

        int nearestPower = power2[range];

        return min(table[l][nearestPower],
                   table[r - pow(2, nearestPower) + 1][nearestPower]
                  );
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

    vector<int> arr = {10, -2, 0, -4, 85, 6, -7, 1, 9};

    // for (int i = 0; i < n; i++)
    //     cin >> arr[i];

    int l = 4, r = 5;
    // cin >> l >> r;

    SparseTable sparseTable = SparseTable(n);
    sparseTable.build(arr);

    for(auto vect : sparseTable.table){
        for(int i:vect) cout<<i<<"      ";
        cout<<endl;
    }
    cout << sparseTable.query(l, r);
}
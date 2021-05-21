#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
#define int long long

class SparseTable
{
public:
    SparseTable(int n) : n(n)
    {
        this->activated = false;
        this->k = 0;
        while ((1 << k) < n)
            k++;
        this->table = vector<vector<int>>(n, vector<int>(k + 1));
    }
    void insert(int ind, int val)
    {
        this->table[ind][0] = val;
        this->activated = false;
    }
    int query(int l, int r)
    {
        if (!this->activated)
            this->arise();
        int ans = this->null;
        for (int j = k; j >= 0; j--)
        {
            if ((1 << j) <= r - l + 1)
            {
                ans = merge(ans, table[l][j]);
                l += 1 << j;
            }
        }
        return ans;
    }

private:
    int n, k;
    bool activated;
    vector<vector<int>> table;
    int null = INT32_MAX;
    void arise()
    {
        for (int j = 1; j <= k; j++)
            for (int i = 0; i + (1 << j) <= n; i++)
                table[i][j] = merge(table[i][j - 1], table[i + (1 << (j - 1))][j - 1]);
        activated = true;
    }
    int merge(int x, int y)
    {
        return min(x, y);
    }
};
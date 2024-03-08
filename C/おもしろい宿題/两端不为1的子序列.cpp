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

        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        int MAXP = pow(2, n);
        int prod = 1;
        for (int i = 0; i < n; i++)
        {
            prod *= a[i];
            if (prod > MAXP)
                break;
        }
        /*
        结论：如果数组中所有元素的乘积足够大， 选整个数组（除了 1 前/后缀）总是最优的。

        证明如下：

        有 N = {a[n]}, a[n] ∈ N*;
        ∃ l , r ∈ {1, 2, 3, ..., n}, l < r, M = {a[l], a[l + 1], ..., a[r]}, a[l], a[r] > 1;

        例如，取 2 ^ n ，此时数组中 > 1 的元素数最多为n。(对于 {1, 2, 2, 2, 2, 1}，4 < n = 6)

        现在问题简化为 “使两端不为1的子序列元素积不大于 2 ^ n ”，并根据此遍历（暴力）。

        时间复杂度为 O(n ^ 2)。
        */
        if (prod > MAXP)
        {
            int l = 0, r = n - 1;
            while (l < n && a[l] == 1)
                l++;
            while (r >= 0 && a[r] == 1)
                r--;
            cout << l + 1 << " " << r + 1 << endl;
            continue;
        }

        vector<int> not1;
        for (int i = 0; i < n; i++)
            if (a[i] > 1)
                not1.push_back(i);

        int maxval = 0;
        int l = 0;
        int r = 0;
        for (int x = 0; x < not1.size(); x++)
        {
            int p = 1;
            int s = 0;
            for (int y = x; y < not1.size(); y++)
            {
                int i = not1[x];
                int j = not1[y];
                p *= a[j];
                s += a[j] - 1;
                if (maxval <= p - s - (j - i + 1))
                {
                    maxval = p - s - (j - i + 1);
                    l = i;
                    r = j;
                }
            }
        }
        cout << l + 1 << " " << r + 1 << endl;
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;

int cnt[N], n, k, s, num = 0;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    memset(cnt, 0, sizeof cnt);

    cin >> n >> k >> s;
    while (n--)
    {
        int a, b;
        cin >> a >> b;

        if (a >= 175)
            if (b >= s)
                num++;
            else if (cnt[a]++ < k)
                num++;
    }

    cout << num;

    return 0;
}
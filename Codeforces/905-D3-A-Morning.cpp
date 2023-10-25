#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, num;
    cin >> n;

    while (n--)
    {
        cin >> num;

        int ans = 0, a = 0, b = 0, c = 0, d = 0;

        a = num / 1000;
        ans += a ? a : 10;

        num %= 1000;
        b = num / 100;
        if (a > 0 || b > 0)
            ans += b ? (a ? (abs(b - a) + 1) : 11 - b) : (11 - a);
        else
            ans++;

        num %= 100;
        c = num / 10;
        if (b > 0 || c > 0)
            ans += c ? (b ? (abs(c - b) + 1) : 11 - c) : (11 - b);
        else
            ans++;

        num %= 10;
        d = num;
        if (c > 0 || d > 0)
            ans += d ? (c ? (abs(d - c) + 1) : 11 - d) : (11 - c);
        else
            ans++;

        cout << ans << endl;
    }

    return 0;
}
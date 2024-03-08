#include <bits/stdc++.h>
using namespace std;
int T;
char a[9], b[9], s[9];
int n, m, len;
bool check(int x)
{
    if (x <= 10)
    {
        for (int i = 1; i <= n; i++)
            if (a[i] >= x + 48)
                return 0;
        for (int i = 1; i <= m; i++)
            if (b[i] >= x + 48)
                return 0;
        for (int i = 1; i <= len; i++)
            if (s[i] >= x + 48)
                return 0;

        char ans[30];
        
        int y = 0;
        for (int i = 1; i <= max(n, m); i++)
        {
            ans[i] = a[i] + b[i] - '0' + y;
            y = 0;
            if (ans[i] >= x + '0')
                y = 1, ans[i] -= '0';
        }
        for (int i = 1; i <= len; i++)
            if (ans[i] != s[i])
                return 0;
        return 1;
    }
    else
    {
        for (int i = 1; i <= n; i++)
            if (a[i] >= x - 10 + 'A')
                return 0;
        for (int i = 1; i <= m; i++)
            if (b[i] >= x - 10 + 'A')
                return 0;
        for (int i = 1; i <= len; i++)
            if (s[i] >= x - 10 + 'A')
                return 0;
        int y = 0;
        char ans[30];
        for (int i = 1; i <= max(n, m); i++)
        {
            int t, ta = 0, tb = 0;
            if (a[i] <= '9')
                ta = a[i] - '0';
            else
                ta = a[i] - 'A' + 10;
            if (b[i] <= '9')
                tb = b[i] - '0';
            else
                tb = b[i] - 'A' + 10;
            t = ta + tb + y;
            // cout<<ta<<" "<<tb<<" "<<t<<endl;
            y = 0;
            if (t >= x)
                y = 1, t -= x;
            if (t <= 9)
                ans[i] = t + '0';
            else
                ans[i] = t - 10 + 'A';
            // cout<<ans[i]<<" ";
        }
        int lenans = strlen(ans + 1);
        if (y)
            a[lenans + 1] = '1';
        // for(int i=1;i<=lenans;i++) cout<<ans[i]<<" ";
        // cout<<endl;
        if (lenans != len)
            return 0;
        for (int i = 1; i <= len; i++)
            if (ans[i] != s[i])
                return 0;
        return 1;
    }
}
int main()
{
    cin >> T;
    while (T--)
    {
        cin >> a + 1 >> b + 1 >> s + 1;
        n = strlen(a + 1);
        m = strlen(b + 1);
        len = strlen(s + 1);
        reverse(a + 1, a + n + 1);
        reverse(b + 1, b + m + 1);
        reverse(s + 1, s + len + 1);
        for (int i = 2; i <= 16; i++)
        {
            if (check(i))
            {
                cout << i << endl;
                break;
            }
        }
    }
}
// C++
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 65, B = 65;
ll x, c[N], d[N], p[N], a[N], b[N], f[N][B], g[N][B], ans[N];
int m;

ll read()
{
    ll x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}

void solve()
{
    // 读取输入数据
    x = read();
    m = read();
    int A = read(), B = read();
    for (int i = 0; i <= m; i++)
        c[i] = read();
    // 初始化
    for (int i = 0; i <= m; i++)
        a[i] = c[i] % B, b[i] = c[i] / B;
    for (int i = 0; i <= m; i++)
        d[i] = 1ll * a[i] * p[m - i] % B;
    memset(f, 0, sizeof(f));
    memset(g, 0, sizeof(g));
    f[0][0] = 1;
    g[0][0] = 1;
    // 动态规划
    for (int i = 1; i <= m; i++)
        for (int j = 0; j < B; j++)
            for (int k = 0; k < i && k < B; k++)
                if (f[k][j])
                {
                    int nj = (j + d[i]) % B, nk = k + 1;
                    if (!f[nk][nj] || f[nk][nj] > f[k][j] + b[i] || (f[nk][nj] == f[k][j] + b[i] && g[nk][nj] > g[k][j] + a[i]))
                    {
                        f[nk][nj] = f[k][j] + b[i];
                        g[nk][nj] = g[k][j] + a[i];
                    }
                }
    // 找到满足条件的序列
    for (int i = B - 1; i >= 0; i--)
    {
        if (!f[i][x % B])
            continue;
        if (f[i][x % B] > x / B || (f[i][x % B] == x / B && g[i][x % B] > x % B))
            continue;
        printf("%d\n", i);
        for (int j = m, k = x % B; j; j--)
            if (f[i][k] == f[i - 1][(k - d[j] + B) % B] + b[j] && g[i][k] == g[i - 1][(k - d[j] + B) % B] + a[j])
            {
                ans[j] = 1;
                k = (k - d[j] + B) % B;
                i--;
            }
        for (int j = 1; j <= m; j++)
            printf("%lld", ans[j]);
        puts("");
        return;
    }
    puts("-1");
}

int main()
{
    int T = read();
    while (T--)
        solve();
    return 0;
}
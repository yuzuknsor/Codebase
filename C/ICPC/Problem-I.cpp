#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e6 + 10, mod = 1e9 + 7;
ll n, m, k, inv[N], fac[N], ifac[N];
ll ksm(ll a, ll b)
{
    ll res = 1;
    while (b)
    {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}
void init()
{
    fac[0] = 1;
    for (int i = 1; i <= n * m; i++)
        fac[i] = fac[i - 1] * i % mod;
    ifac[n * m] = ksm(fac[n * m], mod - 2);
    for (int i = n * m - 1; i >= 0; i--)
        ifac[i] = ifac[i + 1] * (i + 1) % mod;
    inv[1] = 1;
    for (int i = 2; i <= n * m; i++)
        inv[i] = (mod - mod / i) * inv[mod % i] % mod;
}
ll C(ll n, ll m)
{
    if (m > n || m < 0)
        return 0;
    return fac[n] * ifac[m] % mod * ifac[n - m] % mod;
}
ll calc(ll x)
{
    return ksm(C(n * m, x), k);
}
int main()
{
    cin >> n >> m >> k;
    init();
    ll ans = 0;
    for (int i = 0; i <= n * m; i++)
    {
        if (i & 1)
            ans = (ans - C(n * m, i) * calc(i) % mod + mod) % mod;
        else
            ans = (ans + C(n * m, i) * calc(i) % mod) % mod;
    }
    cout << ans << endl;
    return 0;
}

/*小M 正在研究方格！现在在小M 面前有个n×m 的方格图，其中每个方格上都有一个1 ∼ k 的正整
数。
小M 对于最大值很感兴趣，因此，他会留意这个方格图中的” 极大方格”。对于某个方格，他是极大
方格当且仅当这个方格中的数字严格大于与该方格同行或是同列的其他方格的数字。
现在这个方格图所有方格都是空的，定义f(i) 为使方格图的” 极大方格” 数不少于i 的填数方案。小
M 想要知道，f(0) + f(1) + f(2) +···+ f(i) +···+ f(nm)的值？
由于这个结果可能很大，小M 只要求你求出答案对于109 + 7 取模的结果即可。
输入格式：
输入一行共三个整数n, m, k (1 ≤ n,m ≤ 10^6, 1 ≤ k ≤ 10^18)，含义如上文所述。
输出格式：
输出一行共一个整数，表示答案的值对109 + 7 取模的结果。
样例输入：
1 2 3
11 45 14
114514 1919 810
样例输出：
15
181394144
710129823
*/
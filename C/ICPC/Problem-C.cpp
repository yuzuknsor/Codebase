#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 10, mod = 998244353;
ll n, k, inv[N], fac[N], ifac[N], f[N], g[N];
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
    for (int i = 1; i <= n; i++)
        fac[i] = fac[i - 1] * i % mod;
    ifac[n] = ksm(fac[n], mod - 2);
    for (int i = n - 1; i >= 0; i--)
        ifac[i] = ifac[i + 1] * (i + 1) % mod;
    inv[1] = 1;
    for (int i = 2; i <= n; i++)
        inv[i] = (mod - mod / i) * inv[mod % i] % mod;
}
ll C(ll n, ll m)
{
    if (m > n || m < 0)
        return 0;
    return fac[n] * ifac[m] % mod * ifac[n - m] % mod;
}
int main()
{
    cin >> n >> k;
    init();
    f[0] = 1;
    for (int i = 1; i <= n; i++)
        f[i] = (f[i - 1] * 2 % mod + C(i - 1, k)) % mod;
    g[0] = 1;
    for (int i = 1; i <= n; i++)
        g[i] = (g[i - 1] * 2 % mod + C(i, k)) % mod;
    cout << (f[n] - g[n - 1] + mod) % mod << endl;
    return 0;
}
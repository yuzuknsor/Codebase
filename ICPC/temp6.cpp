#pragma GCC optimize(2)
#pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
#ifndef LOCAL
#define debug(...) 42
#else
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#endif
#define rep1(a) for (int i = 0; i < a; i++)
#define rep2(i, a) for (int i = 0; i < a; i++)
#define rep3(i, a, b) for (int i = a; i < b; i++)
#define rep4(i, a, b, c) for (int i = a; i < b; i += c)
#define overload4(a, b, c, d, e, ...) e
#define rep(...) overload4(__VA_ARGS__, rep4, rep3, rep2, rep1)(__VA_ARGS__)

#define pb emplace_back
using namespace std;
template <typename T, typename T2> void cmin(T &x, const T2 &y) {
  x = x < y ? x : y;
}
template <typename T, typename T2> void cmax(T &x, const T2 &y) {
  x = x > y ? x : y;
}
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;
template <class T> using vc = vector<T>;
template <class T> using pq = priority_queue<T>;
template <class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
mt19937 rng(time(NULL));
const int inf = 1000000000;
const ll lnf = 1000000000000000000;
#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
#define fi first
#define se second

const int B = 650;
int C[B * 4], cc = 0;
using ull = unsigned long long;
const ull W = 1048575;
const int N = 1e5 + 5;
int p[N], bk[N], rv[N];
array<ull, 2> ww[N];
unordered_map<ull, int> mp;
vi ss;
ull ans;
ull sol() {
  cc = 0;
  for (auto i : ss) {
    auto [z, xy] = ww[i];
    const ull x = xy >> 20, y = xy & W;
    const ull u = mp[z << 20 | x], v = mp[z << 20 | y];
    swap(p[u], p[v]);
    C[cc++] = u, C[cc++] = v;
  }
  ull res = ans;
  rep(j, cc) {
    const int &i = C[j];
    if (i == p[i])
      continue;
    res -= 1ll * (rv[i] + 1) * (i + 1);
    res += 1ll * (rv[i] + 1) * (p[i] + 1);
    p[i] = i;
  }
  return res;
}

int pt[N];
vector<ull> each[N];
int get(int pos, const ull &z) {
  int &p = pt[pos];
  while (p < sz(each[pos]) && each[pos][p] <= z) {
    p += 1;
  }
  return each[pos][p - 1] & W;
}

void solve() {
  int n, q;
  cin >> n >> q;
  vc<pii> a(q);
  vc<array<ull, 2>> pr(q);
  rep(i, q) {
    char c;
    cin >> c;
    if (c == '+') {
      a[i].fi = 1;
    } else {
      a[i].fi = -1;
    }
    ull x, y, z;
    cin >> x >> y >> z;
    z = inf - z;
    --x, --y;
    pr[i] = array<ull, 2>{z, x << 20 | y};
  }
  auto w = pr;
  sort(all(w));
  w.resize(unique(all(w)) - w.begin());
  rep(i, q) { a[i].se = lower_bound(all(w), pr[i]) - w.begin(); }
  set<int> s;
  int m = sz(w);
  rep(i, m) ww[i] = w[i];
  vi vis(m, 0);
  rep(i, n) p[i] = i;
  for (int l = 0, r = 0; l < q; l = r) {
    r = min(l + B, q);
    rep(i, l, r) vis[a[i].se] = 1;
    mp.clear();
    rep(i, n) pt[i] = 0, each[i].clear(), each[i].pb(i);
    ss.clear();
    for (auto i : s)
      if (!vis[i]) {
        auto [z, xy] = w[i];
        const ull x = xy >> 20, y = xy & W;
        const ull u = each[x].back() & W, v = each[y].back() & W;
        each[x].pb(z << 20 | v);
        each[y].pb(z << 20 | u);
      } else {
        ss.pb(i);
      }
    ans = 0;
    rep(i, n) bk[i] = each[i].back() & W, rv[bk[i]] = i;
    rep(i, n) ans += 1ll * (bk[i] + 1) * (i + 1);
    rep(i, m) if (vis[i]) {
      auto [z, xy] = w[i];
      const ull x = xy >> 20, y = xy & W;
      mp[z << 20 | x] = get(x, z << 20);
      mp[z << 20 | y] = get(y, z << 20);
    }
    rep(i, l, r) {
      if (a[i].fi == -1)
        ss.erase(lower_bound(all(ss), a[i].se));
      else
        ss.emplace(lower_bound(all(ss), a[i].se), a[i].se);
      cout << sol() << "\n";
    }
    rep(i, l, r) {
      if (a[i].fi == -1) {
        s.erase(a[i].se);
      } else {
        s.emplace(a[i].se);
      }
      vis[a[i].se] = 0;
    }
  }
  debug(clock());
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  // cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
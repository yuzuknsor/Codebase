#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define enl , writestr("\n")
#define int long long
#define endl "\n"
#define PII pair<int, int>
#define ULL unsigned long long
#define xx first
#define yy second
#define PI acos(-1)
const int P = 131; // 131,13331
const int N = 1e6 + 10;
const int M = 3e3 + 10;
const int INF = 1e18;
const int ENF = -1e18;
const int mod = 1e9 + 7; // 998244353
const int modd = 998244353;
const int mdd = 987654321;
void ClearFloat()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}
int read()
{
    int ret = 0, f = 1;
    char ch = getchar();
    while ('0' > ch || ch > '9')
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while ('0' <= ch && ch <= '9')
    {
        ret = ret * 10 + ch - '0';
        ch = getchar();
    }
    return ret * f;
}
int gcd(int a, int b)
{
    if (b)
        while ((a %= b) && (b %= a))
            ;
    return a + b;
}
int lcm(int a, int b) { return a * b / gcd(a, b); }
int lowbit(int x) { return x & (-x); }
int h[N], ne[N], e[N], idx, w[N];
int n, m, dist[N], d[N], q[N], t;
bool st[N];
vector<int> vt[N];
void add(int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}
void dijkstra()
{
    memset(dist, 0x3f, sizeof(dist));
    memset(st, false, sizeof(st));
    dist[1] = 0;
    priority_queue<PII, vector<PII>, greater<PII>> heap;
    heap.push({0, 1});
    vt[1].push_back(0);
    while (heap.size())
    {
        auto t = heap.top();
        heap.pop();
        int ver = t.yy, distance = t.xx;
        if (st[ver])
            continue;
        st[ver] = true;
        for (int i = h[ver]; ~i; i = ne[i])
        {
            int j = e[i];
            if (dist[j] > distance + w[i])
            {
                int flag = 0, fag = 0;
                vt[j].clear();
                for (auto i : vt[ver])
                {
                    if (!flag && (i + 1) % 2 == 0)
                    {
                        vt[j].push_back(i + 1);
                        flag = 1;
                    }
                    else if (!fag && (i + 1) % 2 != 0)
                    {
                        vt[j].push_back(i + 1);
                        fag = 1;
                    }
                    if (flag && fag)
                        break;
                }
                dist[j] = distance + w[i];
                heap.push({dist[j], j});
            }
            if (dist[j] == distance + w[i])
            {
                int flag = 0, fag = 0;
                for (auto i : vt[ver])
                {
                    if (!flag && (i + 1) % 2 == 0)
                    {
                        vt[j].push_back(i + 1);
                        flag = 1;
                    }
                    else if (!fag && (i + 1) % 2 != 0)
                    {
                        vt[j].push_back(i + 1);
                        fag = 1;
                    }
                    if (flag && fag)
                        break;
                }
            }
        }
    }
}
void bfs(int u)
{
    memset(st, false, sizeof(st));
    queue<int> q;
    st[u] = true;
    q.push(u);
    memset(d, -1, sizeof(d));
    d[1] = 0;
    while (!q.empty())
    {
        int t = q.front();
        q.pop();
        for (int i = h[t]; ~i; i = ne[i])
        {
            int j = e[i];
            if (!st[j] && d[j] == -1)
            {
                q.push(j);
                d[j] = d[t] + 1;
                st[j] = true;
            }
        }
    }
}
signed main()
{
    ClearFloat();
    cin >> t;
    while (t--)
    {
        memset(h, -1, sizeof h);
        idx = 0;
        cin >> n >> m;
        for (int i = 0; i <= n; i++)
            vt[i].clear();
        while (m--)
        {
            int u, v, w;
            cin >> u >> v >> w;
            add(u, v, w), add(v, u, w);
        }
        bfs(1);
        dijkstra();
        int flag = 0;
        for (auto i : vt[n])
        {
            if (i & 1)
            {
                flag = 1;
                break;
            }
        }
        if (flag)
            cout << "Little M is the winner." << endl;
        else
            cout << "Little I is the winner." << endl;
    }
}
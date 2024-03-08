#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

int n, m, q, h[N], fa[N], dep[N], sz[N], son[N], top[N], dfn[N], idx;
vector<int> G[N];

struct Edge
{
    int u, v, w;
    bool operator<(const Edge &rhs) const
    {
        return w < rhs.w;
    }
} e[N];

int find(int x)
{
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}

void dfs1(int u, int f)
{
    dep[u] = dep[f] + 1, sz[u] = 1, fa[u] = f;
    for (int v : G[u])
    {
        if (v == f)
            continue;
        dfs1(v, u);
        sz[u] += sz[v];
        if (sz[v] > sz[son[u]])
            son[u] = v;
    }
}

void dfs2(int u, int t)
{
    top[u] = t, dfn[u] = ++idx;
    if (son[u])
        dfs2(son[u], t);
    for (int v : G[u])
    {
        if (v == fa[u] || v == son[u])
            continue;
        dfs2(v, v);
    }
}

struct Node
{
    int l, r, mx;
} tr[N << 2];

void pushup(int u)
{
    tr[u].mx = max(tr[u << 1].mx, tr[u << 1 | 1].mx);
}

void build(int u, int l, int r)
{
    tr[u] = {l, r};
    if (l == r)
    {
        tr[u].mx = h[l];
        return;
    }
    int mid = l + r >> 1;
    build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
    pushup(u);
}

void modify(int u, int x, int v)
{
    if (tr[u].l == tr[u].r)
    {
        tr[u].mx = v;
        return;
    }
    int mid = tr[u].l + tr[u].r >> 1;
    if (x <= mid)
        modify(u << 1, x, v);
    else
        modify(u << 1 | 1, x, v);
    pushup(u);
}

int query(int u, int l, int r)
{
    if (tr[u].l >= l && tr[u].r <= r)
        return tr[u].mx;
    int mid = tr[u].l + tr[u].r >> 1, res = 0;
    if (l <= mid)
        res = max(res, query(u << 1, l, r));
    if (r > mid)
        res = max(res, query(u << 1 | 1, l, r));
    return res;
}

int query_path(int u, int v)
{
    int res = 0;
    while (top[u] != top[v])
    {
        if (dep[top[u]] < dep[top[v]])
            swap(u, v);
        res = max(res, query(1, dfn[top[u]], dfn[u]));
        u = fa[top[u]];
    }
    if (dep[u] > dep[v])
        swap(u, v);
    res = max(res, query(1, dfn[u], dfn[v]));
    return res;
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &h[i]);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d", &e[i].u, &e[i].v);
        e[i].w = abs(h[e[i].v] - h[e[i].u]);
    }
    sort(e + 1, e + m + 1);
    for (int i = 1; i <= n; i++)
        fa[i] = i;
    for (int i = 1; i <= m; i++)
    {
        int u = e[i].u, v = e[i].v, w = e[i].w;
        int fu = find(u), fv = find(v);
        if (fu != fv)
        {
            fa[fu] = fv;
            G[u].push_back(v), G[v].push_back(u);
        }
    }
    dfs1(1, 0), dfs2(1, 1), build(1, 1, n);
    scanf("%d", &q);
    while (q--)
    {
        int s, t, e;
        scanf("%d%d%d", &s, &t, &e);
        int d = query_path(s, t);
        if (d <= e)
            puts("YES");
        else
            puts("NO");
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;

int n, m, f[N] = {}, dep[N] = {}, unicost = 0, dep_max = 0;
bool vis[N];

int DFS(int x, int route)
{
    if(vis[x])
    {
        int dep_new = dep[x] + route;
        dep_max = dep_max > dep_new ? dep_max : dep_new;
        return 2 * route;
    }
    int cost = DFS(f[x], route + 1);

    vis[x] = true;
    dep[x] = dep[f[x]] + 1;
    
    return cost;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    memset(vis, false, sizeof vis);

    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        cin >> f[i];
        if(f[i] == -1) vis[i] = true;
    }

    while(m --)
    {
        int _new;
        cin >> _new;
        unicost += DFS(_new, 0);
        cout << unicost - dep_max << endl;
    }

    return 0;
}
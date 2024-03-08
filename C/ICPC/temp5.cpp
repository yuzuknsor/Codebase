#include <bits/stdc++.h>
#define rep(x, l, r) for(int x = l; x <= r; x++)
#define repd(x, r, l) for(int x = r; x >= l; x--)
#define clr(x, y) memset(x, y, sizeof(x))
#define all(x) x.begin(), x.end()
#define SZ(x) ((int)x.size())
#define pb push_back
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;

const int MAXN = 1e6 + 5;

vector<int> ve1[MAXN], ve2[MAXN];
int num[MAXN];

struct node2{
    int x1, x2, y;
}Q[MAXN];

struct node{
    int tot, fa[MAXN], son[MAXN][2];
    int new_node(){
        tot++;
        fa[tot] = son[tot][0] = son[tot][1] = 0;
        return tot;
    }
    int get(int x){ return son[fa[x]][1] == x;}
    
    void rotate(int x){
        int f = fa[x], gf = fa[f], lx = get(x), lf = get(f);
        
        son[f][lx] = son[x][!lx];
        if(son[x][!lx]) fa[son[x][!lx]] = f;

        son[x][!lx] = f;
        fa[f] = x;

        if(gf) son[gf][lf] = x;
        fa[x] = gf;
    }
    
    void splay(int x){
        // printf("%d\n", x);
        for(int f; f = fa[x], f; rotate(x)){
    // printf("xxxx %d %d\n", x, fa[2]);
            if(fa[f]){
                rotate(get(x) == get(f) ? f : x);
            }
        }
    }
    int pren(int x){
    // printf("xxxx %d\n", fa[2]);
        splay(x);
        int y = son[x][0];
        while(son[y][0]){
            y = son[y][0];
        }
        return y;
    }
    int nxtn(int x){
    // printf("xxxx %d\n", fa[2]);
        splay(x);
        int y = son[x][1];
        while(son[y][1]){
            // printf("%d %d\n", y, son[y][0]);
            y = son[y][1];
        }
        return y;
    }
    void link(int x, int y){
        // printf("%d %d\n", x, y);
        son[x][1] = y;
        fa[y] = x;
    }
} T;


int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    ll ans = 0;
    rep(i, 1, m){
        char ch[5];
        int x, y, z;
        scanf("%s%d%d%d", ch, &x, &y, &z);
        Q[i] = (node2){x, y, z};
        ve1[x].pb(z);
        ve1[y].pb(z);
    }
    rep(i, 1, n){
        ans += 1ll * i * i;
        ve1[i].pb(0); ve1[i].pb(INF);
        sort(all(ve1[i]));
        int len = unique(all(ve1[i])) - ve1[i].begin();
        ve1[i].resize(len);
        rep(j, 0, len - 1){
            int x = T.new_node();
            num[x] = i;
            ve2[i].pb(x);
        }
        rep(j, 0, len - 2){
            T.link(ve2[i][j], ve2[i][j + 1]);
        }
    }
    rep(i, 1, m){
        int x1 = Q[i].x1, x2 = Q[i].x2, y = Q[i].y;
        int id1 = lower_bound(all(ve1[x1]), y) - ve1[x1].begin(),
        id2 = lower_bound(all(ve1[x2]), y) - ve1[x2].begin();
    // printf("xxxx %d\n", T.fa[2]);
        int a = ve2[x1][id1], b = ve2[x2][id2];
        // printf("%d %d %d\n", i, a, b);
    // printf("xxxx %d\n", T.fa[2]);
        int pa = T.pren(a), na = T.nxtn(a),
        pb = T.pren(b), nb = T.nxtn(b);
        // printf("%d\n", i);
        // printf("%d %d %d %d\n", pa, na, pb, nb);
        // printf("%d %d %d %d\n", num[pa], num[na], num[pb], num[nb]);
        ans -= 1ll * num[pa] * num[na] + 1ll * num[pb] * num[nb];
        ans += 1ll * num[pa] * num[nb] + 1ll * num[pb] * num[na];
        printf("%lld\n", ans);
        
        T.splay(a);
        T.splay(b);
        int sa = T.son[a][1], sb = T.son[b][1];
        T.link(a, sb);
        T.link(b, sa);
    }
    return 0;
}
#include <bits/stdc++.h>
#define Tp template <typename Ty>
#define Ts template <typename Ty, typename... Ar>
#define Rg register
#define RI Rg int
#define Cn const
#define CI int
#define I inline
#define W while
#define NM 200000
#define N 100000
#define P(i, j) (((i)-1) * m + (j))
#define P_(i, j) (((j)-1) * n + (i))
using namespace std;
namespace FastIO
{
#define FS 100000
#define tc() (FA == FB && (FB = (FA = FI) + fread(FI, 1, FS, stdin), FA == FB) ? EOF : *FA++)
#define pc(x) (FC == FE && (clear(), 0), *FC++ = x)
    int OT;
    char oc, FI[FS], FO[FS], OS[FS], *FA = FI, *FB = FI, *FC = FO, *FE = FO + FS;
    I void clear() { fwrite(FO, 1, FC - FO, stdout), FC = FO; }
    Tp I void read(Ty &x)
    {
        x = 0;
        W(!isdigit(oc = tc()));
        W(x = (x << 3) + (x << 1) + (oc & 15), isdigit(oc = tc()));
    }
    Tp I void readd(Ty &x)
    {
        W(!isdigit(oc = tc()));
        x = oc & 15;
    }
    Tp I void writeln(Ty x)
    {
        W(OS[++OT] = x % 10 + 48, x /= 10);
        W(OT)
        pc(OS[OT]), --OT;
        pc('\n');
    }
}
using namespace FastIO;
int n, m, Qt, a[NM + 5], b[NM + 5], tg[NM + 5], fg[NM + 5], ct[N + 5], ans[N + 5];
struct OP
{
    int c, v, x, y;
} q[N + 5];
int Rt[2][NM + 5], RtA[NM + 5], RtB[NM + 5];
template <int SZ>
class SegmentTree
{
private:
#define LT l, mid, O[rt].S[0]
#define RT mid + 1, r, O[rt].S[1]
#define PU(x) (O[x].V = O[O[x].S[0]].V + O[O[x].S[1]].V)
#define New() (Et ? Ep[Et--] : ++Nt)
#define Del(x) (Ep[++Et] = x, O[x].S[0] = O[x].S[1] = O[x].V = 0)
    int Nt, Et, Ep[SZ];
    struct node
    {
        int V, S[2];
    } O[SZ];

public:
    void Cl()
    {
        W(Nt)
        O[Nt].V = O[Nt].S[0] = O[Nt].S[1] = 0,
        --Nt;
        Et = 0;
    }
    void U(CI x, CI v, CI l, CI r, int &rt)
    {
        if (!rt && (rt = New()), l == r)
            return (void)(O[rt].V = v);
        RI mid = l + r >> 1;
        x <= mid ? U(x, v, LT) : U(x, v, RT), PU(rt);
    }
    int Q(CI L, CI R, CI l, CI r, CI rt)
    {
        if (!rt || L <= l && r <= R)
            return O[rt].V;
        RI mid = l + r >> 1;
        return (L <= mid ? Q(L, R, LT) : 0) + (R > mid ? Q(L, R, RT) : 0);
    }
    void Mg(int &x, RI y, CI l, CI r)
    {
        if (!x || !y)
            return (void)(x |= y);
        if (l == r)
            return (void)(O[x].V |= O[y].V, Del(y));
        RI mid = l + r >> 1;
        Mg(O[x].S[0], O[y].S[0], l, mid), Mg(O[x].S[1], O[y].S[1], mid + 1, r), Del(y), PU(x);
    }
};
SegmentTree<N * 80> S[2];
SegmentTree<NM * 20> SA, SB;
struct UnionFindSet1
{
    int f[NM + 5], g[NM + 5];
    int fa(CI x) { return f[x] ? f[x] = fa(f[x]) : x; }
    I void Cl()
    {
        S[0].Cl(), S[1].Cl(), SA.Cl(), SB.Cl();
        for (RI i = 1; i <= n * m; ++i)
            f[i] = Rt[0][i] = Rt[1][i] = RtA[i] = RtB[i] = 0, g[i] = 1;
    }
    I void Mg(RI x, RI y)
    {
        if ((x = fa(x)) == (y = fa(y)))
            return;
        g[f[y] = x] += g[y];
        S[0].Mg(Rt[0][x], Rt[0][y], 1, Qt), S[1].Mg(Rt[1][x], Rt[1][y], 1, Qt), SA.Mg(RtA[x], RtA[y], 1, n * m), SB.Mg(RtB[x], RtB[y], 1, n * m);
    }
} U;
struct UnionFindSet2
{
    int f[NM + 5], l[NM + 5], r[NM + 5];
    int fa(CI x) { return f[x] ? f[x] = fa(f[x]) : x; }
    I void Cl(CI op)
    {
        for (RI i = 1; i <= n; ++i)
            for (RI j = 1; j <= m; ++j)
                f[P(i, j)] = 0;
    }
    I void Mg(RI x, RI y) { (x = fa(x)) ^ (y = fa(y)) && (f[x] = y, l[y] = l[x]); }
} A, B;
I void Init(CI x, CI y)
{
    SA.U(P(x, y), 1, 1, n * m, RtA[P(x, y)]), SB.U(P_(x, y), 1, 1, n * m, RtB[P(x, y)]), A.l[P(x, y)] = A.r[P(x, y)] = y, B.l[P(x, y)] = B.r[P(x, y)] = x;
}
I void Set(CI x, CI y)
{
    if (y ^ m && !tg[P(x, y + 1)])
    {
        if (a[P(x, y)] == 3)
            U.Mg(P(x, y), P(x, y + 1));
        if (a[P(x, y)] == 2)
            A.Mg(P(x, y), P(x, y + 1));
    }
    if (y ^ 1 && !tg[P(x, y - 1)])
    {
        if (a[P(x, y - 1)] == 3)
            U.Mg(P(x, y), P(x, y - 1));
        if (a[P(x, y - 1)] == 2)
            A.Mg(P(x, y - 1), P(x, y));
    }
    if (x ^ n && !tg[P(x + 1, y)])
    {
        if (b[P(x, y)] == 3)
            U.Mg(P(x, y), P(x + 1, y));
        if (b[P(x, y)] == 2)
            B.Mg(P(x, y), P(x + 1, y));
    }
    if (x ^ 1 && !tg[P(x - 1, y)])
    {
        if (b[P(x - 1, y)] == 3)
            U.Mg(P(x, y), P(x - 1, y));
        if (b[P(x - 1, y)] == 2)
            B.Mg(P(x - 1, y), P(x, y));
    }
}
I void Tg(CI x, CI y, CI c, CI v, CI op)
{
    if (y ^ m && !tg[P(x, y + 1)] && a[P(x, y)] == 3)
        S[c].U(v, op, 1, Qt, Rt[c][U.fa(P(x, y + 1))]);
    if (y ^ 1 && !tg[P(x, y - 1)] && a[P(x, y - 1)] == 3)
        S[c].U(v, op, 1, Qt, Rt[c][U.fa(P(x, y - 1))]);
    if (x ^ n && !tg[P(x + 1, y)] && b[P(x, y)] == 3)
        S[c].U(v, op, 1, Qt, Rt[c][U.fa(P(x + 1, y))]);
    if (x ^ 1 && !tg[P(x - 1, y)] && b[P(x - 1, y)] == 3)
        S[c].U(v, op, 1, Qt, Rt[c][U.fa(P(x - 1, y))]);
}
I void Sett(CI x, CI y)
{
    if (y ^ m && !tg[P(x, y + 1)])
    {
        if (a[P(x, y)] == 3)
            U.Mg(P(x, y), P(x, y + 1));
        if (a[P(x, y)] == 2)
            A.Mg(P(x, y), P(x, y + 1));
    }
    if (y ^ 1 && !tg[P(x, y - 1)])
    {
        if (a[P(x, y - 1)] == 3)
            U.Mg(P(x, y), P(x, y - 1));
        if (a[P(x, y - 1)] == 2)
            A.Mg(P(x, y - 1), P(x, y));
    }
    if (x ^ n && !tg[P(x + 1, y)])
    {
        if (b[P(x, y)] == 3)
            U.Mg(P(x, y), P(x + 1, y));
        if (b[P(x, y)] == 2)
            B.Mg(P(x, y), P(x + 1, y));
    }
    if (x ^ 1 && !tg[P(x - 1, y)])
    {
        if (b[P(x - 1, y)] == 3)
            U.Mg(P(x, y), P(x - 1, y));
        if (b[P(x - 1, y)] == 2)
            B.Mg(P(x - 1, y), P(x, y));
    }
    if (y ^ m && a[P(x, y)] == 3 && tg[P(x, y + 1)])
        S[fg[P(x, y + 1)]].U(tg[P(x, y + 1)], 1, 1, Qt, Rt[fg[P(x, y + 1)]][U.fa(P(x, y))]);
    if (y ^ 1 && a[P(x, y - 1)] == 3 && tg[P(x, y - 1)])
        S[fg[P(x, y - 1)]].U(tg[P(x, y - 1)], 1, 1, Qt, Rt[fg[P(x, y - 1)]][U.fa(P(x, y))]);
    if (x ^ n && b[P(x, y)] == 3 && tg[P(x + 1, y)])
        S[fg[P(x + 1, y)]].U(tg[P(x + 1, y)], 1, 1, Qt, Rt[fg[P(x + 1, y)]][U.fa(P(x, y))]);
    if (x ^ 1 && b[P(x - 1, y)] == 3 && tg[P(x - 1, y)])
        S[fg[P(x - 1, y)]].U(tg[P(x - 1, y)], 1, 1, Qt, Rt[fg[P(x - 1, y)]][U.fa(P(x, y))]);
}
int main()
{
    freopen("chess.in", "r", stdin), freopen("chess.out", "w", stdout);
    RI Tt, i, j, x, y, c, v, o, f, t = 0;
    read(Tt);
    W(Tt--)
    {
        for (read(n), read(m), read(Qt), i = 1; i <= n * m; ++i)
            tg[i] = 0;
        U.Cl(), A.Cl(0), B.Cl(1);
        for (i = 1; i <= n; ++i)
            for (j = 1; j ^ m; ++j)
                readd(a[P(i, j)]);
        for (i = 1; i ^ n; ++i)
            for (j = 1; j <= m; ++j)
                readd(b[P(i, j)]);
        for (i = 1; i <= Qt; ++i)
            ct[i] = 0;
        for (i = 1; i <= Qt; ++i)
            read(q[i].c), read(q[i].v), read(q[i].x), read(q[i].y), ++ct[q[i].v];
        for (i = 1; i <= Qt; ++i)
            ct[i] += ct[i - 1];
        for (i = Qt; i; --i)
            fg[P(q[i].x, q[i].y)] = q[i].c, tg[P(q[i].x, q[i].y)] = q[i].v = ct[q[i].v]--;
        for (i = 1; i <= n; ++i)
            for (j = 1; j <= m; ++j)
                Init(i, j);
        for (i = 1; i <= n; ++i)
            for (j = 1; j <= m; ++j)
                if (!tg[P(i, j)])
                    Set(i, j);
        for (i = 1; i <= Qt; ++i)
            Tg(q[i].x, q[i].y, q[i].c, q[i].v, 1);
        for (i = Qt; i; ans[i--] = t)
        {
            x = q[i].x, y = q[i].y, c = q[i].c, v = q[i].v, Tg(x, y, c, v, 0), tg[P(x, y)] = 0, Sett(x, y), f = U.fa(P(x, y)), t = U.g[f] - 1 + S[c ^ 1].Q(1, v, 1, Qt, Rt[c ^ 1][f]);
            if (y ^ m && a[P(x, y)] && a[P(x, y)] ^ 3)
            {
                o = a[P(x, y)] == 1 ? (tg[P(x, y + 1)] ? y : y + 1) : A.r[A.fa(P(x, y))], o ^ y && (t += o - y - SA.Q(P(x, y + 1), P(x, o), 1, n * m, RtA[f]));
                if (o ^ m && (a[P(x, y)] == 1 ? (y == o) : (a[P(x, o)] == 2)) && tg[P(x, o + 1)] && tg[P(x, o + 1)] <= v && fg[P(x, o + 1)] ^ c && !S[c ^ 1].Q(tg[P(x, o + 1)], tg[P(x, o + 1)], 1, Qt, Rt[c ^ 1][f]))
                    ++t;
            }
            if (y ^ 1 && a[P(x, y - 1)] && a[P(x, y - 1)] ^ 3)
            {
                o = a[P(x, y - 1)] == 1 ? (tg[P(x, y - 1)] ? y : y - 1) : A.l[A.fa(P(x, y))], o ^ y && (t += y - o - SA.Q(P(x, o), P(x, y - 1), 1, n * m, RtA[f]));
                if (o ^ 1 && (a[P(x, y - 1)] == 1 ? (y == o) : (a[P(x, o - 1)] == 2)) && tg[P(x, o - 1)] && tg[P(x, o - 1)] <= v && fg[P(x, o - 1)] ^ c && !S[c ^ 1].Q(tg[P(x, o - 1)], tg[P(x, o - 1)], 1, Qt, Rt[c ^ 1][f]))
                    ++t;
            }
            if (x ^ n && b[P(x, y)] && b[P(x, y)] ^ 3)
            {
                o = b[P(x, y)] == 1 ? (tg[P(x + 1, y)] ? x : x + 1) : B.r[B.fa(P(x, y))], o ^ x && (t += o - x - SB.Q(P_(x + 1, y), P_(o, y), 1, n * m, RtB[f]));
                if (o ^ n && (b[P(x, y)] == 1 ? (x == o) : (b[P(o, y)] == 2)) && tg[P(o + 1, y)] && tg[P(o + 1, y)] <= v && fg[P(o + 1, y)] ^ c && !S[c ^ 1].Q(tg[P(o + 1, y)], tg[P(o + 1, y)], 1, Qt, Rt[c ^ 1][f]))
                    ++t;
            }
            if (x ^ 1 && b[P(x - 1, y)] && b[P(x - 1, y)] ^ 3)
            {
                o = b[P(x - 1, y)] == 1 ? (tg[P(x - 1, y)] ? x : x - 1) : B.l[B.fa(P(x, y))], o ^ x && (t += x - o - SB.Q(P_(o, y), P_(x - 1, y), 1, n * m, RtB[f]));
                if (o ^ 1 && (b[P(x - 1, y)] == 1 ? (x == o) : (b[P(o - 1, y)] == 2)) && tg[P(o - 1, y)] && tg[P(o - 1, y)] <= v && fg[P(o - 1, y)] ^ c && !S[c ^ 1].Q(tg[P(o - 1, y)], tg[P(o - 1, y)], 1, Qt, Rt[c ^ 1][f]))
                    ++t;
            }
        }
        for (i = 1; i <= Qt; ++i)
            writeln(ans[i]);
    }
    return clear(), 0;
}
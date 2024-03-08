#include <bits/stdc++.h>
using namespace std;

#define PII pair<int, int>
// #define fi first
// #define se second

const int MAXN = 1e5 + 5;
vector<PII> gph[MAXN];
int dist[MAXN], rec[MAXN];
bool inq[MAXN];

void __SPFA(int n)
{
    fill(dist, dist + n + 1, INT_MAX);
    fill(inq, inq + n + 1, false);
    fill(rec, rec + n + 1, 0);

    dist[n] = 0;
    rec[n] = 0;
    queue<int> q;
    q.push(n);
    inq[n] = true;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        inq[u] = false;

        for (int i = 0; i < gph[u].size(); i++)
        {
            PII edge = gph[u][i];
            int v = edge.first, cost = edge.second;
            if (dist[u] + cost < dist[v])
            {
                dist[v] = dist[u] + cost;
                rec[v] = rec[u] + 1;
                if (!inq[v])
                {
                    q.push(v);
                    inq[v] = true;
                }
            }
        }
    }
}

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int n, m;
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
            gph[i].clear();

        while (m--)
        {
            int u, v, w;
            cin >> u >> v >> w;
            gph[u].push_back({v, w});
            gph[v].push_back({u, w});
        }

        __SPFA(n);

        cout << rec[1] << " " << rec[n] << endl;

        if (rec[1] % 2 == 0)
            cout << "Little M is the winner." << endl;
        else
            cout << "Little I is the winner." << endl;
    }
    return 0;
}
/*
请根据以下题目判断我的程序是否能够求解并给出建议：
题目描述：今天是第十届集美大学程序设计竞赛的比赛日，小M 和小I 约定好了要来看比赛。 小M 将厦门市抽象为了一个N 个点M 条边的无向带权联通图，他们要从厦门大学（1 号点）走到 集美大学（N 号点）观看比赛。 为了增加路途中的趣味性，小M 决定和小I 玩一个游戏，他们要轮流指定走到的下一条路，走到集 美大学时轮到谁指定怎么走，谁就输了，小M 先走。 当然，他们不想因为博弈错过了大家精彩的比赛，所以他们一定会确保每次选择的走的路是能够最 快到达集美大学的路。 小M 和小I 都十分的聪明，所以他们都会按照最优策略来选择如何走。 现在小M 想要知道，他是否能够获胜。 输入格式： 输入第一行是一个正整数T, 表示本题共有T(≤ 10) 组数据， 对于每组数据，第一行是两个被空格分隔的正整数N(≤ 105),M(≤ 2 × 105)。 接下来M 行，每行三个被空格分隔的正整数ui, vi,wi，表示在ui, vi(≤ N) 之间有一条边，小M 和 小I 需要花wi(≤ 109) 的时间走过。 输出格式： 每组数据输出一行，如果小M 获胜，输出”Little M is the winner.” 否则输出”Little I is the winner.”。 输入： 2 2 1 1 2 1 3 3 1 2 1 2 3 1 1 3 3 输出： Little M is the winner. Little I is the winner.（请用SPFA最短路方法求解）
*/
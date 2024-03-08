#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int INF = 1e9;
const int MAXN = 205;
int N, M, K;
int cost[MAXN][MAXN];
vector<int> path;
int minCost = INF, minIndex = -1;

void check(int index)
{
    int totalCost = 0;
    for (int i = 0; i < path.size() - 1; ++i)
    {
        int from = path[i], to = path[i + 1];
        if (cost[from][to] == INF)
            return;
        totalCost += cost[from][to];
    }
    if (totalCost < minCost)
    {
        minCost = totalCost;
        minIndex = index;
    }
}

int main()
{
    cin >> N >> M;
    fill(cost[0], cost[0] + MAXN * MAXN, INF);
    for (int i = 0; i <= N; ++i)
        cost[i][i] = 0;
    for (int i = 0; i < M; ++i)
    {
        int from, to, c;
        cin >> from >> to >> c;
        cost[from][to] = cost[to][from] = min(cost[from][to], c);
    }
    for (int k = 0; k <= N; ++k)
        for (int i = 0; i <= N; ++i)
            for (int j = 0; j <= N; ++j)
                cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
    cin >> K;
    int validCount = 0;
    for (int i = 1; i <= K; ++i)
    {
        int n;
        cin >> n;
        path.resize(n + 2);
        path[0] = path[n + 1] = 0;
        for (int j = 1; j <= n; ++j)
            cin >> path[j];
        if (unique(path.begin(), path.end()) - path.begin() == n + 2)
        {
            ++validCount;
            check(i);
        }
    }
    cout << validCount << endl;
    cout << minIndex << " " << minCost << endl;
    return 0;
}
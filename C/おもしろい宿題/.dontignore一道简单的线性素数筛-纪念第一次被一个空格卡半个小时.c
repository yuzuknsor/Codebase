// 线性素数筛解法 by Knsor
#include <stdio.h>

const int N = 1e5 + 10;

int main()
{
    int n;
    long pri[N], now = 0, count;
    int vis[N];
    for (int i = 0; i < N; i++)
    {
        vis[i] = 0;
    }
    scanf("%d", &n);
    for (int i = 2; i <= n; i++)
    {
        if (!vis[i])
        {
            pri[++now] = i;
        }
        for (int j = 1, mult = pri[j] * i; j <= now && mult <= n; j++)
        {
            vis[mult] = 1;
        }
        if(pri[now] - pri[now - 1] == 2)
        {
            count++;
        }
    }

    printf("%d\n", count - 1);
    return 0;
}

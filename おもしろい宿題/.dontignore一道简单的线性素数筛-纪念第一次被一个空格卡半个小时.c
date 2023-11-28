// 线性素数筛解法 by Knsor
#include <stdio.h>

const int N = 1e4 + 10;

int main()
{
    int m, n;
    long long pri[N >> 1], now = 0;
    int vis[N];
    scanf("%lld", &n);
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
    }

    int count = 0;
    long long sum = 0;
    for (int i = 1; i <= now; ++i)
    {
        if(pri[i] >= m)
        {
            count++;
            sum += pri[i];
        }
    }
    printf("%d %lld", count, sum);
    return 0;
}

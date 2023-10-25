// 线性素数筛解法 by Knsor
#include <stdio.h>

const int N = 1e4 + 10;

int main()
{
    long long int n, pri[N >> 1], now = 0, sum = 0;
    int vis[N];
    scanf("%lld", &n);
    for (int i = 2; i <= n; i++)
    {
        if (sum + i > n)
            break;
        if (!vis[i])
        {
            sum += i;
            pri[++now] = i;
        }
        for (int j = 1; j <= now && pri[j] * i <= n; j++)
        {
            vis[pri[j] * i] = 1;
            if (i % pri[j] == 0)
                break;
        }
    }

    printf("2");
    for (int i = 2; i <= now; ++i)
        printf(" %lld", pri[i]);
    printf("\ncount = %lld", now);
    return 0;
}

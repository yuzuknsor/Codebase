#include <bits/stdc++.h>
using namespace std;
const int N = 43210;

struct PERIOD
{
    int h1, m1, s1, h2, m2, s2;
} a[43210];

bool cmp(PERIOD x, PERIOD y)
{
    if (x.h1 != y.h1)
        return x.h1 < y.h1;
    if (x.m1 != y.m1)
        return x.m1 < y.m1;
    return x.s1 < y.s1;
}

int main()
{
    // 和 scanf / printf 不兼容
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        scanf("%d:%d:%d - %d:%d:%d", &a[i].h1, &a[i].m1, &a[i].s1, &a[i].h2, &a[i].m2, &a[i].s2);
    sort(a + 1, a + n + 1, cmp);

    // 每个PERIOD的两端点时间必须是严格单调的，即排序后能存在耦合不存在重叠

    if (a[1].h1 != 0 || a[1].m1 != 0 || a[1].s1 != 0) // 检查0点至第一个端点时间
        printf("00:00:00 - %02d:%02d:%02d\n", a[1].h1, a[1].m1, a[1].s1);

    for (int i = 2; i <= n; i++)
        if (a[i].h1 != a[i - 1].h2 || a[i].m1 != a[i - 1].m2 || a[i].s1 != a[i - 1].s2)
            printf("%02d:%02d:%02d - %02d:%02d:%02d\n", a[i - 1].h2, a[i - 1].m2, a[i - 1].s2, a[i].h1, a[i].m1, a[i].s1);

    if (a[n].h2 != 23 || a[n].m2 != 59 || a[n].s2 != 59) // 检查最后一个端点至23:59:59
        printf("%02d:%02d:%02d - 23:59:59\n", a[n].h2, a[n].m2, a[n].s2);

    return 0;
}
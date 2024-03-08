#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
typedef long long int LLD;
typedef pair<int, int> PII;

const int MAXN = 2005;
PII p[MAXN];

LLD judge(PII a, PII b, PII c)
{
    return 1LL * (a.x - c.x) * (b.y - c.y) - 1LL * (a.y - c.y) * (b.x - c.x);
}

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> p[i].x >> p[i].y;
    }

    LLD ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            int left = 0, right = 0;
            for (int k = 1; k <= n; k++)
            {
                if (k == i || k == j)
                    continue;
                if (judge(p[i], p[j], p[k]) > 0)
                {
                    left++;
                    // cout << endl << left;
                }
                else
                {
                    right++;
                    // cout << " " << right << endl;
                }
                    right++;
            }
            if (left == right)
                ans++;
        }
    }

    cout << ans << "\n";

    return 0;
}
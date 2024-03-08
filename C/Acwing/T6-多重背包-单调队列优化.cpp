#include <bits/stdc++.h>
using namespace std;

const int N = 2e4 + 10;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, cap, val[N] = { }, pq[N] = { }, dp[N] = { };
    cin >> n >> cap;
    while (n--)
    {
        memcpy(val, dp, sizeof val);
        int weight, value, number;
        cin >> weight >> value >> number;
        for (int r = 0; r < weight; ++r)
        {
            int head = 0, tail = -1;
            for (int j = r; j <= cap; j += weight)
            {
                while(head <= tail && j - pq[head] > number * weight)
                    head++;
                while(head <= tail && val[pq[tail]] + (j - pq[tail]) / weight * value <= val[j])
                    --tail;
                pq[++tail] = j;
                dp[j] = val[pq[head]] + (j - pq[head]) / weight * value;
            }
        }
    }

    cout << dp[cap];
}
//4 5 1 2 3 2 4 1 3 4 3 4 5 2
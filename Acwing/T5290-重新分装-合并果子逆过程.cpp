#define _CRT_SECURE_NO_WARNINGS
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include <bits/stdc++.h>
// #define endl "\n"
using namespace std;
void _clear_float_()
{
    ios_base::sync_with_stdio(false);
    // cin.tie(nullptr);
    cout.tie(nullptr);
}
typedef unsigned long long uLL;
const int N = 1e5 + 10;
priority_queue<uLL, vector<uLL>, greater<uLL>> heap;
template <typename T>
inline void read(T &x)
{
    x = 0;
    char c = getchar();
    bool flag = false;
    while (!isdigit(c))
    {
        if (c == '-')
            flag = true;
        c = getchar();
    }
    while (isdigit(c))
    {
        x = (x << 1) + (x << 3) + (c ^ 48);
        c = getchar();
    }

    if (c == '.')
    {
        double base = 1;
        c = getchar();
        while (isdigit(c))
        {
            base *= 0.1;
            x += base * (c ^ 48);
            c = getchar();
        }
    }
    if (flag)
        x = -x;
}

int main()
{
    _clear_float_();
    int n;
    read(n);
    if (n % 2 == 0)
        heap.push(0);
    for (int i = 0; i < n; i++)
    {
        int a;
        read(a);
        heap.push(a);
    }
    uLL ans = 0;
    while (heap.size() > 1)
    {
        uLL sum = 0;
        for (int i = 0; i < 3; ++i)
        {
            sum += heap.top();
            heap.pop();
        }
        ans += sum;
        heap.push(sum);
    }
    cout << ans;
}
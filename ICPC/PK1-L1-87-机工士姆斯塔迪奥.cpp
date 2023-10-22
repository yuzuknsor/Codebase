#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;

int row, col, n;
bool vis_col[N], vis_row[N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    memset(vis_col, false, sizeof vis_col);
    memset(vis_row, false, sizeof vis_row);

    cin >> row >> col >> n;

    while (n--)
    {
        bool choose;
        int tmp;
        cin >> choose >> tmp;
        if (choose && !vis_col[tmp])
            col--, vis_col[tmp] = true;
        if (!choose && !vis_row[tmp])
            row--, vis_row[tmp] = true;
    }

    cout << row * col;

    return 0;
}
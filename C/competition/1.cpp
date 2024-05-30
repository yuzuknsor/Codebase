#include <bits/stdc++.h>
using namespace std;
#define _sort std::sort
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; ++ i)
    {
        int a[33];
        memset(a, 0, sizeof a);
        long int m;
        cin >> m;
        for (int k = 1; m > 0, k <= 32; m >>= 1, k++)
        {
            a[k] = m & 1;
        }
        for(int j = 32; j >= 1; -- j)
        {
            cout << a[j];
        }
        cout << endl;
    }
}
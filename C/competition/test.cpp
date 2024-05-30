#include <bits/stdc++.h>
using namespace std;
#define _sort std::sort
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int a[14];
    memset(a, 0, sizeof a);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        bool flag = false;
        int m;
        cin >> m;
        for (int j = 1; j <= 5; ++j)
        {
            char c;
            cin >> c;
            if (c == 'A')
                ++a[1];
            else if (c == 't')
                ++a[10];
            else if (c == 'j')
                ++a[11];
            else if (c == 'q')
                ++a[12];
            else if (c == 'k')
                ++a[13];
            else if (isdigit(c))
                ++a[int(c)];
            else
            {
                flag = true;
            }
        }
        for (int j = 1; j <= m * 2; ++j)
        {
            char c;
            cin >> c;
            if (c == 'A')
                ++a[1];
            else if (c == 't')
                ++a[10];
            else if (c == 'j')
                ++a[11];
            else if (c == 'q')
                ++a[12];
            else if (c == 'k')
                ++a[13];
            else if (isdigit(c))
                ++a[int(c)];
            else
            {
                flag = true;
            }
        }
        for (int j = 1; j <= 13 && !flag; ++j)
        {
            if (a[j] > 4)
            {
                flag = true;
                break;
            }
        }
        if (flag)
        {
            cout << "Error" << endl;
        }
        else
        {
            cout << "Correct" << endl;
        }
    }
    return 0;
}
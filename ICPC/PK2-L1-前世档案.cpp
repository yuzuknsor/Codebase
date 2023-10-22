#include <bits/stdc++.h>
using namespace std;
int n, m;

long long int pow2(int p)
{
    int ans = 1;
    for(int i = 0; i <p; ++i)
        ans *= 2;
    return ans;
}

int main()
{
    cin >> n >> m;

    long long int _pow = pow2(n);

    while (m--)
    {
        string s;
        getline(cin, s);
        int len = s.length(), p = n;
        long long int cmp = 0;
        for (int i = 0; i < len; ++i )
        {
            if (s[i] == 'y')
                cmp += pow2(--p);
            else
                p--;
        }
        cout << _pow - cmp << endl;
    }

    return 0;
}

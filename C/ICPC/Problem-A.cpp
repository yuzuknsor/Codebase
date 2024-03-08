#include <bits/stdc++.h>
using namespace std;

int trans(char c)
{
    if (c >= '0' && c <= '9')
        return c - '0';
    if (c >= 'A' && c <= 'F')
        return c - 'A' + 10;
    return 0;
}

int solve(string A, string B, string S)
{
    for (int X = 16; X >= 2; X--)
    {
        int a = 0, b = 0, s = 0;
        for (char c : A)
            a = a * X + trans(c);
        for (char c : B)
            b = b * X + trans(c);
        for (char c : S)
            s = s * X + trans(c);
        if (a + b == s)
            return X;
    }
    return 0;
}

int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);

    int n;
    cin >> n;
    while (n--)
    {
        string A, B, S;
        cin >> A >> B >> S;
        cout << solve(A, B, S) << endl;
    }
    return 0;
}
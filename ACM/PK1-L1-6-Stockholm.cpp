#include <bits/stdc++.h>
using namespace std;

int num(char c) { return c - '0'; }

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string a, a_hdd, b, b_hdd;

    getline(cin, a);
    int la = a.length();
    for (int i = 1; i < la; i++)
        if (num(a[i]) % 2 == num(a[i - 1]) % 2)
            a_hdd.push_back(a[i] > a[i - 1] ? a[i] : a[i - 1]);
    
    /*
    getline(cin, b);
    int lb = b.length();
    for (int i = 1; i < lb; i++)
        if (num(b[i]) % 2 == num(b[i - 1]) % 2)
            b_hdd.push_back(b[i] > b[i - 1] ? b[i] : b[i - 1]);
    */
    getline(cin, b);
    for (auto iter = b.begin() + 1; iter != b.end(); iter++)
        if (num(*iter) % 2 == num(*(iter - 1)) % 2)
            b_hdd.push_back(*iter > *(iter - 1) ? *iter : *(iter - 1));
    

    (a_hdd == b_hdd) ? (cout << a_hdd << endl) : (cout << a_hdd << endl << b_hdd << endl);
}

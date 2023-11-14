#include <bits/stdc++.h>
using namespace std;

int num(char c) { return c - '0'; }

int main()
{
    string a, a_hdd, b, b_hdd;

    getline(cin, a);
    int la = a.length();
    for (int i = 1; i < la; i++)
        if (num(a[i]) % 2 == num(a[i - 1]) % 2)
            a_hdd.push_back(a[i] > a[i - 1] ? a[i] : a[i - 1]);
    
    getline(cin, b);
    for (auto iter = b.begin() + 1; iter != b.end(); iter++) // 尝试使用auto
        if (num(*iter) % 2 == num(*(iter - 1)) % 2)
            b_hdd.push_back(*iter > *(iter - 1) ? *iter : *(iter - 1));
    

    (a_hdd == b_hdd) ? (cout << a_hdd << endl) : (cout << a_hdd << endl << b_hdd << endl);
}

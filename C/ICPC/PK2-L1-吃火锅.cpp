#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string line;
    int total = 0, count = 0, first = -1;
    while (getline(cin, line) && line != ".")
    {
        ++total;
        if (line.find("chi1 huo3 guo1") != string::npos)
        {
            ++count;
            if (first == -1)
            {
                first = total;
            }
        }
    }

    cout << total << endl;
    if (count > 0)
    {
        cout << first << " " << count << endl;
    }
    else
    {
        cout << "-_-#" << endl;
    }

    return 0;
}